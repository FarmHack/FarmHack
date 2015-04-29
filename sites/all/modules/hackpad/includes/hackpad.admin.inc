<?php

/**
 * Settings form for Hackpad configuration.
 */
function hackpad_settings_form($form, $form_state) {
  $form['hackpad_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Hackpad integration'),
    '#default_value' => variable_get('hackpad_enabled', FALSE),
  );

  $form['hackpad_subdomain'] = array(
    '#type' => 'textfield',
    '#title' => t('Subdomain'),
    '#field_prefix' => 'https://',
    '#default_value' => variable_get('hackpad_subdomain', ''),
    '#field_suffix' => '.hackpad.com/',
    '#size' => 20,
    '#description' => t('Enter the Hackpad subdomain for your account.'),
    '#states' => array(
      'invisible' => array(
        ':input[name="hackpad_enabled"]' => array('checked' => FALSE),
      ),
      'required' => array(
        ':input[name="hackpad_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['hackpad_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#description' => t('Enter your Hackpad Client ID as provided at your Hackpad account page.'),
    '#default_value' => variable_get('hackpad_client_id', ''),
    '#states' => array(
      'invisible' => array(
        ':input[name="hackpad_enabled"]' => array('checked' => FALSE),
      ),
      'required' => array(
        ':input[name="hackpad_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['hackpad_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret'),
    '#description' => t('Enter your Hackpad Secret as provided at your Hackpad account page.'),
    '#default_value' => variable_get('hackpad_secret', ''),
    '#states' => array(
      'invisible' => array(
        ':input[name="hackpad_enabled"]' => array('checked' => FALSE),
      ),
      'required' => array(
        ':input[name="hackpad_enabled"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['hackpad_save_edit_node'] = array(
    '#type' => 'checkbox',
    '#title' => t('Save new nodes with Hackpads before allowing edits'),
    '#description' => t('When creating a new node with a Hackpad field, hide the Hackpad field. When the node has been saved, redirect to the node edit form and show the Hackpad field for editing.'),
    '#default_value' => variable_get('hackpad_save_edit_node', TRUE),
    '#states' => array(
      'invisible' => array(
        ':input[name="hackpad_enabled"]' => array('checked' => FALSE),
      ),
    ),
  );

  $form = system_settings_form($form);
  return $form;
}

/**
 * Validation callback for our settings form.
 */
function hackpad_settings_form_validate($form, &$form_state) {
  if ($form_state['values']['hackpad_enabled']) {
    $elements = array('hackpad_subdomain', 'hackpad_client_id', 'hackpad_secret');
    foreach ($elements as $element_name) {
      if (empty($form_state['values'][$element_name])) {
        form_error($form[$element_name], t('!name field is required.', array('!name' => $form[$element_name]['#title'])));
      }
    }
  }
}

/**
 * Form to test embedding a Hackpad.
 */
function hackpad_embed_form($form, &$form_state) {
  $form['pad_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Hackpad Pad ID'),
    '#description' => t('Enter the ID of an existing pad to load. A new pad will be created if it does not exist.'),
    '#default_value' => isset($form_state['values']['pad_id']) ? $form_state['values']['pad_id'] : '',
  );


  $form['load'] = array(
    '#type' => 'submit',
    '#value' => t('Load pad'),
  );

  if (isset($form_state['values']) && !empty($form_state['values']['pad_id'])) {
    $form['pad'] = array(
      '#type' => 'hackpad',
      '#pad_id' => $form_state['values']['pad_id'],
    );
  }

  return $form;
}

/**
 * Submit function for the embed testing form.
 */
function hackpad_embed_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

