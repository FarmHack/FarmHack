<?php
/**
 * @file
 * farmhack_events.features.inc
 */

/**
 * Implements hook_node_info().
 */
function farmhack_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Event Name'),
      'help' => '',
    ),
  );
  return $items;
}
