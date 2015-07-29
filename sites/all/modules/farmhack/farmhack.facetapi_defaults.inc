<?php
/**
 * @file
 * farmhack.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function farmhack_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::sm_field_tool_stage';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'sm_field_tool_stage';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => 1,
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  );
  $export['apachesolr@solr::sm_field_tool_stage'] = $facet;

  return $export;
}
