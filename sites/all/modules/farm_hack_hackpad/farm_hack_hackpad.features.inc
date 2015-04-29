<?php
/**
 * @file
 * farm_hack_hackpad.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farm_hack_hackpad_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
