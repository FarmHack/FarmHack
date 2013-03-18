<?php
/**
 * @file
 * farmhack_org.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function farmhack_org_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'organization';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'organization' => 'organization',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-opentools_tools-block_3' => array(
          'module' => 'views',
          'delta' => 'opentools_tools-block_3',
          'region' => 'content',
          'weight' => '-64',
        ),
        'views-fb1421d49000589a8abfd3842f0d48f0' => array(
          'module' => 'views',
          'delta' => 'fb1421d49000589a8abfd3842f0d48f0',
          'region' => 'content',
          'weight' => '-63',
        ),
        'views-organization_comments-block' => array(
          'module' => 'views',
          'delta' => 'organization_comments-block',
          'region' => 'content',
          'weight' => '-62',
        ),
        'views-organization-block' => array(
          'module' => 'views',
          'delta' => 'organization-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['organization'] = $context;

  return $export;
}
