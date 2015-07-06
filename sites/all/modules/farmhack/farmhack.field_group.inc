<?php
/**
 * @file
 * farmhack.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function farmhack_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool1|node|tool|default';
  $field_group->group_name = 'group_tool1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tool Concept',
    'weight' => '0',
    'children' => array(
      0 => 'field_tool_description',
      1 => 'field_tool_image',
      2 => 'problem_statement_eva_on_tool_display_entity_view_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_tool1|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool1|node|tool|form';
  $field_group->group_name = 'group_tool1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tool Concept',
    'weight' => '0',
    'children' => array(
      0 => 'field_tool_description',
      1 => 'field_tool_image',
      2 => 'field_related_problem_statements',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tool Concept',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-tool1 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool1|node|tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool2|node|tool|default';
  $field_group->group_name = 'group_tool2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documentation',
    'weight' => '1',
    'children' => array(
      0 => 'field_wiki',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Documentation',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool2|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool2|node|tool|form';
  $field_group->group_name = 'group_tool2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Documentation',
    'weight' => '1',
    'children' => array(
      0 => 'field_wiki',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Documentation',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-tool2 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool2|node|tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool3|node|tool|default';
  $field_group->group_name = 'group_tool3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Manual',
    'weight' => '2',
    'children' => array(
      0 => 'field_wiki2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'User Manual',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool3|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool3|node|tool|form';
  $field_group->group_name = 'group_tool3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Manual',
    'weight' => '2',
    'children' => array(
      0 => 'field_wiki2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'User Manual',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-tool3 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool3|node|tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool4|node|tool|default';
  $field_group->group_name = 'group_tool4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Tools',
    'weight' => '3',
    'children' => array(
      0 => 'field_tools_component',
      1 => 'field_tools_assembly',
      2 => 'field_tools_branch',
      3 => 'field_tools_merge',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related Tools',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool4|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool4|node|tool|form';
  $field_group->group_name = 'group_tool4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Tools',
    'weight' => '3',
    'children' => array(
      0 => 'field_tools_component',
      1 => 'field_tools_assembly',
      2 => 'field_tools_branch',
      3 => 'field_tools_merge',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Related Tools',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-tool4 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool4|node|tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool5|node|tool|default';
  $field_group->group_name = 'group_tool5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skills',
    'weight' => '5',
    'children' => array(
      0 => 'field_wiki3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Skills',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool5|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool5|node|tool|form';
  $field_group->group_name = 'group_tool5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skills',
    'weight' => '4',
    'children' => array(
      0 => 'field_wiki3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Skills',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-tool5 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool5|node|tool|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool6|node|tool|default';
  $field_group->group_name = 'group_tool6';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commerce',
    'weight' => '6',
    'children' => array(
      0 => 'field_commerce_markup',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Commerce',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool6|node|tool|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tool6|node|tool|form';
  $field_group->group_name = 'group_tool6';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'tool';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Commerce',
    'weight' => '5',
    'children' => array(
      0 => 'field_commerce_markup',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Commerce',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-tool6 field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_tool6|node|tool|form'] = $field_group;

  return $export;
}
