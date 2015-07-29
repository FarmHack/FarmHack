<?php
/**
 * @file
 * farmhack.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function farmhack_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://localhost:8983/solr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_search_facet_pages' => '',
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'event_shared',
      1 => 'forum',
      2 => 'opentools_tool',
      3 => 'tool',
      4 => 'wiki',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
