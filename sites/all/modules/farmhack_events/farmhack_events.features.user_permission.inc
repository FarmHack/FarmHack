<?php
/**
 * @file
 * farmhack_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function farmhack_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: publish any event content
  $permissions['publish any event content'] = array(
    'name' => 'publish any event content',
    'roles' => array(),
  );

  // Exported permission: unpublish any event content
  $permissions['unpublish any event content'] = array(
    'name' => 'unpublish any event content',
    'roles' => array(),
  );

  return $permissions;
}
