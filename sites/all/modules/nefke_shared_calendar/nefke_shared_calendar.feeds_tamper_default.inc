<?php
/**
 * @file
 * nefke_shared_calendar.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function nefke_shared_calendar_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nefke_events_external_-xpathparser_1-strtotime';
  $feeds_tamper->importer = 'nefke_events_external_';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['nefke_events_external_-xpathparser_1-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nefke_events_external_-xpathparser_2-strtotime';
  $feeds_tamper->importer = 'nefke_events_external_';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['nefke_events_external_-xpathparser_2-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nefke_events_external_-xpathparser_7-explode';
  $feeds_tamper->importer = 'nefke_events_external_';
  $feeds_tamper->source = 'xpathparser:7';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '||',
    'limit' => '',
    'real_separator' => '||',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['nefke_events_external_-xpathparser_7-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nefke_events_reciprocal_-xpathparser_1-strtotime';
  $feeds_tamper->importer = 'nefke_events_reciprocal_';
  $feeds_tamper->source = 'xpathparser:1';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['nefke_events_reciprocal_-xpathparser_1-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nefke_events_reciprocal_-xpathparser_2-strtotime';
  $feeds_tamper->importer = 'nefke_events_reciprocal_';
  $feeds_tamper->source = 'xpathparser:2';
  $feeds_tamper->plugin_id = 'strtotime';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'String to Unix timestamp';
  $export['nefke_events_reciprocal_-xpathparser_2-strtotime'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nefke_events_reciprocal_-xpathparser_7-explode';
  $feeds_tamper->importer = 'nefke_events_reciprocal_';
  $feeds_tamper->source = 'xpathparser:7';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '||',
    'limit' => '',
    'real_separator' => '||',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['nefke_events_reciprocal_-xpathparser_7-explode'] = $feeds_tamper;

  return $export;
}
