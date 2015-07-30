<?php
/**
 * @file
 * template.php
 */
function bootstrap_farmhack_apachesolr_search_page_alter(array &$build, array $search_page) {
  if (arg(0) == "library" && arg(1) == "tools") {
    // Manage the loading of the library/tools page
    drupal_add_js( '
      jQuery(window).load(function() {
        jQuery(".spinner").hide()
        jQuery(".search-results").fadeIn()
        jQuery(".search-results").packery({ itemSelector: ".item",  gutter: 10 }) 
      })
      document.addEventListener("DOMContentLoaded", function(event) { 
        jQuery(".page-header").text("Tool Library")
        jQuery(\'#block-system-main h2\').hide()
        jQuery(".search-results").hide()
        jQuery(".search-results").before("<center><img class=\"spinner\" src=\"/sites/all/themes/bootstrap_farmhack/images/spinner.gif\" align=\"center\"></center>")
      })
    ', 'inline');
  }
}


function bootstrap_farmhack_preprocess_search_result(&$vars) {
  if (arg(0) == "library" && arg(1) == "tools") {
    $vars['nid'] = $vars['result']['node']->entity_id;
    $vars['url'] = drupal_get_path_alias('node/' . $vars['nid']);
    $vars['node'] = node_load($vars['result']['node']->entity_id);
    $vars['picture'] = file_create_url($vars['node']->field_tool_image['und'][0]['uri']);
    $vars['description'] = $vars['node']->field_tool_description['und'][0]['value'];
    $vars['theme_hook_suggestions'][] = 'search_result__tool';
  }
}

