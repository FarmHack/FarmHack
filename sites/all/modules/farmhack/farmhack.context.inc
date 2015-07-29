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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global';
  $context->description = '';
  $context->tag = 'farmhack';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-farmhack_donate' => array(
          'module' => 'boxes',
          'delta' => 'farmhack_donate',
          'region' => 'header',
          'weight' => '-10',
        ),
        'boxes-farmhack_involved' => array(
          'module' => 'boxes',
          'delta' => 'farmhack_involved',
          'region' => 'footer_firstcolumn',
          'weight' => '-10',
        ),
        'boxes-farmhac_friends' => array(
          'module' => 'boxes',
          'delta' => 'farmhac_friends',
          'region' => 'footer_secondcolumn',
          'weight' => '-10',
        ),
        'boxes-farmhack_social_media_links' => array(
          'module' => 'boxes',
          'delta' => 'farmhack_social_media_links',
          'region' => 'footer_thirdcolumn',
          'weight' => '-10',
        ),
        'boxes-license' => array(
          'module' => 'boxes',
          'delta' => 'license',
          'region' => 'footer_fourthcolumn',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('farmhack');
  $export['global'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'library_tool_search';
  $context->description = '';
  $context->tag = 'Tools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'library/search' => 'library/search',
        'library/search/*' => 'library/search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-8Q3VMyDWwZpQ3FyNxo6OORFlpOxYYwed' => array(
          'module' => 'facetapi',
          'delta' => '8Q3VMyDWwZpQ3FyNxo6OORFlpOxYYwed',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tools');
  $export['library_tool_search'] = $context;

  return $export;
}
