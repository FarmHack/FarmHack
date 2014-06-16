<?php
/**
 * @file
 * farmhack_events.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function farmhack_events_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event_node_type';
  $context->description = '';
  $context->tag = 'Events';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'event' => 'event',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-event_not_published_message' => array(
          'module' => 'boxes',
          'delta' => 'event_not_published_message',
          'region' => 'highlighted',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Events');
  $export['event_node_type'] = $context;

  return $export;
}
