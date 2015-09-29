<?php
/**
 * @file
 * Class Layer.
 */

namespace Drupal\openlayers\Types;
use Drupal\openlayers\Openlayers;

/**
 * Class Layer.
 */
abstract class Layer extends Object implements LayerInterface {
  /**
   * The array containing the options.
   *
   * @var array
   */
  protected $options = array();

  /**
   * Returns the source of this layer.
   *
   * @return SourceInterface|FALSE
   *   The source assigned to this layer.
   */
  public function getSource() {
    $source = $this->getObjects('source');
    if ($source = array_shift($source)) {
      return ($source instanceof SourceInterface) ? $source : FALSE;
    }
    return FALSE;
  }

  /**
   * Returns the style of this layer.
   *
   * @return StyleInterface|FALSE
   *   The style assigned to this layer.
   */
  public function getStyle() {
    $style = $this->getObjects('style');
    if ($style = array_shift($style)) {
      return ($style instanceof StyleInterface) ? $style : FALSE;
    }
    return FALSE;
  }

  /**
   * Set the source of this layer.
   *
   * @param SourceInterface $source
   *   The source object.
   */
  public function setSource(SourceInterface $source) {
    /* @var Source $source */
    $this->setOption('source', $source->getMachineName());
  }

  /**
   * Set the style of this layer.
   *
   * @param StyleInterface $style
   *   The style object.
   */
  public function setStyle(StyleInterface $style) {
    /* @var Style $style */
    $this->setOption('style', $style->getMachineName());
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    $import = parent::optionsToObjects();

    if ($style = $this->getOption('style')) {
      $import = array_merge($import, Openlayers::load('style', $style)->getCollection()->getFlatList());
    }

    if ($source = $this->getOption('source')) {
      $import = array_merge($import, Openlayers::load('source', $source)->getCollection()->getFlatList());
    }

    return $import;
  }
}
