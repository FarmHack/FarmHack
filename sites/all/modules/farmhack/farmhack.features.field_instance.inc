<?php
/**
 * @file
 * farmhack.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function farmhack_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-problem_statement-body'
  $field_instances['node-problem_statement-body'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Narrative',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 10,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-problem_statement-field_problem_action'
  $field_instances['node-problem_statement-field_problem_action'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<em>Existing tags (e.g.</em>improve plant germination at lower cost<em>) will be suggested as you type.</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_problem_action',
    'label' => 'I want a tool to',
    'required' => 1,
    'settings' => array(
      'jquery_ui_multiselect' => array(
        'dividerLocation' => 0.5,
        'doubleClickable' => 1,
        'dragToAdd' => 1,
        'enabled' => 0,
        'height' => 0,
        'includeAddAll' => 1,
        'includeRemoveAll' => 1,
        'searchable' => 1,
        'selectedContainerOnLeft' => 1,
        'sortable' => 1,
        'width' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'node-problem_statement-field_problem_functionality'
  $field_instances['node-problem_statement-field_problem_functionality'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_problem_functionality',
    'label' => 'What functionality solves this problem?',
    'required' => 0,
    'settings' => array(
      'jquery_ui_multiselect' => array(
        'dividerLocation' => 0.5,
        'doubleClickable' => 1,
        'dragToAdd' => 1,
        'enabled' => 0,
        'height' => 0,
        'includeAddAll' => 1,
        'includeRemoveAll' => 1,
        'searchable' => 1,
        'selectedContainerOnLeft' => 1,
        'sortable' => 1,
        'width' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-problem_statement-field_problem_needs'
  $field_instances['node-problem_statement-field_problem_needs'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<em>Add one need per line, e.g. </em>consistent germination is important economically<em> AND </em>commercially available solutions are too expensive',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_problem_needs',
    'label' => 'Because',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-problem_statement-field_problem_person'
  $field_instances['node-problem_statement-field_problem_person'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<em>Existing tags (e.g.</em> farmer<em>) will be suggested as you type.</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_problem_person',
    'label' => 'I am a',
    'required' => 1,
    'settings' => array(
      'jquery_ui_multiselect' => array(
        'dividerLocation' => 0.5,
        'doubleClickable' => 1,
        'dragToAdd' => 1,
        'enabled' => 0,
        'height' => 0,
        'includeAddAll' => 1,
        'includeRemoveAll' => 1,
        'searchable' => 1,
        'selectedContainerOnLeft' => 1,
        'sortable' => 1,
        'width' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-problem_statement-field_problem_tags'
  $field_instances['node-problem_statement-field_problem_tags'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<em>Enter a list of relevant terms separated by commas. Existing tags will be suggested as you type.</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_problem_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'jquery_ui_multiselect' => array(
        'dividerLocation' => 0.5,
        'doubleClickable' => 1,
        'dragToAdd' => 1,
        'enabled' => 0,
        'height' => 0,
        'includeAddAll' => 1,
        'includeRemoveAll' => 1,
        'searchable' => 1,
        'selectedContainerOnLeft' => 1,
        'sortable' => 1,
        'width' => 0,
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-problem_statement-field_related_conversations'
  $field_instances['node-problem_statement-field_related_conversations'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<em>If you don\'t see the desired conversation topic in the dropdown list, you can create a new one via the green button to the right.</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_related_conversations',
    'label' => 'Related Conversations',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiple_selects',
      'settings' => array(),
      'type' => 'multiple_selects',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-problem_statement-field_related_open_shops'
  $field_instances['node-problem_statement-field_related_open_shops'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<em>If you don\'t see the desired open shop in the dropdown list, you can create a new one via the green button to the right.</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_related_open_shops',
    'label' => 'Related Open Shops',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiple_selects',
      'settings' => array(),
      'type' => 'multiple_selects',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-problem_statement-field_related_tools'
  $field_instances['node-problem_statement-field_related_tools'] = array(
    'bundle' => 'problem_statement',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<em>If you don\'t see the desired tool in the dropdown list, you can create a new one via the green button to the right.</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 0,
    'field_name' => 'field_related_tools',
    'label' => 'Related Tools',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiple_selects',
      'settings' => array(),
      'type' => 'multiple_selects',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-tool-field_commerce_markup'
  $field_instances['node-tool-field_commerce_markup'] = array(
    'bundle' => 'tool',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_view',
        'weight' => 7,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_commerce_markup',
    'label' => 'Commerce Markup',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-tool-field_related_problem_statements'
  $field_instances['node-tool-field_related_problem_statements'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<em>If you don\'t see the problem statement in the dropdown list, you can create a new one via the green button to the right.</em>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 0,
    'entityconnect_unload_edit' => 1,
    'field_name' => 'field_related_problem_statements',
    'label' => 'Related Problem Statements',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiple_selects',
      'settings' => array(),
      'type' => 'multiple_selects',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-tool-field_tool_description'
  $field_instances['node-tool-field_tool_description'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Add a short narrative to describe your tool concept.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tool_description',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-tool-field_tool_image'
  $field_instances['node-tool-field_tool_image'] = array(
    'bundle' => 'tool',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'lightbox2',
        'settings' => array(),
        'type' => 'lightbox2__lightbox__medium__original',
        'weight' => 2,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tool_image',
    'label' => 'Representative Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '5 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'image' => 0,
          'image_300x300' => 0,
          'image_icon' => 0,
          'image_large' => 0,
          'image_medium' => 0,
          'image_organization_image' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-tool-field_tools_assembly'
  $field_instances['node-tool-field_tools_assembly'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 1,
    'entityconnect_unload_edit' => 1,
    'field_name' => 'field_tools_assembly',
    'label' => 'This tool an assembly of other tools',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiple_selects',
      'settings' => array(),
      'type' => 'multiple_selects',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-tool-field_tools_branch'
  $field_instances['node-tool-field_tools_branch'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 7,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 1,
    'entityconnect_unload_edit' => 1,
    'field_name' => 'field_tools_branch',
    'label' => 'This tool is a branch from these other tools',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiple_selects',
      'settings' => array(),
      'type' => 'multiple_selects',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-tool-field_tools_component'
  $field_instances['node-tool-field_tools_component'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 1,
    'entityconnect_unload_edit' => 1,
    'field_name' => 'field_tools_component',
    'label' => 'This tool is a component of these other tools',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiple_selects',
      'settings' => array(),
      'type' => 'multiple_selects',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-tool-field_tools_merge'
  $field_instances['node-tool-field_tools_merge'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_label',
        'weight' => 8,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'entityconnect_unload_add' => 1,
    'entityconnect_unload_edit' => 1,
    'field_name' => 'field_tools_merge',
    'label' => 'This tool merges these other tools together',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiple_selects',
      'settings' => array(),
      'type' => 'multiple_selects',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-tool-field_wiki'
  $field_instances['node-tool-field_wiki'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_wiki',
    'label' => 'Documentation Wiki (Drupal)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-tool-field_wiki2'
  $field_instances['node-tool-field_wiki2'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_wiki2',
    'label' => 'User Manual Wiki (Drupal)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-tool-field_wiki3'
  $field_instances['node-tool-field_wiki3'] = array(
    'bundle' => 'tool',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'notifications' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_wiki3',
    'label' => 'Skills Wiki (Drupal)',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<em>Add one need per line, e.g. </em>consistent germination is important economically<em> AND </em>commercially available solutions are too expensive');
  t('<em>Enter a list of relevant terms separated by commas. Existing tags will be suggested as you type.</em>');
  t('<em>Existing tags (e.g.</em> farmer<em>) will be suggested as you type.</em>');
  t('<em>Existing tags (e.g.</em>improve plant germination at lower cost<em>) will be suggested as you type.</em>');
  t('<em>If you don\'t see the desired conversation topic in the dropdown list, you can create a new one via the green button to the right.</em>');
  t('<em>If you don\'t see the desired open shop in the dropdown list, you can create a new one via the green button to the right.</em>');
  t('<em>If you don\'t see the desired tool in the dropdown list, you can create a new one via the green button to the right.</em>');
  t('<em>If you don\'t see the problem statement in the dropdown list, you can create a new one via the green button to the right.</em>');
  t('Add a short narrative to describe your tool concept.');
  t('Because');
  t('Commerce Markup');
  t('Description');
  t('Documentation Wiki (Drupal)');
  t('I am a');
  t('I want a tool to');
  t('Narrative');
  t('Related Conversations');
  t('Related Open Shops');
  t('Related Problem Statements');
  t('Related Tools');
  t('Representative Image');
  t('Skills Wiki (Drupal)');
  t('Tags');
  t('This tool an assembly of other tools');
  t('This tool is a branch from these other tools');
  t('This tool is a component of these other tools');
  t('This tool merges these other tools together');
  t('User Manual Wiki (Drupal)');
  t('What functionality solves this problem?');

  return $field_instances;
}
