<?php
/**
 * @file
 * nefke_shared_calendar.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function nefke_shared_calendar_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Unique source ID for events';
  $rule->name = 'unique_source_id_for_events';
  $rule->field_name = 'field_source_id';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'event_shared';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'data' => 'bundle',
    'per_user' => 0,
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = 'Sorry, this event has already been added';
  $export['unique_source_id_for_events'] = $rule;

  return $export;
}
