<?php
/**
 * Nodetitle plugin for Freelinking
 *
 * @file
 * Allows for a link like [[nodetitle:Freelinking filter]] to be expanded to
 * a link to the node titled "Freelinking filter" or a link to create the node.
 */

$freelinking['nodetitle'] = array(
  'indicator' => '/nt$|nodetitle|title/A',
  'callback' => 'freelinking_nodetitle_callback',
  'tip' => t('Link to a local node by title'),
  'run on view' => TRUE,
);

/**
 * Replacement callback for nodetitle plugin
 *
 * Resolve $target into a link to the node or display failure.
 *
 * @return
 *   an array with node properties to build the link.
 */
function freelinking_nodetitle_callback($target, $plugin) {
  $node = freelinking_nodetitle_nid_from_title($target);
  // if no node was found, identify proceed with configured failover
  if (!$node) {
    $target['target'] = check_plain($target['target']);
    $target['dest'] = check_plain($target['dest']);
    return _freelinking_nodetitle_failure($target);
  }
  else {
    // construct values for link, use $text if it exists.
    if (isset($target['text'])) {
      $title = $target['text'];
    }
    elseif (isset($node->title)) {
      $title = $node->title;
    }
    else {
      $title = 'nodetitle';
    }
    $title = check_plain($title);
  }

  $node_cache_title = &drupal_static('freelinking_nodetitle_nid_from_title', array());
  $key = array_search($title, $node_cache_title['title']);
  $nodenid = isset($node->nid) ? $node->nid : $node_cache_title['nid'][$key];

  if (!$target['tooltip']) {
    $target['tooltip'] = freelinking_internal_tooltip('node', $nodenid);
  }
  $language = isset($node->language) ? $node->language : LANGUAGE_NONE;
  // return link structure
  return array($title, 'node/' . $nodenid, array(
      'attributes' => array('title' => $target['tooltip']),
      'language' => $language,
  ));
}

/**
 * Nodetitle Settings Callback
 */
function freelinking_nodetitle_settings() {
  // Restrict nodetitle plugin to search specified content type
  $form['freelinking_nodetitle_searchcontenttype'] = array(
    '#title' => t('Restrict freelinks to this content type'),
    '#type' => 'select',
    '#options' => array_merge(array('none' => t('No restriction')), node_type_get_names()),
    '#default_value' => variable_get('freelinking_nodetitle_searchcontenttype', 'none'),
    '#description' => t('Lookup by title to find a freelink will be restricted to this content type only.'),
  );

  $failover_option['none'] = t('Do nothing');
  $failover_option['showtext'] = t('Show text (remove markup)');

  $extra_description = '';

  // if Create Node plugin is available, it's an option!
  if (module_exists('freelinking_prepopulate')) {
    $failover_option['create'] = t('Add a link to create content. (Without Permission: Access Denied)');
  }
  else {
    $extra_description .= '<br />'
      . t('Note: Enable the <strong>Freelinking Prepopulate</strong> submodule to add a content creation failover option.');
  }

  // if search is available, have a search failover
  if (module_exists('search')) {
    $failover_option['search'] = t('Add a link to Search Content');
  }
  else {
    $extra_description .= '<br /><strong>'
      . t('Note: Enable the %module module for internal search option.', array('%module' => 'Search'))
      . '</strong>';
    // if search is unavailable offer it's own (applicable)search fallback. [Google, etc]
    if (($search_plugin = variable_get('freelinking_search_failover', 'error')) != 'error') {
      $failover_option['search'] = t('Add a link to %search Search Content.',
        array('%search' => drupal_ucfirst($search_plugin)));
    }
  }
  $failover_option['error'] = t('Insert an error message');

  $form['freelinking_nodetitle_failover'] = array(
    '#title' => t('If a suitable content is not found'),
    '#type' => 'select',
    '#options' => $failover_option,
    '#default_value' => variable_get('freelinking_nodetitle_failover',
      _freelinking_nodetitle_default_failover()),
    '#description' => t('What should freelinking do when the page is not found?')
      . $extra_description,
  );
  return $form;
}

/**
 * Grab the nid associated with the title.
 * Attempt some degree of language sensibility.
 */
function freelinking_nodetitle_nid_from_title(&$target) {
  // Avoid recursion by marking loaded nodes.
  $title = $target['dest'];
  $node_cache_title = &drupal_static(__FUNCTION__, array());
  if (isset($node_cache_title['title']) && (in_array($title, $node_cache_title['title']))) {
    // Return TRUE to avoid infinite recursion.
    return TRUE;
  }
  // First time accessing this node. Process it.
  $params['title'] = $target['dest'];
  $default_type = variable_get('freelinking_nodetitle_searchcontenttype', 'none');
  if (isset($target['type'])) {
    $params['type'] = $target['type'];
  }
  elseif ($default_type != 'none') {
    $params['type'] = $default_type;
  }
  $nodes = node_load_multiple(array(), $params);

  if (empty($nodes)) {
    return NULL;
  }

  // language restriction. Includes next-best-language logic.
  $language = array(language_default('language'), '');
  if (module_exists('locale')) {
    if (isset($target['language'])) {
      array_unshift($language, $target['language']);
    }
    foreach ($language as $priority) {
      foreach ($nodes as $node) {
        if ($priority == $node->language) {
          $retn = $node;
          break 2;
        }
      }
    }
  }
  if (!isset($retn)) {
    $retn = reset($nodes);
  }
  if (node_access('view', $retn)) {
    if (!isset($key)) {
      $retn = reset($nodes);
      $key = key($nodes);
    }
    $node_cache_title['nid'][] = $nodes[$key]->nid;
    $node_cache_title['title'][] = $nodes[$key]->title;
    $node_cache_title['language'][] = $language;
    return $retn;
  }
}

/**
 * Determining the proper failure response per plugin configuration
 */
function _freelinking_nodetitle_failure($target) {
  $failover = variable_get('freelinking_nodetitle_failover',
    _freelinking_nodetitle_default_failover());

  switch ($failover) {
    case 'create':
      return array('failover' => 'freelinking_prepopulate', 'target' => $target);
    case 'showtext':
      return array('failover' => 'showtext', 'target' => $target);
    case 'search':
      return array('failover' => 'search', 'target' => $target);
    case 'error':
      return array('failover' => 'error', 'message' => t('node title "%title" does not exist',
        array('%title' => $target['dest'])));

  }
  // do nothing
  return FALSE;
}

/**
 * Find the best default failover
 */
function _freelinking_nodetitle_default_failover() {
  if (module_exists('freelinking_prepopulate')) {
    return 'create node';
  }
  elseif (module_exists('search')) {
    return 'search';
  }
  return 'none';
}
