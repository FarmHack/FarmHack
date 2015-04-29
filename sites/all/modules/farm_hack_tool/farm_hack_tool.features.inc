<?php
/**
 * @file
 * farm_hack_tool.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farm_hack_tool_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function farm_hack_tool_node_info() {
  $items = array(
    'farm_hack_tool' => array(
      'name' => t('Farm Hack Tool'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
