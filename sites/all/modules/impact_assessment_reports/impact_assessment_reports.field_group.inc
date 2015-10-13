<?php
/**
 * @file
 * impact_assessment_reports.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function impact_assessment_reports_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool7|node|tool|default';
  $field_group->group_name = 'group_tool7';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Impact',
    'weight' => '6',
    'children' => array(
      0 => 'impact_link_entity_view_1',
      1 => 'impact_assessment_reports_on_tool_entity_view_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Impact',
      'instance_settings' => array(
        'classes' => 'group-tool7 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool7|node|tool|default'] = $field_group;

  return $export;
}
