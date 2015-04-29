<?php
/**
 * @file
 * farm_hack_tool.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function farm_hack_tool_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create farm_hack_tool content'.
  $permissions['create farm_hack_tool content'] = array(
    'name' => 'create farm_hack_tool content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any farm_hack_tool content'.
  $permissions['delete any farm_hack_tool content'] = array(
    'name' => 'delete any farm_hack_tool content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own farm_hack_tool content'.
  $permissions['delete own farm_hack_tool content'] = array(
    'name' => 'delete own farm_hack_tool content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any farm_hack_tool content'.
  $permissions['edit any farm_hack_tool content'] = array(
    'name' => 'edit any farm_hack_tool content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own farm_hack_tool content'.
  $permissions['edit own farm_hack_tool content'] = array(
    'name' => 'edit own farm_hack_tool content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
