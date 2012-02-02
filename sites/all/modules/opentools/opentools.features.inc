<?php
/**
 * @file
 * opentools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opentools_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function opentools_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function opentools_node_info() {
  $items = array(
    'wiki' => array(
      'name' => t('Wiki page'),
      'base' => 'node_content',
      'description' => t('A <em>wiki page</em>, with freelinking and wiki input format.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
