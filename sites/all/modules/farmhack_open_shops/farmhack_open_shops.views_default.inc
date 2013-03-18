<?php
/**
 * @file
 * farmhack_open_shops.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function farmhack_open_shops_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'organization';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Organization';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = FALSE;
  $handler->display->display_options['header']['php']['php_output'] = '<style>.views-label {font-weight: bold;}</style>';
  /* Field: Content: Organization's Image */
  $handler->display->display_options['fields']['field_organization_image']['id'] = 'field_organization_image';
  $handler->display->display_options['fields']['field_organization_image']['table'] = 'field_data_field_organization_image';
  $handler->display->display_options['fields']['field_organization_image']['field'] = 'field_organization_image';
  $handler->display->display_options['fields']['field_organization_image']['label'] = '';
  $handler->display->display_options['fields']['field_organization_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_organization_image']['settings'] = array(
    'image_style' => 'organization_image',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_organization_image']['field_api_classes'] = 0;
  /* Field: Content: Farm Hack Users in this organization */
  $handler->display->display_options['fields']['field_organization_to_user']['id'] = 'field_organization_to_user';
  $handler->display->display_options['fields']['field_organization_to_user']['table'] = 'field_data_field_organization_to_user';
  $handler->display->display_options['fields']['field_organization_to_user']['field'] = 'field_organization_to_user';
  $handler->display->display_options['fields']['field_organization_to_user']['label'] = 'Members';
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_organization_to_user']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_to_user']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_to_user']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_organization_to_user']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_organization_to_user']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_organization_to_user']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_organization_to_user']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Joined on';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j, Y';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'print "<br><br>"';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Organization's Website */
  $handler->display->display_options['fields']['field_organization_s_website']['id'] = 'field_organization_s_website';
  $handler->display->display_options['fields']['field_organization_s_website']['table'] = 'field_data_field_organization_s_website';
  $handler->display->display_options['fields']['field_organization_s_website']['field'] = 'field_organization_s_website';
  $handler->display->display_options['fields']['field_organization_s_website']['label'] = '';
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_s_website']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_organization_s_website']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_organization_s_website']['settings'] = array(
    'trim_length' => '80',
    'nofollow' => 0,
  );
  $handler->display->display_options['fields']['field_organization_s_website']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_organization_s_website']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_organization_s_website']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_organization_s_website']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );

  /* Display: organization */
  $handler = $view->new_display('block', 'organization', 'block');
  $export['organization'] = $view;

  $view = new view;
  $view->name = 'organization_comments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Organization\'s Comments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '1, 5, 10, 20, 40, 60';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'comment';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h1 style="background:#f7e77f">Forum Comments from Organization\'s members</h1>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Relationship: Comment: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 1;
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['subject']['link_to_comment'] = 1;
  /* Sort criterion: Comment: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Comment: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'comment';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['code'] = '$node = node_load(arg(1));
$users = "";
foreach($node->field_organization_to_user["und"] as $i => $entry) {
  if($i != 0) { $users .= "+"; }
  $users .= $entry[\'target_id\'];
}
return $users;
';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: Comment: Approved */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 0;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['organization_comments'] = $view;

  $view = new view;
  $view->name = 'organization_tools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Organization\'s Tools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '...<h1 style="background:#f7e77f">Organization\'s Tools</h1>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opentools_tool' => 'opentools_tool',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['organization_tools'] = $view;

  return $export;
}
