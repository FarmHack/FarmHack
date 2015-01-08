<?php
/**
 * Drupal Developer Plugins
 *
 * drupalorg, drupalproject
 */

/*
 * Allows for a link like [[drupalorg:12345]] to be expanded to
 * a link to drupal.org/node/12345
 */
$freelinking['drupalorg'] = array(
  'indicator' => '/^d(rupal)?o(rg)?$/',
  'callback' => 'freelinking_drupalorg_callback',
  'tip' => t('Link to a drupal.org node.'),
);

/**
 * Builds a link to a node in Drupal.org.
 *
 * @return
 *   array with link details.
 */
function freelinking_drupalorg_callback($target, $plugin) { // resolve nid to a node title
  if (!is_numeric($target['dest'])) {
    return array(
      'failover' => 'error',
      'message' => t('Invalid Node ID !nid', array('!nid' => $target['dest'])),
    );
  }

  $url = 'http://drupal.org/node/' . $target['dest'];
  if (!$target['text'] && variable_get('freelinking_drupalorg_http_request', TRUE)) {
    $result = drupal_http_request($url, array('headers' => array()));
    $found_title = preg_match('/<h1.*>(.*)<\/h1>/', $result->data, $matches);

    if ($found_title) { // regex worked to scarf title of page
      $replacement = array(
        'Drupal.org: "' . check_plain($matches[1]) . '"',
         check_url($url),
         array ('attributes' => array()),
      );
    }
  }
  elseif ($target['text']) {
    $replacement = array($target['text'], $url);
  }

  if (empty($replacement)) {
    $replacement = array(
      'Drupal.org Node: ' . $target['dest'],
      $url,
    );
  }

  return $replacement;
}

/**
 * Settings form for drupalorg plugin
 *
 * @return
 *   array form settings.
 */
function freelinking_drupalorg_settings() {
  $form['freelinking_drupalorg_http_request'] = array(
    '#type' => 'checkbox',
    '#title' => t('Get node title'),
    '#default_value' => variable_get('freelinking_drupalorg_http_request', TRUE),
    '#description' => t('Untick to show nid instead of node title.'),
  );
  return $form;
}

/*
 * Allows for a link like [[drupalproject:Freelinking]] to be expanded to
 * drupal.org/project/freelinking
 */
$freelinking['drupalproject'] = array(
  'indicator' => '/^d(rupal)?project/',
  'translate' => array(' ' => '_'),
  'replacement' => 'http://drupal.org/project/%1',
  'tip' => t('Link to a project on drupal.org by name.'),
);
