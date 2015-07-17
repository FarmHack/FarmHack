<?php
/**
 * @file
 * nefke_shared_calendar.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nefke_shared_calendar_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'nefke_events_external_';
  $feeds_importer->config = array(
    'name' => 'NEFKE Events (External)',
    'description' => 'The “external” feed importer will import events that were created on other websites.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'http',
        'accept_invalid_cert' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'title',
          'xpathparser:1' => 'date-start',
          'xpathparser:2' => 'date-end',
          'xpathparser:7' => 'category',
          'xpathparser:9' => 'source',
          'xpathparser:10' => 'location',
          'xpathparser:12' => 'description',
          'xpathparser:13' => 'link',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:7' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
        ),
        'context' => '//node',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:7' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '990',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_date_time:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_date_time:end',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_nefke_event_categories',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_source_id',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_eventlocation',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_event_description',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_url_uri:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'event_shared',
        'update_non_existent' => 'delete',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['nefke_events_external_'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'nefke_events_reciprocal_';
  $feeds_importer->config = array(
    'name' => 'NEFKE Events (Reciprocal)',
    'description' => 'The “reciprocal” feed importer will import events that were originally created on your site and have found their way back home',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'title',
          'xpathparser:1' => 'date-start',
          'xpathparser:2' => 'date-end',
          'xpathparser:6' => 'source',
          'xpathparser:7' => 'category',
          'xpathparser:8' => 'location',
          'xpathparser:10' => 'description',
          'xpathparser:11' => 'link',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
        ),
        'context' => '//node',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '990',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_date_time:start',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_date_time:end',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:6',
            'target' => 'nid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_nefke_event_categories',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_eventlocation',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_event_description',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_url_uri:url',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 0,
        'bundle' => 'event_shared',
        'update_non_existent' => 'delete',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['nefke_events_reciprocal_'] = $feeds_importer;

  return $export;
}
