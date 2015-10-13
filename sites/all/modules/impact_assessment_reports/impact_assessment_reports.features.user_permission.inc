<?php
/**
 * @file
 * impact_assessment_reports.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function impact_assessment_reports_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create impact_assessment_report content'.
  $permissions['create impact_assessment_report content'] = array(
    'name' => 'create impact_assessment_report content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any impact_assessment_report content'.
  $permissions['delete any impact_assessment_report content'] = array(
    'name' => 'delete any impact_assessment_report content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own impact_assessment_report content'.
  $permissions['delete own impact_assessment_report content'] = array(
    'name' => 'delete own impact_assessment_report content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any impact_assessment_report content'.
  $permissions['edit any impact_assessment_report content'] = array(
    'name' => 'edit any impact_assessment_report content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own impact_assessment_report content'.
  $permissions['edit own impact_assessment_report content'] = array(
    'name' => 'edit own impact_assessment_report content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
