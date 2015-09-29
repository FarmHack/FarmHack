<?php
/**
 * @file
 * CTools Export UI plugin definition for maps.
 */

/**
 * CTools Export UI plugin definition.
 */
function openlayers_ui_OpenlayersMaps_ctools_export_ui() {
  return array(
    'schema' => 'openlayers_maps',
    'access' => 'administer openlayers',
    'menu' => array(
      'menu prefix' => 'admin/structure/openlayers',
      'menu item' => 'maps',
      'menu title' => 'Maps',
      'menu description' => 'Administer Openlayers maps presets.',
    ),

    'handler' => array(
      'class' => '\\Drupal\\openlayers_ui\\UI\\OpenlayersMaps',
      'file' => 'OpenlayersMaps.php',
    ),

    'use wizard' => TRUE,
    'form info' => array(
      'order' => array(
        'start' => t('Administrative settings'),
        'settings' => t('Map settings'),
        'layers' => t('Layers'),
        'controls' => t('Controls'),
        'interactions' => t('Interactions'),
        'components' => t('Components'),
        'preview' => t('Preview'),
      ),
      'forms' => array(
        'start' => array(
          'form id' => 'openlayers_map_form_start',
        ),
        'settings' => array(
          'form id' => 'openlayers_map_form_settings',
        ),
        'layers' => array(
          'form id' => 'openlayers_map_form_layers',
        ),
        'controls' => array(
          'form id' => 'openlayers_map_form_controls',
        ),
        'interactions' => array(
          'form id' => 'openlayers_map_form_interactions',
        ),
        'components' => array(
          'form id' => 'openlayers_map_form_components',
        ),
        'preview' => array(
          'form id' => 'openlayers_map_form_preview',
        ),
      ),
      'wrapper' => 'openlayers_objects_ui_form_wrapper',
    ),

    'export' => array(
      'admin_title' => 'name',
      'admin_description' => 'description',
    ),

    'title singular' => t('map'),
    'title plural' => t('maps'),
    'title singular proper' => t('Openlayers map preset'),
    'title plural proper' => t('Openlayers maps presets'),

    'strings' => array(
      'confirmation' => array(
        'add' => array(
          'success' => t('Map saved.'),
        ),
        'delete' => array(
          'success' => t('Map was deleted.'),
        ),
      ),
    ),
  );
}

/**
 * Map base config form handler.
 */
function openlayers_map_form_start($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form($form, $form_state);
  return $form;
}

/**
 * Map base config form validation handler.
 */
function openlayers_map_form_start_validate($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form_validate($form, $form_state);
}

/**
 * Map base config form submit handler.
 */
function openlayers_map_form_start_submit($form, &$form_state) {
  $class = new Drupal\openlayers_ui\UI\OpenlayersMaps();
  $class->init($form_state['plugin']);
  $class->edit_form_submit($form, $form_state);
}

/**
 * Map settings config form handler.
 */
function openlayers_map_form_settings($form, &$form_state) {
  if (!isset($form_state['item']->factory_service)) {
    $form_state['item']->factory_service = 'openlayers.Map:OLMap';
  }
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == TRUE) {
    $map->optionsForm($form, $form_state);
    $form['options']['#tree'] = TRUE;
  }

  return $form;
}

/**
 * Map settings config form validation handler.
 */
function openlayers_map_form_settings_validate($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);
  $map->optionsFormValidate($form, $form_state);
}

/**
 * Map settings config form submit handler.
 */
function openlayers_map_form_settings_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  if (empty($map->factory_service)) {
    $map->factory_service = 'openlayers.Map:OLMap';
  }

  $map->optionsFormSubmit($form, $form_state);
}

/**
 * Map layers config form handler.
 */
function openlayers_map_form_layers($form, &$form_state) {
  $all_layers = \Drupal\openlayers\Openlayers::loadAllExportable('Layer');
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == FALSE) {
    return;
  }

  array_walk($all_layers, function($object) {
    $object->weight = 0;
    $object->enabled = 0;
  });

  foreach ($map->getOption('layers', array()) as $weight => $layer) {
    /* @var Drupal\openlayers\Types\Layer $layer */
    $layer = \Drupal\openlayers\Openlayers::load('layer', $layer);
    $all_layers[$layer->getMachineName()]->weight = $weight;
    $all_layers[$layer->getMachineName()]->enabled = 1;
  }

  uasort($all_layers, function($a, $b) {
    if ($a->enabled > $b->enabled) {
      return -1;
    }
    elseif ($a->enabled < $b->enabled) {
      return 1;
    }
    if ($a->weight < $b->weight) {
      return -1;
    }
    elseif ($a->weight > $b->weight) {
      return 1;
    }
    if ($a->machine_name < $b->machine_name) {
      return -1;
    }
    elseif ($a->machine_name > $b->machine_name) {
      return 1;
    }
    return 0;
  });

  $data = array();
  $i = 0;
  /* @var \Drupal\openlayers\Types\Layer $layer */
  foreach ($all_layers as $machine_name => $layer) {
    $data[$machine_name] = array(
      'name' => $layer->name,
      'machine_name' => $layer->machine_name,
      'factory_service' => $layer->factory_service,
      'weight' => $i++,
      'enabled' => isset($layer->enabled) ? $layer->enabled : 0,
      'default' => 1,
      'style' => isset($layer->options['style']) ? $layer->options['style'] : NULL,
    );
  }

  $rows = array();
  $row_elements = array();
  foreach ($data as $id => $entry) {
    $rows[$id] = array(
      'data' => array(
        array('class', array('entry-cross')),
        array(
          'data' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['weight'],
            '#parents' => array('layers', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          ),
        ),
        array(
          'data' => array(
            '#type' => 'hidden',
            '#default_value' => $entry['machine_name'],
            '#parents' => array('layers', $id, 'machine_name'),
          ),
        ),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enabled'],
            '#parents' => array('layers', $id, 'enabled'),
          ),
        ),
        array(
          'data' => array(
            '#type' => 'select',
            '#title' => t('Style'),
            '#title_display' => 'invisible',
            '#options' => array('' => t('- Select a Style -')) + \Drupal\openlayers\Openlayers::loadAllAsOptions('style'),
            '#default_value' => $entry['style'],
            '#parents' => array('layers', $id, 'style'),
          ),
        ),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['factory_service']),
        l(t('Edit'), 'admin/structure/openlayers/layers/list/' . $entry['machine_name'] . '/edit/options',
          array(
            'query' => array(
              'destination' => current_path(),
            ),
          )
        ),
      ),
      'class' => array('draggable'),
    );
    // Build rows of the form elements in the table.
    $row_elements[$id] = array(
      'weight' => &$rows[$id]['data'][1]['data'],
      'enabled' => &$rows[$id]['data'][2]['data'],
      'style' => &$rows[$id]['data'][3]['data'],
      'machine_name' => &$rows[$id]['data'][4]['data'],
    );
  }

  // Add the table to the form.
  $form['layers']['table_layers'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weigth field and the cross.
      array('data' => NULL, 'colspan' => 2),
      array('data' => t('Enabled'), 'colspan' => 2),
      array('data' => t('Style'), 'colspan' => 1),
      t('Name'),
      t('Machine name'),
      t('Factory service'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-layers'),
  );
  drupal_add_tabledrag('entry-order-layers', 'order', 'sibling', 'entry-order-weight');

  return $form;
}

/**
 * Map layers config form submit handler.
 */
function openlayers_map_form_layers_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $layers_enabled = array_filter($form_state['values']['layers'], function($item) {
    return (bool) $item['enabled'];
  });

  uasort($layers_enabled, function($a, $b) {
    return $a['weight'] - $b['weight'];
  });

  foreach ($layers_enabled as $id => $data) {
    //Update the layer style.
    if (($layer = \Drupal\openlayers\Openlayers::load('layer', $data['machine_name'])) == TRUE) {
      if (!empty($data['style'])) {
        $layer->setOption('style', $data['style']);
      }
      else {
        $layer->clearOption('style');
      }
      \Drupal\openlayers\Openlayers::save($layer);
    }
  }

  $map->setOption('layers', array_keys($layers_enabled));

  $form_state['item'] = $map->getExport();
}

/**
 * Map controls config form handler.
 */
function openlayers_map_form_controls($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);
  $all_controls = \Drupal\openlayers\Openlayers::loadAllExportable('Control');

  if (!isset($form_state['item']->options['controls'])) {
    $form_state['item']->options['controls'] = array();
  }

  array_walk($all_controls, function($object) {
    $object->weight = 0;
    $object->enabled = 0;
  });

  foreach ($map->getObjects('control') as $control) {
    /* @var Drupal\openlayers\Types\Control $control */
    $all_controls[$control->getMachineName()]->weight = $control->getWeight();
    $all_controls[$control->getMachineName()]->enabled = 1;
  }

  uasort($all_controls, function($a, $b) {
    if ($a->enabled > $b->enabled) {
      return -1;
    }
    elseif ($a->enabled < $b->enabled) {
      return 1;
    }
    if ($a->weight < $b->weight) {
      return -1;
    }
    elseif ($a->weight > $b->weight) {
      return 1;
    }
    if ($a->machine_name < $b->machine_name) {
      return -1;
    }
    elseif ($a->machine_name > $b->machine_name) {
      return 1;
    }
    return 0;
  });

  $data = array();
  $i = 0;
  foreach ($all_controls as $machine_name => $control) {
    $data[$machine_name] = array(
      'name' => $control->name,
      'machine_name' => $control->machine_name,
      'description' => $control->description,
      'weight' => $i++,
      'enabled' => (int) $control->enabled,
    );
  }

  $rows = array();
  $row_elements = array();
  foreach ($data as $id => $entry) {
    $rows[$id] = array(
      'data' => array(
        array(
          'class',
          array(
            'entry-cross'
          )
        ),
        array(
          'data' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['weight'],
            '#parents' => array('controls', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          )
        ),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enabled'],
            '#parents' => array('controls', $id, 'enabled'),
          )
        ),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['description']),
        l(t('Edit'), 'admin/structure/openlayers/controls/list/' . $entry['machine_name'] . '/edit',
          array(
            'query' => array(
              'destination' => current_path(),
            ),
          )
        ),
      ),
      'class' => array('draggable'),
    );
    // Build rows of the form elements in the table.
    $row_elements[$id] = array(
      'weight' => &$rows[$id]['data'][1]['data'],
      'enabled' => &$rows[$id]['data'][2]['data'],
    );
  }

  $form['options']['#tree'] = TRUE;

  // Add the table to the form.
  $form['controls']['table_controls'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weigth field and the cross.
      array('data' => NULL, 'colspan' => 2),
      t('Enabled'),
      t('Name'),
      t('Machine name'),
      t('Description'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-controls'),
  );
  drupal_add_tabledrag('entry-order-controls', 'order', 'sibling', 'entry-order-weight');

  return $form;
}

/**
 * Map controls config form submit handler.
 */
function openlayers_map_form_controls_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $controls_enabled = array_filter($form_state['values']['controls'], function($item) {
    return (bool) $item['enabled'];
  });

  uasort($controls_enabled, function($a, $b) {
    return $a['weight'] - $b['weight'];
  });

  $map->setOption('controls', array_keys($controls_enabled));

  $form_state['item'] = $map->getExport();
}

/**
 * Map interactions config form handler.
 */
function openlayers_map_form_interactions($form, &$form_state) {
  $all_interactions = \Drupal\openlayers\Openlayers::loadAllExportable('Interaction');

  $header = array(
    'name' => t('Name'),
    'machine_name' => t('Machine name'),
    'description' => t('Description'),
    'operations' => t('Operations'),
  );

  $rows = array();
  foreach ($all_interactions as $machine_name => $interaction) {
    $rows[$machine_name] = array(
      'name' => $interaction->name,
      'machine_name' => $interaction->machine_name,
      'description' => $interaction->description,
      'operations' => l(
        t('Edit'),
        'admin/structure/openlayers/interactions/list/' . $machine_name . '/edit/options',
        array(
          'query' => array(
            'destination' => current_path(),
          ),
        )
      ),
    );
  }

  $form['options']['#tree'] = TRUE;

  if (!isset($form_state['item']->options['interactions'])) {
    $form_state['item']->options['interactions'] = array();
  }

  $form['options']['interactions'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $rows,
    '#default_value' => drupal_map_assoc($form_state['item']->options['interactions']),
  );

  return $form;
}

/**
 * Map interactions config form submit handler.
 */
function openlayers_map_form_interactions_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $interactions_enabled = array_filter($form_state['values']['options']['interactions']);

  $map->setOption('interactions', array_keys($interactions_enabled));

  $form_state['item'] = $map->getExport();
}

/**
 * Map components config form handler.
 */
function openlayers_map_form_components($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);
  $all_components = \Drupal\openlayers\Openlayers::loadAllExportable('Component');

  array_walk($all_components, function($object) {
    $object->weight = 0;
    $object->enabled = 0;
  });

  foreach ($map->getObjects('component') as $component) {
    /* @var Drupal\openlayers\Types\Component $component */
    $all_components[$component->getMachineName()]->weight = $component->getWeight();
    $all_components[$component->getMachineName()]->enabled = 1;
  }

  uasort($all_components, function($a, $b) {
    if ($a->enabled > $b->enabled) {
      return -1;
    }
    elseif ($a->enabled < $b->enabled) {
      return 1;
    }
    if ($a->weight < $b->weight) {
      return -1;
    }
    elseif ($a->weight > $b->weight) {
      return 1;
    }
    if ($a->machine_name < $b->machine_name) {
      return -1;
    }
    elseif ($a->machine_name > $b->machine_name) {
      return 1;
    }
    return 0;
  });

  $data = array();
  $i = 0;
  foreach ($all_components as $machine_name => $component) {
    $data[$machine_name] = array(
      'name' => $component->name,
      'machine_name' => $component->machine_name,
      'description' => $component->description,
      'weight' => $i++,
      'enabled' => $component->enabled,
    );
  }

  $rows = array();
  $row_elements = array();
  foreach ($data as $id => $entry) {
    $rows[$id] = array(
      'data' => array(
        array('class', array('entry-cross')),
        array(
          'data' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['weight'],
            '#parents' => array('components', $id, 'weight'),
            '#attributes' => array(
              'class' => array('entry-order-weight'),
            ),
          )),
        array(
          'data' => array(
            '#type' => 'checkbox',
            '#title' => t('Enable'),
            '#title_display' => 'invisible',
            '#default_value' => $entry['enabled'],
            '#parents' => array('components', $id, 'enabled'),
          )),
        check_plain($entry['name']),
        check_plain($entry['machine_name']),
        check_plain($entry['description']),
        l(t('Edit'), 'admin/structure/openlayers/components/list/' . $entry['machine_name'] . '/edit',
          array(
            'query' => array(
              'destination' => current_path(),
            ),
          )
        ),
      ),
      'class' => array('draggable'),
    );
    // Build rows of the form elements in the table.
    $row_elements[$id] = array(
      'weight' => &$rows[$id]['data'][1]['data'],
      'enabled' => &$rows[$id]['data'][2]['data'],
    );
  }

  $form['options']['#tree'] = TRUE;

  // Add the table to the form.
  $form['components']['table_components'] = array(
    '#theme' => 'table',
    // The row form elements need to be processed and build,
    // therefore pass them as element children.
    'elements' => $row_elements,
    '#header' => array(
      // We need two empty columns for the weight field and the cross.
      array('data' => NULL, 'colspan' => 2),
      t('Enabled'),
      t('Name'),
      t('Machine name'),
      t('Description'),
      t('Operations'),
    ),
    '#rows' => $rows,
    '#empty' => t('There are no entries available.'),
    '#attributes' => array('id' => 'entry-order-components'),
  );
  drupal_add_tabledrag('entry-order-components', 'order', 'sibling', 'entry-order-weight');

  return $form;
}

/**
 * Map components config form submit handler.
 */
function openlayers_map_form_components_submit($form, &$form_state) {
  $map = \Drupal\openlayers\Openlayers::load('map', $form_state['item']);

  $components_enabled = array_filter($form_state['values']['components'], function($item) {
    return (bool) $item['enabled'];
  });

  uasort($components_enabled, function($a, $b) {
    return $a['weight'] - $b['weight'];
  });

  $map->setOption('components', array_keys($components_enabled));

  $form_state['item'] = $map->getExport();
}

/**
 * Map preview form handler.
 */
function openlayers_map_form_preview($form, &$form_state) {
  if (($map = \Drupal\openlayers\Openlayers::load('Map', $form_state['item'])) == TRUE) {
    $form['preview'] = $map->build();
  }
  return $form;
}

/**
 * Map preview config form submit handler.
 */
function openlayers_map_form_preview_submit($form, &$form_state) {

}
