<?php
/**
 * @file
 * farmhack_prevent_dissappear_form.box.inc
 */

/**
 * Implements hook_default_box().
 */
function farmhack_prevent_dissappear_form_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'farmhack_prevent_dissappear_form';
  $box->plugin_key = 'simple';
  $box->title = 'Node Form Disappears Bandaid';
  $box->description = 'Code to keep node form from disappearing when removing images.';
  $box->options = array(
    'body' => array(
      'value' => '<script type="text/javascript">
setInterval(\'jQuery("#block-system-main").show()\', 250);
</script>',
      'format' => 'php_code',
    ),
  );
  $export['farmhack_prevent_dissappear_form'] = $box;

  return $export;
}
