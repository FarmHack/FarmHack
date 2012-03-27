<?php
/**
 * @file
 * farmhack_users.box.inc
 */

/**
 * Implements hook_default_box().
 */
function farmhack_users_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'farmhack_user_stats';
  $box->plugin_key = 'simple';
  $box->title = 'Contributions';
  $box->description = 'FarmHack - User Stats';
  $box->options = array(
    'body' => array(
      'value' => '<?php

$view = views_get_view(\'farmhack_user_wiki_edits\');
$view->set_display(\'block\');    
$view->render();   
print "<p>" . "# of Wiki Edits: " . $view->total_rows . "</p>";

$view = views_get_view(\'farmhack_user_forum_topics\');
$view->set_display(\'block\');    
$view->render();   
print "<p># of Forum topics submitted: " . $view->total_rows . "</p>";


$view = views_get_view(\'farmhack_user_comments\');
$view->set_display(\'block\');
$view->render();   
print "<p># of Comments: " . $view->total_rows . "</p>";

?>',
      'format' => 'php_code',
    ),
    'additional_classes' => '',
  );
  $export['farmhack_user_stats'] = $box;

  return $export;
}
