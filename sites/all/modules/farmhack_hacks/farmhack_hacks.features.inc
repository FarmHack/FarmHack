<?php
/**
 * @file
 * farmhack_hacks.features.inc
 */

/**
 * Implements hook_views_api().
 */
function farmhack_hacks_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function farmhack_hacks_node_info() {
  $items = array(
    'hack' => array(
      'name' => t('hack'),
      'base' => 'node_content',
      'description' => t('Not quite a tool, a modification to a tool or a process.'),
      'has_title' => '1',
      'title_label' => t('Hack description in one sentence'),
      'help' => '',
    ),
  );
  return $items;
}
