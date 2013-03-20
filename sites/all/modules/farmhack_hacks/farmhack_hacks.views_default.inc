<?php
/**
 * @file
 * farmhack_hacks.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function farmhack_hacks_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'hacks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Hacks';
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
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = FALSE;
  $handler->display->display_options['header']['php']['php_output'] = '<div style="font-size: 25px; color: #f7e77f;"><center>Hacks. Not quite tools but too useful not to share.</center></div>
<style>

.plus1-widget a {
color: #000;
}
.plus1-widget a:hover { color: red; }

.plus1-widget {background: #f7e77f !important;
color: #000;
top: 16px;
left: -41px;
border-radius: 6px 0 0 6px;
width: 35px !important;
position:absolute;
}
.view-hacks td { background: #FFF !important; }

.view-hacks div.node {background: #EEE !important; width: 230px; position: relative;-moz-box-shadow: 0 0 5px #888;
-webkit-box-shadow: 0 0 5px#888;
box-shadow: 0 0 5px #888;}

.node-teaser {padding: 10px; text-align:center;}
</style>';
  /* Field: Content: A photo of your hack */
  $handler->display->display_options['fields']['field_photo_of_your_hack']['id'] = 'field_photo_of_your_hack';
  $handler->display->display_options['fields']['field_photo_of_your_hack']['table'] = 'field_data_field_photo_of_your_hack';
  $handler->display->display_options['fields']['field_photo_of_your_hack']['field'] = 'field_photo_of_your_hack';
  $handler->display->display_options['fields']['field_photo_of_your_hack']['label'] = '';
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_photo_of_your_hack']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_photo_of_your_hack']['settings'] = array(
    'image_style' => '300x300',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_photo_of_your_hack']['field_api_classes'] = 0;
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
    'hack' => 'hack',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'hacks';
  $export['hacks'] = $view;

  return $export;
}
