<?php
/**
 * @file
 * farmhack.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function farmhack_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'library';
  $searcher->label = 'Library Tools';
  $searcher->description = 'Library search of tools.';
  $searcher->search_path = 'library/tools';
  $searcher->page_title = 'Tool Library';
  $searcher->env_id = 'solr';
  $searcher->settings = array(
    'fq' => array(
      0 => 'bundle:tool',
    ),
    'apachesolr_search_custom_enable' => 1,
    'apachesolr_search_search_type' => 'custom',
    'apachesolr_search_per_page' => 10,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 1,
    'apachesolr_search_browse' => 'results',
  );
  $export['library'] = $searcher;

  return $export;
}
