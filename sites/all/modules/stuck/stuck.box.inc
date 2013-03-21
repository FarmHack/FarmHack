<?php
/**
 * @file
 * stuck.box.inc
 */

/**
 * Implements hook_default_box().
 */
function stuck_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'stuck';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'stuck';
  $box->options = array(
    'body' => array(
      'value' => '<div id="stuck">
<div id="stuck-inner">
<a href="/contact">Stuck?<br> Contact us.</a>
</div>
</div>
<style>

#stuck {
z-index:99999999;
position: fixed;
bottom: 20px;
right:0px;
width: 75px;
height: 75px;
background: #222;
border: #FFF solid; 
border-width: 3px 0px 3px 3px;
}

#stuck-inner {
padding: 6px 10px 0px;
}


#stuck a {
font-size: 14px;
color: #FFF;
}

#stuck a:hover {
color: red;
text-decoration: none;
}
</style>',
      'format' => 'php_code',
    ),
  );
  $export['stuck'] = $box;

  return $export;
}
