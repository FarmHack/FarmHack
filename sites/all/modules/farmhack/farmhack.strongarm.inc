<?php
/**
 * @file
 * farmhack.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function farmhack_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_problem_statement';
  $strongarm->value = '1';
  $export['auto_entitylabel_node_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_problem_statement';
  $strongarm->value = 'I am a [node:field_problem_person] and I want a tool to [node:field_problem_action]';
  $export['auto_entitylabel_pattern_node_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_problem_statement';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_node_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_problem_statement';
  $strongarm->value = 0;
  $export['comment_anonymous_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_tool';
  $strongarm->value = 0;
  $export['comment_anonymous_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_problem_statement';
  $strongarm->value = 1;
  $export['comment_default_mode_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_tool';
  $strongarm->value = 1;
  $export['comment_default_mode_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_problem_statement';
  $strongarm->value = '50';
  $export['comment_default_per_page_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_tool';
  $strongarm->value = '50';
  $export['comment_default_per_page_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_problem_statement';
  $strongarm->value = 1;
  $export['comment_form_location_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_tool';
  $strongarm->value = 1;
  $export['comment_form_location_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_problem_statement';
  $strongarm->value = '0';
  $export['comment_preview_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_tool';
  $strongarm->value = '1';
  $export['comment_preview_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_problem_statement';
  $strongarm->value = '0';
  $export['comment_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_problem_statement';
  $strongarm->value = 1;
  $export['comment_subject_field_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_tool';
  $strongarm->value = 1;
  $export['comment_subject_field_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_tool';
  $strongarm->value = '2';
  $export['comment_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__problem_statement';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'notifications' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
        'path' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(
        'problem_statement_eva_entity_view_1' => array(
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__tool';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'notifications' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
        'path' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(
        'problem_statement_eva_on_tool_display_entity_view_1' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_problem_statement';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_tool';
  $strongarm->value = array();
  $export['menu_options_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_problem_statement';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_tool';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_problem_statement';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_tool';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_problem_statement';
  $strongarm->value = '0';
  $export['node_preview_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_tool';
  $strongarm->value = '0';
  $export['node_preview_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_problem_statement';
  $strongarm->value = 1;
  $export['node_submitted_problem_statement'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_tool';
  $strongarm->value = 1;
  $export['node_submitted_tool'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_tool_pattern';
  $strongarm->value = 'library/[node:title]';
  $export['pathauto_node_tool_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_bootstrap_farmhack_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'bootstrap__active_tab' => 'edit-components',
    'bootstrap_fluid_container' => 0,
    'bootstrap_button_size' => '',
    'bootstrap_button_colorize' => 1,
    'bootstrap_button_iconize' => 1,
    'bootstrap_forms_required_has_error' => 0,
    'bootstrap_forms_smart_descriptions' => 1,
    'bootstrap_forms_smart_descriptions_limit' => '250',
    'bootstrap_forms_smart_descriptions_allowed_tags' => 'b, code, em, i, kbd, span, strong',
    'bootstrap_image_shape' => '',
    'bootstrap_image_responsive' => 1,
    'bootstrap_table_bordered' => 0,
    'bootstrap_table_condensed' => 0,
    'bootstrap_table_hover' => 1,
    'bootstrap_table_striped' => 1,
    'bootstrap_table_responsive' => 1,
    'bootstrap_breadcrumb' => '1',
    'bootstrap_breadcrumb_home' => 0,
    'bootstrap_breadcrumb_title' => 1,
    'bootstrap_navbar_position' => 'static-top',
    'bootstrap_navbar_inverse' => 0,
    'bootstrap_pager_first_and_last' => 1,
    'bootstrap_region_well-navigation' => '',
    'bootstrap_region_well-header' => '',
    'bootstrap_region_well-highlighted' => '',
    'bootstrap_region_well-help' => '',
    'bootstrap_region_well-content' => '',
    'bootstrap_region_well-sidebar_first' => 'well',
    'bootstrap_region_well-sidebar_second' => '',
    'bootstrap_region_well-footer' => '',
    'bootstrap_region_well-page_top' => '',
    'bootstrap_region_well-page_bottom' => '',
    'bootstrap_region_well-dashboard_main' => '',
    'bootstrap_region_well-dashboard_sidebar' => '',
    'bootstrap_region_well-dashboard_inactive' => '',
    'bootstrap_anchors_fix' => 1,
    'bootstrap_anchors_smooth_scrolling' => 1,
    'bootstrap_forms_has_error_value_toggle' => 1,
    'bootstrap_popover_enabled' => 1,
    'bootstrap_popover_animation' => 1,
    'bootstrap_popover_html' => 0,
    'bootstrap_popover_placement' => 'right',
    'bootstrap_popover_selector' => '',
    'bootstrap_popover_trigger' => array(
      'click' => 'click',
      'hover' => 0,
      'focus' => 0,
      'manual' => 0,
    ),
    'bootstrap_popover_trigger_autoclose' => 1,
    'bootstrap_popover_title' => '',
    'bootstrap_popover_content' => '',
    'bootstrap_popover_delay' => '0',
    'bootstrap_popover_container' => 'body',
    'bootstrap_tooltip_enabled' => 1,
    'bootstrap_tooltip_animation' => 1,
    'bootstrap_tooltip_html' => 0,
    'bootstrap_tooltip_placement' => 'auto left',
    'bootstrap_tooltip_selector' => '',
    'bootstrap_tooltip_trigger' => array(
      'hover' => 'hover',
      'focus' => 'focus',
      'click' => 0,
      'manual' => 0,
    ),
    'bootstrap_tooltip_delay' => '0',
    'bootstrap_tooltip_container' => 'body',
    'bootstrap_toggle_jquery_error' => 0,
    'bootstrap_cdn_provider' => 'jsdelivr',
    'bootstrap_cdn_custom_css' => '//cdn.jsdelivr.net/bootstrap/3.3.2/css/bootstrap.css',
    'bootstrap_cdn_custom_css_min' => '//cdn.jsdelivr.net/bootstrap/3.3.2/css/bootstrap.min.css',
    'bootstrap_cdn_custom_js' => '//cdn.jsdelivr.net/bootstrap/3.3.2/js/bootstrap.js',
    'bootstrap_cdn_custom_js_min' => '//cdn.jsdelivr.net/bootstrap/3.3.2/js/bootstrap.min.js',
    'bootstrap_cdn_jsdelivr_version' => '3.3.2',
    'bootstrap_cdn_jsdelivr_theme' => 'bootstrap',
    'jquery_update_jquery_version' => '1.9',
  );
  $export['theme_bootstrap_farmhack_settings'] = $strongarm;

  return $export;
}
