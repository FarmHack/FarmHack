<?php
/**
 * @file
 * farmhack_users.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function farmhack_users_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'farmhack_user_comments';
  $view->description = '';
  $view->tag = 'FarmHack';
  $view->base_table = 'comment';
  $view->human_name = 'FarmHack User Comments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stream of Forum Comments';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'comment';
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

  /* Display: User's Comments */
  $handler = $view->new_display('block', 'User\'s Comments', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Comment: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'comment';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: All Comments */
  $handler = $view->new_display('block', 'All Comments', 'block_1');
  $export['farmhack_user_comments'] = $view;

  $view = new view;
  $view->name = 'farmhack_user_forum_topics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FarmHack User Forum Topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stream of Forum Topics';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_image' => 'field_image',
    'title' => 'title',
    'last_comment_timestamp' => 'last_comment_timestamp',
    'created' => 'created',
    'comment_count' => 'comment_count',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'field_image' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_comment_timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Topic Type (field_forum_topic_type) */
  $handler->display->display_options['relationships']['field_forum_topic_type_tid']['id'] = 'field_forum_topic_type_tid';
  $handler->display->display_options['relationships']['field_forum_topic_type_tid']['table'] = 'field_data_field_forum_topic_type';
  $handler->display->display_options['relationships']['field_forum_topic_type_tid']['field'] = 'field_forum_topic_type_tid';
  $handler->display->display_options['relationships']['field_forum_topic_type_tid']['required'] = 0;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['relationship'] = 'field_forum_topic_type_tid';
  $handler->display->display_options['fields']['field_image']['label'] = 'Topic Type';
  $handler->display->display_options['fields']['field_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'icon',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'In 50 characters or less...';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Last comment time */
  $handler->display->display_options['fields']['last_comment_timestamp']['id'] = 'last_comment_timestamp';
  $handler->display->display_options['fields']['last_comment_timestamp']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_comment_timestamp']['field'] = 'last_comment_timestamp';
  $handler->display->display_options['fields']['last_comment_timestamp']['label'] = 'Last comment';
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['last_comment_timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['last_comment_timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_comment_timestamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['last_comment_timestamp']['date_format'] = 'long';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Posted';
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
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Number of Comments';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['comment_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['comment_count']['format_plural'] = 0;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'New to you?';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['label'] = '# of Comments new to you';
  $handler->display->display_options['fields']['new_comments']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['external'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['new_comments']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['new_comments']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['html'] = 0;
  $handler->display->display_options['fields']['new_comments']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['new_comments']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = 0;
  $handler->display->display_options['fields']['new_comments']['empty_zero'] = 0;
  $handler->display->display_options['fields']['new_comments']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['new_comments']['format_plural'] = 0;
  $handler->display->display_options['fields']['new_comments']['link_to_comment'] = 1;
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
    'forum' => 'forum',
  );

  /* Display: User's Forum Topics */
  $handler = $view->new_display('block', 'User\'s Forum Topics', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: All Forum Topics */
  $handler = $view->new_display('block', 'All Forum Topics', 'block_1');
  $export['farmhack_user_forum_topics'] = $view;

  $view = new view;
  $view->name = 'farmhack_user_wiki_edits';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'FarmHack User Wiki Edits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stream of Wiki Edits';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_1']['required'] = 0;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['vid']['id'] = 'vid';
  $handler->display->display_options['relationships']['vid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['vid']['field'] = 'vid';
  $handler->display->display_options['relationships']['vid']['required'] = 0;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = 1;
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  /* Field: Content revision: Log message */
  $handler->display->display_options['fields']['log']['id'] = 'log';
  $handler->display->display_options['fields']['log']['table'] = 'node_revision';
  $handler->display->display_options['fields']['log']['field'] = 'log';
  $handler->display->display_options['fields']['log']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['log']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['log']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['log']['alter']['external'] = 0;
  $handler->display->display_options['fields']['log']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['log']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['log']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['log']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['log']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['log']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['log']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['log']['alter']['html'] = 0;
  $handler->display->display_options['fields']['log']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['log']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['log']['hide_empty'] = 0;
  $handler->display->display_options['fields']['log']['empty_zero'] = 0;
  $handler->display->display_options['fields']['log']['hide_alter_empty'] = 1;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['relationship'] = 'vid';
  $handler->display->display_options['fields']['timestamp_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['timestamp_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['timestamp_1']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp_1']['comments'] = 0;
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'wiki' => 'wiki',
  );

  /* Display: User's Wiki Edits */
  $handler = $view->new_display('block', 'User\'s Wiki Edits', 'block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid_1';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: All Wiki Edits */
  $handler = $view->new_display('block', 'All Wiki Edits', 'block_1');
  $export['farmhack_user_wiki_edits'] = $view;

  return $export;
}
