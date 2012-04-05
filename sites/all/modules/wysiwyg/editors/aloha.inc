<?php

/**
 * @file
 * Editor integration functions for Aloha editor.
 */

/**
 * Plugin implementation of hook_editor().
 */
function wysiwyg_aloha_editor() {
  $editor['aloha'] = array(
    'title' => 'Aloha editor',
    'vendor url' => 'http://www.aloha-editor.org/',
    'download url' => 'http://www.aloha-editor.org/',
    'library path' => wysiwyg_get_path('aloha') . '/aloha',
    'libraries' => array(
      'min-bundled' => array(
        'title' => 'Minified (bundled with jQuery + ExtJS)',
        'files' => array(
          'lib/aloha.js' => array('scope' => 'footer', 'group' => JS_LIBRARY),
        ),
      ),
    ),
    'version callback' => 'wysiwyg_aloha_version',
    'load callback' => 'wysiwyg_aloha_load',
    'settings callback' => 'wysiwyg_aloha_settings',
    'plugin callback' => 'wysiwyg_aloha_plugins',
    'versions' => array(
      '0.10.0' => array(
        'js files' => array('aloha.js'),
      ),
    ),
  );
  return $editor;
}

/**
 * Detect editor version.
 *
 * @param $editor
 *   An array containing editor properties as returned from hook_editor().
 *
 * @return
 *   The installed editor version.
 */
function wysiwyg_aloha_version($editor) {
  $library = $editor['library path'] . '/package.json';
  if (!file_exists($library)) {
    return;
  }
  $library = fopen($library, 'r');
  $max_lines = 3;
  while ($max_lines && $line = fgets($library, 60)) {
    if (preg_match('@"version"\: "([0-9\._-]+)",@', $line, $version)) {
      fclose($library);
      return $version[1];
    }
    $max_lines--;
  }
  fclose($library);
}

/**
 * Perform additional actions upon loading this editor.
 *
 * @param $editor
 *   A processed hook_editor() array of editor properties.
 * @param $library
 *   The internal library name (array key) to use.
 */
function wysiwyg_aloha_load($editor, $library) {
  drupal_add_css($editor['library path'] . '/css/aloha.css');
  // It appears that it is impossible to have 2 instances with different controls,
  // as we need this information before aloha loads
  $data = "Aloha = window.Aloha || {};";
  $data .= "Aloha.settings = {";
  $data .= "  'baseUrl': '/" . wysiwyg_get_path('aloha') . "/aloha/lib',";
  $data .= "  'plugins': {";
  $data .= "    'load': 'common/format, common/table, common/list, common/link'";
  $data .= "  }";
  $data .= "}";
  drupal_add_js($data, array('type' => 'inline', 'group' => JS_LIBRARY, 'weight' => JS_LIBRARY));
}

/**
 * Return runtime editor settings for a given wysiwyg profile.
 *
 * @param $editor
 *   A processed hook_editor() array of editor properties.
 * @param $config
 *   An array containing wysiwyg editor profile settings.
 * @param $theme
 *   The name of a theme/GUI/skin to use.
 *
 * @return
 *   A settings array to be populated in
 *   Drupal.settings.wysiwyg.configs.{editor}
 */
function wysiwyg_aloha_settings($editor, $config, $theme) {
  $settings = array(
    'baseUrl' => base_path() . $editor['library path'] . '/lib',
    'ribbon' => FALSE,
    'logLevels' => array(
      'error' => TRUE,
      'warn' => TRUE,
      'info' => FALSE,
      'debug' => FALSE,
    ),
    'errorhandling' => FALSE,
    'plugins' => array(
      // @todo: This doesn't really do anything, @see wysiwyg_aloha_load().
      'load' => 'common/format, common/table, common/list, common/link',
    ),
  );

  return $settings;
}

/**
 * Return internal plugins for this editor; semi-implementation of hook_wysiwyg_plugin().
 */
function wysiwyg_aloha_plugins($editor) {
  return array(
    'default' => array(
      'buttons' => array(
        'Format' => t('HTML block format'),
        'List' => t('List'),
        'Link' => t('Link'),
        'LinkChecker' => t('LinkChecker'),
        'HighlightEditables' => t('Highlight Editables'),
        'Table' => t('Table'),
        'Abbr' => t('Abbreviation'),
        'Paste' => t('Paste'),
        'TOC' => t('TOC'),
      ),
      'internal' => TRUE,
    ),
  );
}

