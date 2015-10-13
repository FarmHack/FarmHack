<?php
/**
 * @file
 * impact_assessment_reports.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function impact_assessment_reports_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function impact_assessment_reports_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function impact_assessment_reports_node_info() {
  $items = array(
    'impact_assessment_report' => array(
      'name' => t('Impact Assessment Report'),
      'base' => 'node_content',
      'description' => t('A simple report form related to tools.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
