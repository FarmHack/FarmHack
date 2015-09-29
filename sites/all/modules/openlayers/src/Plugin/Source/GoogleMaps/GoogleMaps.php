<?php
/**
 * @file
 * Google maps API integration based on the example here:
 * http://openlayers.org/en/v3.0.0/examples/google-map.html
 * http://bl.ocks.org/elemoine/e82c7dd4b1d0ef45a9a4
 */

namespace Drupal\openlayers\Plugin\Source\GoogleMaps;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Types\ObjectInterface;
use Drupal\openlayers\Types\Source;

/**
 * Class GoogleMaps.
 *
 * @OpenlayersPlugin(
 *  id = "GoogleMaps"
 * )
 */
class GoogleMaps extends Source {

  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $layer_types = array(
      'ROADMAP',
      'SATELLITE',
      'HYBRID',
      'TERRAIN',
    );

    $form['options']['key'] = array(
      '#title' => t('Key'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('key', ''),
    );
    $form['options']['client'] = array(
      '#title' => t('Client'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('client', ''),
    );
    $form['options']['channel'] = array(
      '#title' => t('Channel'),
      '#type' => 'textfield',
      '#default_value' => $this->getOption('client', ''),
    );
    $form['options']['mapTypeId'] = array(
      '#title' => t('Mapy Type'),
      '#type' => 'select',
      '#default_value' => $this->getOption('mapTypeId', 'ROADMAP'),
      '#options' => array_combine($layer_types, $layer_types),
    );
    $form['options']['sensor'] = array(
      '#title' => t('Sensor'),
      '#type' => 'checkbox',
      '#default_value' => $this->getOption('sensor', FALSE),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $map = NULL) {
    $build['openlayers']['map-container']['gmap'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'gmap-' . $map->getId(),
        'class' => array('openlayers', 'gmap-map'),
        'style' => $build['openlayers']['map-container']['#attributes']['style'],
      ),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return TRUE;
  }
}
