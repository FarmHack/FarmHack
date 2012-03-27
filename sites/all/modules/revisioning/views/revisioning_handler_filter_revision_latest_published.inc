<?php
/**
 * @file
 *   Views filter to display in a 'Content revisions' view only the latest
 *   revision of each node. Does not work in a standard 'Content' view.
 */
class revisioning_handler_filter_revision_latest_published extends views_handler_filter_boolean_operator {

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
    $this->value_options = array(1 => t('Published only'));
  }

  /**
   * Override the query, in particular the WHERE clause.
   */
  function query() {
    $revisions_table = $this->ensure_my_table();
    $node_table = $this->query->ensure_table('node');

    $where_clause = "$node_table.vid = $revisions_table.vid AND $node_table.status=1";

    $this->query->add_where_expression($this->options['group'], $where_clause);
  }
}
