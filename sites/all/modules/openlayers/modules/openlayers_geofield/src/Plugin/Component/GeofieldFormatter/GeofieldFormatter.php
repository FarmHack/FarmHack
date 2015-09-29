<?php
/**
 * @file
 * Component: GeofieldFormatter.
 */

namespace Drupal\openlayers_geofield\Plugin\Component\GeofieldFormatter;
use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Plugin\Source\Vector\Vector;
use Drupal\openlayers\Types\Component;
use Drupal\openlayers\Types\LayerInterface;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class GeofieldFormatter.
 *
 * @OpenlayersPlugin(
 *  id = "GeofieldFormatter"
 * )
 */
class GeofieldFormatter extends Component {
  /**
   * {@inheritdoc}
   */
  public function optionsForm(&$form, &$form_state) {
    $form['options']['layer'] = array(
      '#type' => 'select',
      '#title' => t('Select the formatter layer'),
      '#default_value' => $this->getOption('editLayer'),
      '#options' => Openlayers::loadAllAsOptions('layer'),
    );
  }

  /**
   * {@inheritDoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($layer = $this->getOption('layer')) {
      $layer = Openlayers::load('layer', $layer);
      $import = array_merge($layer->getCollection()->getFlatList(), $import);
    }

    return $import;
  }

  /**
   * Returns the formatter layer object.
   *
   * @return LayerInterface|FALSE
   *   The layer assigned to this component.
   */
  public function getLayer() {
    $layer = $this->getObjects('layer');
    if ($layer = array_shift($layer)) {
      return ($layer instanceof LayerInterface) ? $layer : FALSE;
    }
    return FALSE;
  }

}
