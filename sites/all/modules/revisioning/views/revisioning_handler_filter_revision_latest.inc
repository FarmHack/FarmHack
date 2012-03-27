<?php
/**
 * @file
 *   Views filter to display in a 'Content revisions' view only
 *   published revisions. Does not work in a standard 'Content' view.
 */
class revisioning_handler_filter_revision_latest extends views_handler_filter_boolean_operator {

  function construct() {
    parent::construct();
    $this->value_value = t('Revisions');
  }

  function access() {
    return user_access('access content');
  }

  function can_expose() {
    return TRUE;
  }

  function expose_form(&$form, &$form_state) {
    $form['expose']['required'] = array(
      '#type' => 'value',
      '#value' => FALSE,
    );
  }

  function get_value_options() {
    $this->value_options = array(1 => t('Latest only'));
  }

  /**
   * Override the query, in particular the WHERE clause.
   */
  function query() {
    $revisions_table = $this->ensure_my_table();
    $node_table = $this->query->ensure_table('node');

    // The subquery selects the maximum revision ID (vid) for a given node ID
    // (nid). This is guaranteed to be the latest revision, because vids are
    // assigned chronologically.
    $max_vid_subquery = "SELECT MAX(vid) FROM $revisions_table WHERE $revisions_table.nid = $node_table.nid";

    $where_clause = "$revisions_table.vid = ($max_vid_subquery)";
    $this->query->add_where_expression($this->options['group'], $where_clause);
  }
}
