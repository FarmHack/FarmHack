<?php

/**
 * @file
 * Views integration for Google Analytics Counter tables.
 *
 * @see http://drupal.org/project/views
 */

/**
 * Implements hook_views_data()
 */
function google_analytics_counter_views_data() {
  $data = array();

  $data['google_analytics_counter_storage'] = array(
    'table' => array(
      'base' => array(
        'field' => 'nid',
        'title' => t('Google Analytics Counter Storage'),
        'help' => t('Google Analytics Counter module table holding pageview counts.'),
      ),
      'group' => 'Google Analytics Counter',
    ),
    'nid' => array(
      'title' => 'Nid',
      'help' => t('Node IDs'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
    ),
    'pageview_total' => array(
      'title' => 'Pageview Total',
      'help' => t('Total pageview counts'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
  );

  $data['google_analytics_counter_storage']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  return $data;
}
