<?php
/**
 * @file
 * farmhack_events.box.inc
 */

/**
 * Implements hook_default_box().
 */
function farmhack_events_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'event_not_published_message';
  $box->plugin_key = 'simple';
  $box->title = 'Event not yet published!';
  $box->description = 'Event not yet published!';
  $box->options = array(
    'body' => array(
      'value' => '<?php

$node = node_load(arg(1));
if ($node->status == 0) { 
?>
  Your event has not yet been published. Start a forum topic to get discussion around this event started and send an email to the Farm Hack events team to give them the heads up.
<?php
}
?>',
      'format' => 'php_code',
    ),
  );
  $export['event_not_published_message'] = $box;

  return $export;
}
