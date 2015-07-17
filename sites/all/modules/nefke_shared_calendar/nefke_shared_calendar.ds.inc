<?php
/**
 * @file
 * nefke_shared_calendar.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nefke_shared_calendar_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|event|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nefke_shared_calendar_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'field_short_description',
      ),
      'left' => array(
        0 => 'field_long_description',
      ),
      'right' => array(
        0 => 'field_event_date',
        1 => 'field_event_activities',
        2 => 'field_topic',
      ),
      'footer' => array(
        0 => 'comments',
      ),
    ),
    'fields' => array(
      'field_short_description' => 'header',
      'field_long_description' => 'left',
      'field_event_date' => 'right',
      'field_event_activities' => 'right',
      'field_topic' => 'right',
      'comments' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|event|default'] = $ds_layout;

  return $export;
}
