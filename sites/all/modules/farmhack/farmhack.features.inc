<?php
/**
 * @file
 * farmhack.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farmhack_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function farmhack_node_info() {
  $items = array(
    'problem_statement' => array(
      'name' => t('Problem Statement'),
      'base' => 'node_content',
      'description' => t('Pose a problem statement; relate it to tools, open shops, conversations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'tool' => array(
      'name' => t('Dev Tool'),
      'base' => 'node_content',
      'description' => t('This is the new Tool content type, which will be integrated with Problem Statements.  It is still in development.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
