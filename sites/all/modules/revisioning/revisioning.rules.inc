<?php

/**
 * @file Rules integration for Revisioning module.
 *
 * @addtogroup rules
 * @{
 */

/************************** Rules Events **************************************/

/**
 * Implements hook_rules_event_info() on behalf of the Revisioning module.
 */
function revisioning_rules_event_info() {
  $default = array(
    'group' => t('Revisioning'),
  //'module' => 'revisioning',
    'variables' => _revisioning_rules_event_arguments(),
  //'redirect' => TRUE,
  );
  $events = array(
    'revisioning_post_update' => $default + array(
      'label' => t('Content revision has been updated'),
    ),

    'revisioning_pre_publish' => $default + array(
      'label' => t('Content revision is going to be published'),
    ),
    'revisioning_post_publish' => $default + array(
      'label' => t('Pending revision has been published'),
    ),
    'revisioning_pre_revert' => $default + array(
      'label' => t('Content is going to be reverted to revision'),
    ),
    'revisioning_post_revert' => $default + array(
      'label' => t('Content has been reverted to revision'),
    ),
    'revisioning_post_unpublish' => $default + array(
      'label' => t('Content has been unpublished'),
    ),
    'revisioning_pre_delete' => $default + array(
      'label' => t('Content revision is going to be deleted'),
    ),
  );
  return $events;
}

/**
 * Returns arguments suitable for using it with a node.
 */
function _revisioning_rules_event_arguments() {
  return array(
    'node' => array(
      'type' => 'node',
      'label' => t('target revision of operation'),
    ),
    'current_revision' => array(
      'type' => 'revision',
      'label' => t('current revision of target content'),
      'handler' => 'revisioning_events_argument_current_revision'
    ),
    'author' => array(
      'type' => 'user',
      'label' => t('content author'),
      'handler' => 'rules_events_argument_node_author'
    ),
    'target_author' => array(
      'type' => 'user',
      'label' => t('target revision author'),
      'handler' => 'revisioning_events_argument_target_revision_author'
    ),
    'current_author' => array(
      'type' => 'user',
      'label' => t('current revision author'),
      'handler' => 'revisioning_events_argument_current_revision_author'
    ),
    'user' => array(
      'type' => 'user',
      'label' => t('acting user'),
      'handler' => 'rules_events_argument_global_user'
    ),
  );
}

/**
 * Current revision argument handler.
 */
function revisioning_events_argument_current_revision($arguments, $name, $info) {
  $node = $arguments['node'];
  $current_vid = $node->current_revision_id; // revisioning_get_current_node_revision_id($node->nid);
  if ($node->vid != $current_vid) {
    $current = node_load($node->nid, $current_vid);
    return $current;
  }
  return $node;
}

/**
 * Target revision author argument handler.
 */
function revisioning_events_argument_target_revision_author($arguments, $name, $info) {
  $node = $arguments['node'];
  return user_load($node->revision_uid);
}

/**
 * Current revision author argument handler.
 */
function revisioning_events_argument_current_revision_author($arguments, $name, $info) {
  $node = $arguments['node'];
  $current_vid = $node->current_revision_id; // revisioning_get_current_node_revision_id($node->nid);
  if ($node->vid != $current_vid) {
    $current = node_load($node->nid, $current_vid);
    return user_load($current->revision_uid);
  }
  return user_load($node->revision_uid);
}

/*************************** Rules Conditions ********************************/

/*
 * Implements hook_rules_condition_info().
 */
function revisioning_rules_condition_info() {
  $defaults = array(
    'group' => t('Revisioning'),
    'parameter' => array(
      'node' => array('type' => 'node', 'label' => t('Content')),
    ),
  );
  $items['revisioning_node_has_pending'] = $defaults + array(
    'label' => t('Content has pending revision'),
    'help' => t('Evaluates to TRUE, if the content has one or more pending revisions.'),
    'module' => 'revisioning',
  );
  $items['revisioning_condition_revision_is'] = $defaults + array(
    'label' => t('Content revision state'),
    'help' => t('Evaluates to TRUE, if the revision is in one of the selected states.'),
    'module' => 'revisioning',
    'base' => 'revisioning_condition_revision_is'
  );
  $items['revisioning_condition_revision_is']['parameter']['revision_type'] = array(
    'type' => 'list<text>',
    'label' => t('Is one of'),
    'options list' => 'revisioning_revision_states_all',
    'description' => t('The content state(s) to check for.'),
  );
  return $items;
}

/**
 * Wrapper function to always return all revisioning states
 */
function revisioning_revision_states_all() {
  return revisioning_revision_states();
}

/*
 * Condition: check for pending revisions of the node.
 */
function revisioning_node_has_pending($node, $settings) {
  revisioning_set_node_revision_info($node);
  return ($node->revision_moderation && $node->num_revisions == 1 && !$node->status) || ($num_pending = _revisioning_get_number_of_pending_revisions($node->nid)) > 0;
}

/*
 * Condition: check revision state.
 */
function revisioning_condition_revision_is($node, $settings) {
  revisioning_set_node_revision_info($node);
  // Should we return FALSE here if $node->revision_moderation is not set?
  $type = _revisioning_revision_is($node);
  return in_array($type, $settings);
}

/**
 * Label callback for "revisioning_revision_is" condition.
 */
function revisioning_condition_revision_is_label($settings, $argument_labels) {
  $names = array_intersect_key(revisioning_revision_states(), $settings['revision_type']);
  return t('Revision status of @node is: @type', $argument_labels + array('@type' => implode(t(' or '), $names)));
}

/**
 * Label callback for "revisioning_node_has_pending" condition.
 */
function revisioning_node_has_pending_label($settings, $argument_labels) {
  return t('Content "@node" has pending revision(s)', $argument_labels);
}

/*************************** Rules Actions ************************************/

/**
 * Implements hook_rules_action_info().
 */
function revisioning_rules_action_info() {
  $default = array(
    'group' => t('Revisioning'),
  );
  return array(
    'revisioning_rules_action_publish_latest' => $default + array(
      'label' => t('Publish the most recent pending revision'),
      'parameter' => array(
        'node' => array('type' => 'node', 'label' => t('content')),
      ),
    ),
    'revisioning_rules_action_load_current' => $default + array(
      'label' => t('Load current revision of content'),
      'parameter' => array(
        'node' => array('type' => 'node', 'label' => t('content')),
      ),
      'new variables' => array(
        'loaded_current_revision' => array(
          'type' => 'node',
          'label' => t('Loaded current revision of content'),
          'save' => FALSE,
          'label callback' => 'revisioning_rules_loaded_current_label',
        ),
      ),
    ),
  );
}

/**
 * Label callback for "revisioning_rules_action_load_current" action.
 * @obsolete ?
 */
function revisioning_rules_action_load_current_label($settings, $argument_labels) {
  return t('Load current revision of "@node"', $argument_labels);
}

/**
 * Label callback for "loaded_current_revision" variable.
 * @obsolete ?
 */
function revisioning_rules_loaded_current_label($settings, $argument_labels) {
  return t('Loaded current revision of "@node"', $argument_labels);
}

/**
 * Action: load current revision of provided node.
 */
function revisioning_rules_action_load_current($node) {
  $current_vid = $node->current_revision_id; // revisioning_get_current_node_revision_id($node->nid);
  if ($node->vid != $current_vid) {
    $current = node_load($node->nid, $current_vid);
    return array('loaded_current_revision' => $current);
  }
  return array('loaded_current_revision' => $node);
}

/**
 * Action: publish most recent pending revision.
 */
function revisioning_rules_action_publish_latest($node) {
  _revisioning_publish_latest_revision($node);
}

/**
 * @}
 */
