<?php
/**
 * @file
 * Class Source.
 */

namespace Drupal\openlayers\Types;
use Drupal\openlayers\Openlayers;

/**
 * Class Source.
 */
abstract class Source extends Object implements SourceInterface {
  /**
   * The array containing the options.
   *
   * @var array
   */
  protected $options;

}
