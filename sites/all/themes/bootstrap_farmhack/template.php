<?php
/**
 * @file
 * template.php
 */
function bootstrap_farmhack_apachesolr_search_page_alter(array &$build, array $search_page) {
  if (arg(0) == "library" && arg(1) == "tools") {
    // Manage the loading of the library/tools page
    drupal_add_css(drupal_get_path('theme', 'bootstrap_farmhack'). '/css/library-tools.css');
    drupal_add_js( '
      var spinnerOpts = {
        lines: 13 // The number of lines to draw
      , length: 28 // The length of each line
      , width: 14 // The line thickness
      , radius: 42 // The radius of the inner circle
      , scale: .25 // Scales overall size of the spinner
      , corners: 1 // Corner roundness (0..1)
      , color: \'#000\' // #rgb or #rrggbb or array of colors
      , opacity: 0.25 // Opacity of the lines
      , rotate: 0 // The rotation offset
      , direction: 1 // 1: clockwise, -1: counterclockwise
      , speed: 1 // Rounds per second
      , trail: 60 // Afterglow percentage
      , fps: 20 // Frames per second when using setTimeout() as a fallback for CSS
      , zIndex: 2e9 // The z-index (defaults to 2000000000)
      , className: \'spinner\' // The CSS class to assign to the spinner
      , top: \'50%\' // Top position relative to parent
      , left: \'50%\' // Left position relative to parent
      , shadow: false // Whether to render a shadow
      , hwaccel: false // Whether to use hardware acceleration
      , position: \'absolute\' // Element positioning
      }
      jQuery(window).load(function() {
        jQuery(".spinner").hide()
        jQuery(".search-results").fadeIn()
        jQuery(".search-results").packery({ itemSelector: ".item",  gutter: 10 }) 
      })
      document.addEventListener("DOMContentLoaded", function(event) { 
        var target = document.getElementById(\'block-system-main\')
        var spinner = new Spinner(spinnerOpts).spin(target);
        jQuery(".page-header").text("Tool Library")
        jQuery(\'#block-system-main h2\').hide()
        jQuery(".search-results").hide()
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

