<?php
/**
 * @file
 * Interface MapInterface.
 */

namespace Drupal\openlayers\Types;

/**
 * Interface MapInterface.
 */
interface MapInterface extends ObjectInterface {
  /**
   * Returns the id of this map.
   *
   * @return string
   *   The id of this map.
   */
  public function getId();

  /**
   * Build render array of a map.
   *
   * @param array $build
   *   The build array before being completed.
   *
   * @return array
   *   The render array.
   */
  public function build(array $build = array());

}
