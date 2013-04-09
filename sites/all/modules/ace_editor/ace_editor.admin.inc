<?php

	/**
	 * Implements hook_form().
	 *
	 * Settings form to configure the module.
	 */
	function ace_editor_settings_form($form, &$form_state) {
		$form = array();

		$filter_formats = filter_formats();
		$filter_formats_options = array();
		foreach($filter_formats as $key => $format_obj) {
			$filter_formats_options[$key] = $format_obj->name;
		}
		
		$form['explanation'] = array(
			'#markup' => t('These settings affect the editor only when used to edit HTML/PHP in your nodes or blocks.<br><br>'),
		);

		$form['ace_editor_filter_formats'] = array(
			'#type' => 'select',
			'#title' => t('Text formats'),
			'#description' => t('Select the text formats that will be using the editor.'),
			'#multiple' => TRUE,
			'#options' => $filter_formats_options,
			'#default_value' => variable_get('ace_editor_filter_formats', array()),
			'#size' => count($filter_formats_options),
			'#attributes' => array(
				'style' => 'min-width: 400px; margin-top: 10px;'
			),
		);

		$form['ace_editor_theme'] = array(
			'#title' => 'Editor theme',
			'#type' => 'select',
			'#options' => ace_editor_get_themes(),
			'#default_value' => variable_get('ace_editor_theme', 'twilight'),
			'#attributes' => array(
				'style' => 'min-width: 400px;'
			),
		);
		
		$form['ace_editor_default_syntax'] = array(
			'#title' => 'Editor default syntax',
			'#type' => 'select',
			'#options' => ace_editor_get_modes(),
			'#default_value' => variable_get('ace_editor_default_syntax', 'html'),
			'#attributes' => array(
				'style' => 'min-width: 400px;'
			),
		);

		$form['ace_editor_fontsize'] = array(
			'#type' => 'select',
			'#title' => t('Font size'),
			'#options' => array(
				'9pt' => '9pt',
				'10pt' => '10pt',
				'11pt' => '11pt',
				'12pt' => '12pt',
			),
			'#default_value' => variable_get('ace_editor_fontsize', '10pt'),
			'#attributes' => array(
				'style' => 'min-width: 100px;'
			),
		);

		$form['ace_editor_printmargin'] = array(
			'#type' => 'checkbox',
			'#title' => t('Show print margin'),
			'#default_value' => variable_get('ace_editor_printmargin'),
		);

		return system_settings_form($form);
	}


