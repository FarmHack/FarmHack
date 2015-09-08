<?php

/**
 * @file
 * Provides the GAFeed object type and associated methods.
 *
 * Most of the Google Analytics authentication process is taken over from http://drupal.org/project/google_analytics_reports because all we need here is its Google Analytics API submodule but it is not possible to use that separately. Moreover, Google Analytics Reports requires also module Chart which is completely unrelated to this module.
 */

/* Seconds in an hour. */
define('GOOGLE_ANALYTICS_COUNTER_HOUR', 60 * 60);

/* Seconds in a day. */
define('GOOGLE_ANALYTICS_COUNTER_DAY', GOOGLE_ANALYTICS_COUNTER_HOUR * 24);

/* Seconds in a week. */
define('GOOGLE_ANALYTICS_COUNTER_WEEK', GOOGLE_ANALYTICS_COUNTER_DAY * 7);

/**
 * Instantiate a new GoogleAnalyticsCounterFeed object.
 *
 * @return object
 *   GoogleAnalyticsCounterFeed object to authorize access and request data
 *   from the Google Analytics Core Reporting API.
 */
function google_analytics_counter_new_gafeed() {
  module_load_include('inc', 'google_analytics_counter', 'google_analytics_counter_oauth2.lib');
  if (variable_get('google_analytics_counter_access_token', NULL) && time() < variable_get('google_analytics_counter_expires_at', NULL)) {
    // If the access token is still valid, return an authenticated GAFeed.
    return new GoogleAnalyticsCounterFeed(variable_get('google_analytics_counter_access_token', NULL));
  }
  elseif (variable_get('google_analytics_counter_refresh_token', NULL)) {
    // If the site has an access token and refresh token, but the access
    // token has expired, authenticate the user with the refresh token.
    $client_id = variable_get('google_analytics_counter_client_id', NULL);
    $client_secret = variable_get('google_analytics_counter_client_secret', NULL);
    $refresh_token = variable_get('google_analytics_counter_refresh_token', NULL);

    try {
      $gafeed = new GoogleAnalyticsCounterFeed();
      $gafeed->refreshToken($client_id, $client_secret, $refresh_token);

      variable_set("google_analytics_counter_access_token", $gafeed->access_token);
      variable_set("google_analytics_counter_expires_at", $gafeed->expires_at);
      return $gafeed;
    }
    catch (Exception $e) {
      drupal_set_message(t("There was an authentication error. Message: " . $e->getMessage()), 'error', FALSE);
      return NULL;
    }
  }
  elseif (isset($_GET['code'])) {
    // If there is no access token or refresh token and client is returned
    // to the config page with an access code, complete the authentication.
    $client_id = variable_get('google_analytics_counter_client_id', NULL);
    $client_secret = variable_get('google_analytics_counter_client_secret', NULL);
    $redirect_uri = variable_get('google_analytics_counter_redirect_uri', NULL);

    try {
      $gafeed = new GoogleAnalyticsCounterFeed();
      $gafeed->finishAuthentication($client_id, $client_secret, $redirect_uri);

      variable_set('google_analytics_counter_access_token', $gafeed->access_token);
      variable_set('google_analytics_counter_expires_at', $gafeed->expires_at);
      variable_set('google_analytics_counter_refresh_token', $gafeed->refresh_token);
      variable_del('google_analytics_counter_redirect_uri');

      drupal_set_message(t("You have been successfully authenticated."), 'status', FALSE);
      drupal_goto($redirect_uri);
    }
    catch (Exception $e) {
      drupal_set_message(t("There was an authentication error. Message: " . $e->getMessage()), 'error', FALSE);
      return NULL;
    }
  }
  else {
    return NULL;
  }
}

/**
 * Menu callback - admin form for OAuth and other settings.
 */
function google_analytics_counter_auth_admin() {

  $form = array();
  $account = google_analytics_counter_new_gafeed();

  if ($account && $account->isAuthenticated()) {
    $webprops = $account->queryWebProperties()->results->items;
    $profiles = $account->queryProfiles()->results->items;
    $options = array();
    $profile_id = variable_get('google_analytics_counter_profile_id', 0);
    $set_default = FALSE;

    // Add optgroups for each web property.
    if (!empty($profiles)) {
      foreach ($profiles as $profile) {
        $webprop = NULL;
        foreach ($webprops as $webprop_value) {
          if ($webprop_value->id == $profile->webPropertyId) {
            $webprop = $webprop_value;
            break;
          }
        }
        $options[$webprop->name][$profile->id] = theme('google_analytics_counter_profile_label', array('profile' => $profile));
        // Rough attempt to see if the current site is in the account list.
        if (empty($profile_id) && (parse_url($webprop->websiteUrl, PHP_URL_PATH) == $_SERVER['HTTP_HOST'])) {
          $profile_id = $profile->id;
          $set_default = TRUE;
        }
      }
    }

    // If no profile ID is set yet, set the first profile in the list.
    if (empty($profile_id)) {
      $profile_id = key($options[key($options)]);
      $set_default = TRUE;
    }

    if ($set_default) {
      variable_set('google_analytics_counter_profile_id', $profile_id);
    }

    // Load current profile object.
    foreach ($profiles as $profile) {
      if ($profile->id == $profile_id) {
        $current_profile = $profile;
        variable_set('google_analytics_counter_default_page', isset($current_profile->defaultPage) ? '/' . $current_profile->defaultPage : '/');
        break;
      }
    }

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
    if (!empty($options) || $options[0]) {
      $form['ga']['google_analytics_counter_profile_id']['#required'] = TRUE;
    }
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
  // Else, there are no profiles, and we should just leave it at setup.
  else {
    $form['setup'] = array(
      '#type' => 'fieldset',
      '#title' => t('Initial setup'),
      '#description' => t("When you submit this form, you will be redirected to Google for authentication. Login with the account that has credentials to the Google Analytics profile you'd like to use."),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['setup']['client_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Client ID'),
      '#default_value' => variable_get('google_analytics_counter_client_id', ''),
      '#size' => 30,
      '#description' => t('Client ID created for the app in the access tab of the !google_link', array(
        '!google_link' => l(t('Google API Console'), 'http://code.google.com/apis/console', array(
          'attributes' => array(
            'target' => '_blank',
          ),
        )),
      )),
      '#weight' => -9,
    );
    $form['setup']['client_secret'] = array(
      '#type' => 'textfield',
      '#title' => t('Client Secret'),
      '#default_value' => variable_get('google_analytics_counter_client_secret', ''),
      '#size' => 30,
      '#description' => t('Client Secret created for the app in the Google API Console'),
      '#weight' => -8,
    );
    $redirect_uri = variable_get('google_analytics_counter_redirect_uri', GoogleAnalyticsCounterFeed::currentUrl());
    $form['setup']['redirect_host'] = array(
      '#type' => 'textfield',
      '#title' => t('Redirect host'),
      '#default_value' => variable_get('google_analytics_counter_redirect_host', ''),
      '#size' => 30,
      '#description' => t('Use to override the host for the callback uri (necessary on some servers, e.g. when using SSL and Varnish). Include schema and host, but not uri path. Example: http://example.com. Current redirect URI is %redirect_uri. Leave blank to use default (blank will work for most cases).',
         array(
           '%redirect_uri' => $redirect_uri,
         )
      ),
      '#weight' => -7,
    );
    $form['setup']['setup_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Start setup and authorize account'),
    );
  }
  return $form;
}

/**
 * Submit handler.
 *
 * Steps through the OAuth process, revokes tokens and saves profiles.
 */
function google_analytics_counter_auth_admin_submit($form, &$form_state) {
  $op = isset($form_state['values']['op']) ? $form_state['values']['op'] : '';
  cache_clear_all('GoogleAnalyticsCounterFeed', 'cache', '*');
  switch ($op) {
    case t('Start setup and authorize account'):
      $client_id = $form_state['values']['client_id'];
      $client_secret = $form_state['values']['client_secret'];
      $redirect_uri = GoogleAnalyticsCounterFeed::currentUrl();
      if (!empty($form_state['values']['redirect_host'])) {
        variable_set('google_analytics_counter_redirect_host', $form_state['values']['redirect_host']);
        $redirect_uri = $form_state['values']['redirect_host'] . $_SERVER['REQUEST_URI'];
      }
      variable_set('google_analytics_counter_client_id', $client_id);
      variable_set('google_analytics_counter_client_secret', $client_secret);
      variable_set('google_analytics_counter_redirect_uri', $redirect_uri);

      $gafeed = new GoogleAnalyticsCounterFeed();
      $gafeed->beginAuthentication($client_id, $redirect_uri);
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
 */
function theme_google_analytics_counter_profile_label($variables) {
  return $variables['profile']->name . ' (' . $variables['profile']->id . ')';
}

/**
 * Programatically revoke token.
 */
function google_analytics_counter_revoke() {
  $gafeed = google_analytics_counter_new_gafeed();
  $gafeed->revokeToken();

  // Delete module variables.
  $query = db_select('variable', 'v')
    ->fields('v', array('name'))
    ->condition('name', db_like('google_analytics_counter') . '%', 'LIKE')
    ->execute();
  while ($variable = $query->fetchAssoc()) {
    variable_del($variable['name']);
  }
}
