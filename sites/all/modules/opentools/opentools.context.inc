<?php
/**
 * @file
 * opentools.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function opentools_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events';
  $context->description = '';
  $context->tag = 'events';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events/*' => 'events/*',
        'events' => 'events',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'events',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('events');
  $export['events'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_term_page';
  $context->description = '';
  $context->tag = 'events';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'events' => 'events',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-event_fields-block_2' => array(
          'module' => 'views',
          'delta' => 'event_fields-block_2',
          'region' => 'content',
          'weight' => '-30',
        ),
        'boxes-events_wiki_title' => array(
          'module' => 'boxes',
          'delta' => 'events_wiki_title',
          'region' => 'content',
          'weight' => '-29',
        ),
        'views-events_wiki-block' => array(
          'module' => 'views',
          'delta' => 'events_wiki-block',
          'region' => 'content',
          'weight' => '-28',
        ),
        'boxes-events_forum_title' => array(
          'module' => 'boxes',
          'delta' => 'events_forum_title',
          'region' => 'triptych_first',
          'weight' => '-27',
        ),
        'views-bd0d246f7e0c107484de88112a0c2b74' => array(
          'module' => 'views',
          'delta' => 'bd0d246f7e0c107484de88112a0c2b74',
          'region' => 'triptych_first',
          'weight' => '-26',
        ),
        'views-forum_topic_type_actions-block' => array(
          'module' => 'views',
          'delta' => 'forum_topic_type_actions-block',
          'region' => 'triptych_middle',
          'weight' => '-10',
        ),
        'views-event_forum_activity-block' => array(
          'module' => 'views',
          'delta' => 'event_forum_activity-block',
          'region' => 'triptych_middle',
          'weight' => '-9',
        ),
        'views-event_forum_activity-block_1' => array(
          'module' => 'views',
          'delta' => 'event_forum_activity-block_1',
          'region' => 'triptych_middle',
          'weight' => '-8',
        ),
        'views-event_forum_activity-block_5' => array(
          'module' => 'views',
          'delta' => 'event_forum_activity-block_5',
          'region' => 'triptych_last',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('events');
  $export['events_term_page'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'forums';
  $context->description = '';
  $context->tag = 'forums';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'forums/*' => 'forums/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-forum_topic_type_actions-block' => array(
          'module' => 'views',
          'delta' => 'forum_topic_type_actions-block',
          'region' => 'help',
          'weight' => '-10',
        ),
        'notifications_ui-subscriptions' => array(
          'module' => 'notifications_ui',
          'delta' => 'subscriptions',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
    'menu' => 'forum',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('forums');
  $export['forums'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opentools_tool';
  $context->description = '';
  $context->tag = 'Tools';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'opentools_tool' => 'opentools_tool',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-opentools_tool-block_7' => array(
          'module' => 'views',
          'delta' => 'opentools_tool-block_7',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'views-opentools_tool-block_6' => array(
          'module' => 'views',
          'delta' => 'opentools_tool-block_6',
          'region' => 'featured',
          'weight' => '-9',
        ),
        'views-opentools_tool-block_5' => array(
          'module' => 'views',
          'delta' => 'opentools_tool-block_5',
          'region' => 'featured',
          'weight' => '-7',
        ),
        'views-opentools_tool-block_4' => array(
          'module' => 'views',
          'delta' => 'opentools_tool-block_4',
          'region' => 'featured',
          'weight' => '-6',
        ),
        'views-opentools_tool-block_3' => array(
          'module' => 'views',
          'delta' => 'opentools_tool-block_3',
          'region' => 'featured',
          'weight' => '-5',
        ),
        'boxes-opentools_tool_wiki_title' => array(
          'module' => 'boxes',
          'delta' => 'opentools_tool_wiki_title',
          'region' => 'content',
          'weight' => '-45',
        ),
        'views-opentools_tool_wiki-block' => array(
          'module' => 'views',
          'delta' => 'opentools_tool_wiki-block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'boxes-opentools_tool_forum_title' => array(
          'module' => 'boxes',
          'delta' => 'opentools_tool_forum_title',
          'region' => 'triptych_first',
          'weight' => '-49',
        ),
        'views-opentools_action_links-block' => array(
          'module' => 'views',
          'delta' => 'opentools_action_links-block',
          'region' => 'triptych_first',
          'weight' => '-48',
        ),
        'views-opentools_tool_forum-block' => array(
          'module' => 'views',
          'delta' => 'opentools_tool_forum-block',
          'region' => 'triptych_middle',
          'weight' => '-10',
        ),
        'views-opentools_tool_forum-block_1' => array(
          'module' => 'views',
          'delta' => 'opentools_tool_forum-block_1',
          'region' => 'triptych_middle',
          'weight' => '-10',
        ),
        'views-opentools_tool_forum-block_2' => array(
          'module' => 'views',
          'delta' => 'opentools_tool_forum-block_2',
          'region' => 'triptych_last',
          'weight' => '-10',
        ),
        'views-opentools_tool_forum-block_3' => array(
          'module' => 'views',
          'delta' => 'opentools_tool_forum-block_3',
          'region' => 'triptych_last',
          'weight' => '-10',
        ),
        'views-opentools_tool_forum-block_4' => array(
          'module' => 'views',
          'delta' => 'opentools_tool_forum-block_4',
          'region' => 'triptych_last',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tools');
  $export['opentools_tool'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tools';
  $context->description = '';
  $context->tag = 'tools';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'tools/*' => 'tools/*',
        'tools' => 'tools',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'tools',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('tools');
  $export['tools'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tools_term_page';
  $context->description = '';
  $context->tag = 'tools';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'tools' => 'tools',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-tool_profile-block_4' => array(
          'module' => 'views',
          'delta' => 'tool_profile-block_4',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'views-tool_profile-block' => array(
          'module' => 'views',
          'delta' => 'tool_profile-block',
          'region' => 'featured',
          'weight' => '-9',
        ),
        'views-tool_profile-block_1' => array(
          'module' => 'views',
          'delta' => 'tool_profile-block_1',
          'region' => 'featured',
          'weight' => '-8',
        ),
        'views-tool_profile-block_2' => array(
          'module' => 'views',
          'delta' => 'tool_profile-block_2',
          'region' => 'featured',
          'weight' => '-7',
        ),
        'views-tool_profile-block_3' => array(
          'module' => 'views',
          'delta' => 'tool_profile-block_3',
          'region' => 'featured',
          'weight' => '-6',
        ),
        'boxes-tools_wiki_title' => array(
          'module' => 'boxes',
          'delta' => 'tools_wiki_title',
          'region' => 'content',
          'weight' => '-6',
        ),
        'views-tool_wiki-block' => array(
          'module' => 'views',
          'delta' => 'tool_wiki-block',
          'region' => 'content',
          'weight' => '-5',
        ),
        'views-wiki_node_images-block' => array(
          'module' => 'views',
          'delta' => 'wiki_node_images-block',
          'region' => 'content',
          'weight' => '-3',
        ),
        'boxes-tools_forum_title' => array(
          'module' => 'boxes',
          'delta' => 'tools_forum_title',
          'region' => 'triptych_first',
          'weight' => '-10',
        ),
        'views-455550642529cd8d064c3b7bf63cbbf5' => array(
          'module' => 'views',
          'delta' => '455550642529cd8d064c3b7bf63cbbf5',
          'region' => 'triptych_first',
          'weight' => '-8',
        ),
        'views-298a00bfac59913cdf15076c3dc7dd37' => array(
          'module' => 'views',
          'delta' => '298a00bfac59913cdf15076c3dc7dd37',
          'region' => 'triptych_first',
          'weight' => '-7',
        ),
        'views-forum_topic_type_actions-block' => array(
          'module' => 'views',
          'delta' => 'forum_topic_type_actions-block',
          'region' => 'triptych_middle',
          'weight' => '-10',
        ),
        'views-e585f6a74165fa7f8237ff14e471a818' => array(
          'module' => 'views',
          'delta' => 'e585f6a74165fa7f8237ff14e471a818',
          'region' => 'triptych_middle',
          'weight' => '-9',
        ),
        'views-tools_tool_forum_activity-block' => array(
          'module' => 'views',
          'delta' => 'tools_tool_forum_activity-block',
          'region' => 'triptych_middle',
          'weight' => '-8',
        ),
        'views-41f811dfbd6ec4751785bc1d370afaf6' => array(
          'module' => 'views',
          'delta' => '41f811dfbd6ec4751785bc1d370afaf6',
          'region' => 'triptych_last',
          'weight' => '-10',
        ),
        'views-066106861347aa16ecce2891593e581c' => array(
          'module' => 'views',
          'delta' => '066106861347aa16ecce2891593e581c',
          'region' => 'triptych_last',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('tools');
  $export['tools_term_page'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'topic_node';
  $context->description = '';
  $context->tag = 'forum';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'forum' => 'forum',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'notifications_ui-subscriptions' => array(
          'module' => 'notifications_ui',
          'delta' => 'subscriptions',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('forum');
  $export['topic_node'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'wiki';
  $context->description = '';
  $context->tag = 'wiki';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'wiki/*' => 'wiki/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'wiki',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('wiki');
  $export['wiki'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'wiki_node';
  $context->description = '';
  $context->tag = 'wiki';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'wiki' => 'wiki',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('wiki');
  $export['wiki_node'] = $context;

  return $export;
}
