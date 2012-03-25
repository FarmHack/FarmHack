<?php
/**
 * @file
 * farmhack.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function farmhack_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'farmhack_home';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-farmhack_frontpage_blog-block' => array(
          'module' => 'views',
          'delta' => 'farmhack_frontpage_blog-block',
          'region' => 'featured',
          'weight' => '-32',
        ),
        'views-farmhack_frontpage_blog-block_1' => array(
          'module' => 'views',
          'delta' => 'farmhack_frontpage_blog-block_1',
          'region' => 'featured',
          'weight' => '-31',
        ),
        'views-farmhack_frontpage_blog-block_2' => array(
          'module' => 'views',
          'delta' => 'farmhack_frontpage_blog-block_2',
          'region' => 'featured',
          'weight' => '-30',
        ),
        'views-farmhack_frontpage_events-block' => array(
          'module' => 'views',
          'delta' => 'farmhack_frontpage_events-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'boxes-upcomingfarmhack_temp' => array(
          'module' => 'boxes',
          'delta' => 'upcomingfarmhack_temp',
          'region' => 'content',
          'weight' => '-9',
        ),
        'boxes-farmhack_about' => array(
          'module' => 'boxes',
          'delta' => 'farmhack_about',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['farmhack_home'] = $context;

  return $export;
}
