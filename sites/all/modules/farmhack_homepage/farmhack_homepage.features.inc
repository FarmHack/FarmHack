<?php
/**
 * @file
 * farmhack_homepage.features.inc
 */

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function farmhack_homepage_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: frontpage
  $nodequeues['frontpage'] = array(
    'name' => 'frontpage',
    'title' => 'Frontpage',
    'subqueue_title' => '',
    'size' => '30',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'opentools_tool',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
