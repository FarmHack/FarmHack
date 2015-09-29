<?php
/**
 * @file
 * Class Collection.
 */

namespace Drupal\openlayers\Types;

use Drupal\openlayers\Component\Annotation\OpenlayersPlugin;
use Drupal\Component\Plugin\PluginBase;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Object;


/**
 * Class Collection.
 *
 * @OpenlayersPlugin(
 *   id = "Collection"
 * )
 */
class Collection extends PluginBase {

  /**
   * @var ObjectInterface[] $objects
   *   List of objects in this collection. The items have to be instances of
   *   \Drupal\openlayers\Types\Object.
   */
  protected $objects = array();

  /**
   * Import a flat list of Openlayers Objects.
   *
   * @param ObjectInterface[] $import
   *   The array of objects to import.
   */
  public function import(array $import = array()) {
    foreach ($import as $object) {
      /* @var Object $object */
      $this->merge($object->getCollection());
    }
  }

  /**
   * Add object to this collection.
   *
   * @param ObjectInterface $object
   *   Object instance to add to this collection.
   */
  public function append(ObjectInterface $object) {
    $object->setWeight($object->getWeight() + count($this->objects));
    $this->objects[$object->getType() . '_' . $object->getMachineName()] = $object;
  }

  /**
   * Add object to this collection.
   *
   * @param ObjectInterface $object
   *   Object instance to add to this collection.
   */
  public function prepend(ObjectInterface $object) {
    $this->objects = array_merge(array($object->getType() . '_' . $object->getMachineName() => $object), $this->objects);
  }

  /**
   * Remove object from this collection.
   *
   * @param ObjectInterface $object
   *   Object instance to remove from this collection.
   */
  public function delete(ObjectInterface $object) {
    unset($this->objects[$object->getType() . '_' . $object->getMachineName()]);
  }

  /**
   * Remove object type.
   *
   * @param array $types
   *   The types of objects to remove.
   */
  public function clear(array $types = array()) {
    foreach ($types as $type) {
      unset($this->objects[$type]);
    }
  }

  /**
   * Returns an array with all the attachments of the collection objects.
   *
   * @return array
   *   Array with all the attachments of the collection objects.
   */
  public function getAttached() {
    $attached = array();
    foreach ($this->getFlatList() as $object) {
      $object_attached = $object->attached() + array(
        'js' => array(),
        'css' => array(),
        'library' => array(),
        'libraries_load' => array(),
      );
      foreach (array('js', 'css', 'library', 'libraries_load') as $type) {
        foreach ($object_attached[$type] as $data) {
          if (isset($attached[$type])) {
            array_unshift($attached[$type], $data);
          }
          else {
            $attached[$type] = array($data);
          }
        }
      }
    }
    return $attached;
  }

  /**
   * Array with all the JS settings of the collection objects.
   *
   * @return array
   *   All the JS settings of the collection objects.
   */
  public function getJS() {
    $settings = array();

    foreach ($this->getFlatList() as $object) {
      $settings[$object->getType()][] = $object->getJS();
    }

    return array_change_key_case($settings, CASE_LOWER);
  }

  /**
   * Array with all the collection objects.
   *
   * @param string $type
   *   Type to filter for. If set only a list with objects of this type is
   *   returned.
   *
   * @return array
   *   List of objects of this collection or list of a specific type of objects.
   */
  public function getObjects($type = NULL) {
    if ($type == NULL) {
      $list = array();
      foreach ($this->getFlatList() as $object) {
        $list[$object->getType()][] = $object;
      }
      return array_change_key_case($list, CASE_LOWER);
    }

    return $this->getFlatList(array($type));
  }

  /**
   * Return an array with all the collection objects.
   *
   * @param array $types
   *   Array of type to filter for. If set, only a list with objects of this
   *   type is returned.
   *
   * @return \Drupal\openlayers\Types\Object[]
   *   List of objects of this collection or list of a specific type of objects.
   */
  public function getFlatList(array $types = array()) {
    $list = $this->objects;

    if (!empty($types)) {
      $types = array_values($types);

      array_walk($types, function(&$value) {
        $value = drupal_strtolower($value);
      });

      $list = array_filter($this->objects, function($obj) use ($types) {
        /* @var Object $obj */
        return in_array($obj->getType(), $types);
      });
    }

    uasort($list, function($a, $b) {
      return $a->getWeight() - $b->getWeight();
    });

    return $list;
  }

  /**
   * Merges another collection into this one.
   *
   * @param \Drupal\openlayers\Types\Collection $collection
   *   The collection to merge into this one.
   */
  public function merge(Collection $collection) {
    foreach ($collection->getFlatList() as $object) {
      $this->prepend($object);
    }
  }

  /**
   * Get the collection as an export array with id's instead of objects.
   *
   * @return array
   *   The export array.
   */
  public function getExport() {
    $export = array();
    foreach ($this->getFlatList() as $object) {
      $export[$object->getType()][] = $object->getMachineName();
    }
    return array_change_key_case($export, CASE_LOWER);
  }
}
