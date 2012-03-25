<?php
/**
 * @file
 * farmhack_users.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function farmhack_users_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'farmhack_user_profile';
  $context->description = '';
  $context->tag = 'FarmHack';
  $context->conditions = array(
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'all',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-farmhack_user_wiki_edits-block' => array(
          'module' => 'views',
          'delta' => 'farmhack_user_wiki_edits-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-098d16db421c23b1630a19009bc89f20' => array(
          'module' => 'views',
          'delta' => '098d16db421c23b1630a19009bc89f20',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-farmhack_user_comments-block' => array(
          'module' => 'views',
          'delta' => 'farmhack_user_comments-block',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('FarmHack');
  $export['farmhack_user_profile'] = $context;

  return $export;
}
