<?php
/**
 * @file
 * farmhack_prevent_dissappear_form.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function farmhack_prevent_dissappear_form_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'farmhack_prevent_dissappear_form';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'opentools_tool' => 'opentools_tool',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-farmhack_prevent_dissappear_form' => array(
          'module' => 'boxes',
          'delta' => 'farmhack_prevent_dissappear_form',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['farmhack_prevent_dissappear_form'] = $context;

  return $export;
}
