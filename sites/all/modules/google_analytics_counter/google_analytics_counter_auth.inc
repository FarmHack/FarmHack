<?php

/**
 * @file
 * Provides the GAFeed object type and associated methods.
 *
 * Most of the Google Analytics authentication process is taken over from http://drupal.org/project/google_analytics_reports because all we need here is its Google Analytics API submodule but it is not possible to use that separately. Moreover, Google Analytics Reports requires also module Chart which is completely unrelated to this module.
 */

/* Number of seconds in an hour. */
define('GOOGLE_ANALYTICS_COUNTER_HOUR', 60 * 60);

/* Number of seconds in a day. */
define('GOOGLE_ANALYTICS_COUNTER_DAY', GOOGLE_ANALYTICS_COUNTER_HOUR * 24);

/* Number of seconds in a week. */
define('GOOGLE_ANALYTICS_COUNTER_WEEK', GOOGLE_ANALYTICS_COUNTER_DAY * 7);

/**
 * Instantiate a new GAFeed object.
 */
function google_analytics_counter_new_gafeed() {
  module_load_include('inc', 'google_analytics_counter', 'GAFeed.lib');
  $key = variable_get('google_analytics_counter_consumer_key', 'anonymous');
  $secret = variable_get('google_analytics_counter_consumer_secret', 'anonymous');
  $oauth_token = variable_get('google_analytics_counter_oauth_token', NULL);
  $oauth_token_secret = variable_get('google_analytics_counter_oauth_token_secret', NULL);
  return new GAFeed($key, $secret, $oauth_token, $oauth_token_secret);
}

/**
 * Menu callback - admin form for OAuth and other settings.
 */
function google_analytics_counter_auth_admin() {

  $form = array();
  $account = google_analytics_counter_new_gafeed();
  //dpm($account);

  if ($account->isAuthenticated()) {
    $webprops = $account->queryWebProperties()->results->items;
    $profiles = $account->queryProfiles()->results->items;
    $options = array();
    $profile_id = variable_get('google_analytics_counter_profile_id', 0);
    $set_default = FALSE;

    /* Add optgroups for each web property */
    foreach ($profiles as $profile) {
      $webprop = NULL;
      foreach ($webprops as $webprop_value) {
        if ($webprop_value->id == $profile->webPropertyId) {
          $webprop = $webprop_value;
          break;
        }
      }

      $options[$webprop->name][$profile->id] = theme('google_analytics_counter_profile_label', array('profile' => $profile));
      /* Rough attempt to see if the current site is in the account list */
      if (empty($profile_id) && (parse_url($webprop->websiteUrl, PHP_URL_PATH) == $_SERVER['HTTP_HOST'])) {
        $profile_id = $profile->id;
        $set_default = TRUE;
      }
    }

    /* If no profile ID is set yet, set the first profile in the list */
    if (empty($profile_id)) {
      $profile_id = key($options[key($options)]);
      $set_default = TRUE;
    }

    if ($set_default) {
      variable_set('google_analytics_counter_profile_id', $profile_id);
    }

    /* Load current profile object */
    foreach ($profiles as $profile) {
      if ($profile->id == $profile_id) {
        $current_profile = $profile;
        variable_set('google_analytics_counter_default_page', '/' . @$current_profile->defaultPage);
        break;
      }
    }
    //dpm($current_profile);

    $form['ga'] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => 1,
    );
    $form['ga']['google_analytics_counter_profile_id'] = array(
      '#type' => 'select',
      '#title' => t('Reports profile'),
      '#options' => $options,
      '#default_value' => $profile_id,
      '#description' => t("Choose your Google Analytics profile. The currently active profile is: %profile", array('%profile' => theme('google_analytics_counter_profile_label', array('profile' => $current_profile)))),
      '#required' => TRUE,
    );
    $form['ga']['settings_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save settings'),
    );
    $form['revoke'] = array(
      '#type' => 'fieldset',
      '#title' => t('Revoke access and logout'),
      '#description' => t('Revoke your access token to Google Analytics. This action will log you out of your Google Analytics account and stop all reports from displaying on your site.'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => 5,
    );
    $form['revoke']['revoke_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Revoke access token'),
    );
  }
  /* Else, there are no profiles, and we should just leave it at setup */
  else {
    $form['setup'] = array(
      '#type' => 'fieldset',
      '#title' => t('Initial setup'),
      '#description' => t("When you submit this form, you will be redirected to Google for authentication. Login with the account that has credentials to the Google Analytics profile you'd like to use."),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['setup']['google_analytics_counter_hd'] = array(
      '#type' => 'textfield',
      '#title' => t('Google Apps for Business Domain (optional)'),
      '#description' => t('Provide the domain name (example.com) if your domain is registered with Google Apps for Business. Otherwise, leave blank.'),
      '#default_value' => variable_get('google_analytics_counter_hd', ''),
    );
    $form['setup']['setup_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Start setup and authorize account'),
    );
  }
  return $form;
}

/**
 * Submit handler.  Steps through the OAuth process, revokes tokens, saves profiles.
 */
function google_analytics_counter_auth_admin_submit($form, &$form_state) {
  $op = isset($form_state['values']['op']) ? $form_state['values']['op'] : '';
  cache_clear_all('GAFeed', 'cache', '*');
  switch ($op) {
    case t('Start setup and authorize account'):
        variable_set('google_analytics_counter_hd', $form_state['values']['google_analytics_counter_hd']);
        /* Anonymous keys are a Google default */
        $key = variable_get('google_analytics_counter_consumer_key', 'anonymous');
        $secret = variable_get('google_analytics_counter_consumer_secret', 'anonymous');
        module_load_include('inc', 'google_analytics_counter', 'GAFeed.lib');
        $GAFeed = new GAFeed($key, $secret);
        /* Step #1 of OAuth */
        $token = $GAFeed->getRequestToken();
        $_SESSION['google_analytics_counter_oauth']['token'] = $token;
        $_SESSION['google_analytics_counter_oauth']['destination'] = $_GET['q'];

        /* Step #2 of OAuth */
        $GAFeed->obtainAuthorization($token);
        //dpm($GAFeed);
      break;
    case t('Save settings'):
        variable_set('google_analytics_counter_profile_id', $form_state['values']['google_analytics_counter_profile_id']);
        drupal_set_message(t('Settings have been saved successfully.'));
      break;
    case t('Revoke access token'):
        google_analytics_counter_revoke();
        drupal_set_message(t('Access token has been successfully revoked.'));
      break;
  }
}

/**
 * Page callback - Provided for Google to call back during the OAuth process.
 */
function google_analytics_counter_oauth_callback() {
  $key = variable_get('google_analytics_counter_consumer_key', 'anonymous');
  $secret = variable_get('google_analytics_counter_consumer_secret', 'anonymous');

  $session_data = $_SESSION['google_analytics_counter_oauth'];
  unset($_SESSION['google_analytics_counter_oauth']);

  $token = $session_data['token'];
  if (!is_array($token) || !$key || !$secret) {
    drupal_set_message(t('Invalid Google Analytics OAuth request'), 'error');
    return ' ';
  }

  if ($token['oauth_token'] != $_GET['oauth_token']) {
    drupal_set_message(t('Invalid OAuth token.'), 'error');
    return ' ';
  }

  module_load_include('inc', 'google_analytics_counter', 'GAFeed.lib');
  $GAFeed = new GAFeed($key, $secret, $token['oauth_token'], $token['oauth_token_secret']);

  /* Google required the verifier */
  $GAFeed->setVerifier($_GET['oauth_verifier']);
  $response = $GAFeed->getAccessToken();

  variable_set('google_analytics_counter_oauth_token', $response['oauth_token']);
  variable_set('google_analytics_counter_oauth_token_secret', $response['oauth_token_secret']);

  drupal_goto('admin/config/system/google_analytics_counter/authentication');
}


/**
 * Implements hook_theme().
 */
function google_analytics_counter_theme() {
  return array(
    'google_analytics_counter_profile_label' => array(
      'arguments' => array('profile' => NULL),
    ),
  );
}


/**
 * Theme the full string label of profiles.
 * @return Themed string label.
 */
function theme_google_analytics_counter_profile_label($variables) {
  return $variables['profile']->name . ' (' . $variables['profile']->id . ')';
}


/**
 * Programatically revoke token.
 */
function google_analytics_counter_revoke() {
  $GAFeed = google_analytics_counter_new_gafeed();
  $GAFeed->revokeToken();
  variable_del('google_analytics_counter_profile_id');
  variable_del('google_analytics_counter_consumer_key');
  variable_del('google_analytics_counter_consumer_secret');
  variable_del('google_analytics_counter_oauth_token');
  variable_del('google_analytics_counter_oauth_token_secret');
}
