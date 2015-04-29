<?php
/**
 * @file
 * farm_hack_hackpad.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function farm_hack_hackpad_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hackpad_client_id';
  $strongarm->value = 'q8mqA5GhwmU';
  $export['hackpad_client_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hackpad_enabled';
  $strongarm->value = 1;
  $export['hackpad_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hackpad_last';
  $strongarm->value = 1430272243;
  $export['hackpad_last'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hackpad_save_edit_node';
  $strongarm->value = 1;
  $export['hackpad_save_edit_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hackpad_secret';
  $strongarm->value = '3e2y7GnnnFdWeWmN2PNFWRPpz4tXCwgC';
  $export['hackpad_secret'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hackpad_subdomain';
  $strongarm->value = 'farmhacktest';
  $export['hackpad_subdomain'] = $strongarm;

  return $export;
}
