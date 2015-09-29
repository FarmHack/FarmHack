<?php
/**
 * @file
 * Class Object.
 */

namespace Drupal\openlayers\Types;
use Drupal\Component\Plugin\PluginBase;
use Drupal\openlayers\Config;
use Drupal\openlayers\Openlayers;
use Drupal\openlayers\Types\Collection;
use Drupal\openlayers\Types\ObjectInterface;

/**
 * Class Object.
 */
abstract class Object extends PluginBase implements ObjectInterface {
  /**
   * The unique machine name.
   *
   * @var string
   */
  public $machine_name;

  /**
   * The human readable name.
   *
   * @var string
   */
  public $name;

  /**
   * A short description.
   *
   * @var string
   */
  public $description;

  /**
   * The factory service.
   *
   * @var string
   */
  public $factory_service;

  /**
   * @var int
   */
  protected $weight = 0;
  /**
   * The array containing the options.
   *
   * @var array
   */
  protected $options = array();

  /**
   * Holds the Collection object.
   *
   * @var Collection
   */
  protected $collection;

  /**
   * Holds all the attachment used by this object.
   *
   * @var array
   */
  protected $attached = array(
    'js' => array(),
    'css' => array(),
    'library' => array(),
    'libraries_load' => array(),
  );

  /**
   * {@inheritdoc}
   */
  public function init() {
    $this->options = $this->getOptions();
    $this->machine_name = $this->getMachineName();
    $this->name = $this->getName();
    $this->description = $this->getDescription();
    $this->factory_service = $this->getFactoryService();
  }

  /**
   * {@inheritdoc}
   *
   * @TODO What is this return? If it is the form, why is form by reference?
   */
  public function optionsForm(&$form, &$form_state) {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function optionsFormValidate($form, &$form_state) {}

  /**
   * {@inheritdoc}
   */
  public function optionsFormSubmit($form, &$form_state) {
    if (isset($form_state['values']['options'])) {
      $options = array_merge((array) $this->getOptions(), (array) $form_state['values']['options']);
      $this->setOptions($options);
    }

    $form_state['item'] = $this->getExport();

    // Refresh translatable strings.
    $this->i18nStringsRefresh();
  }

  /**
   * {@inheritdoc}
   */
  public function preBuild(array &$build, ObjectInterface $context = NULL) {
    foreach ($this->getCollection()->getFlatList() as $object) {
      if ($object !== $this) {
        $object->preBuild($build, $context);
      }
    }
    drupal_alter('openlayers_object_preprocess', $build, $this);
  }

  /**
   * {@inheritdoc}
   */
  public function postBuild(array &$build, ObjectInterface $context = NULL) {
    foreach ($this->getCollection()->getFlatList() as $object) {
      if ($object !== $this) {
        $object->postBuild($build, $context);
      }
    }
    drupal_alter('openlayers_object_postprocess', $build, $this);
  }

  /**
   * {@inheritdoc}
   */
  public function clearOption($parents) {
    $ref = &$this->options;

    if (is_string($parents)) {
      $parents = array($parents);
    }

    $last = end($parents);
    reset($parents);
    foreach ($parents as $parent) {
      if (isset($ref) && !is_array($ref)) {
        $ref = array();
      }
      if ($last == $parent) {
        unset($ref[$parent]);
      }
      else {
        if (isset($ref[$parent])) {
          $ref = &$ref[$parent];
        }
        else {
          break;
        }
      }
    }

    // Invalidate the Collection so it gets rebuilt with new options.
    $this->collection = NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function setOption($parents, $value = NULL) {
    $ref = &$this->options;

    if (is_string($parents)) {
      $parents = array($parents);
    }

    foreach ($parents as $parent) {
      if (isset($ref) && !is_array($ref)) {
        $ref = array();
      }
      $ref = &$ref[$parent];
    }
    $ref = $value;

    // Invalidate the Collection so it gets rebuilt with new options.
    $this->collection = NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function getOptions() {
    if (!empty($this->options)) {
      return $this->options;
    }
    else {
      $configuration = $this->getConfiguration();
      if (!empty($configuration['options'])) {
        return $configuration['options'];
      }
    }

    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function setOptions(array $options = array()) {
    $this->options = $options;

    // Invalidate the Collection so it gets rebuilt with new options.
    $this->collection = NULL;
  }

  /**
   * {@inheritdoc}
   */
  public function getExport() {
    $configuration = $this->getConfiguration();
    $options = $this->getOptions();

    $options = Openlayers::array_map_recursive('\Drupal\openlayers\Openlayers::floatval_if_numeric', (array) $options);
    $options = Openlayers::removeEmptyElements((array) $options);
    $configuration['options'] = $options;

    return (object) $configuration;
  }

  /**
   * {@inheritdoc}
   */
  public function getConfiguration() {
    return $this->configuration;
  }

  /**
   * {@inheritdoc}
   */
  public function getMachineName() {
    $configuration = $this->getConfiguration();
    if (isset($configuration['machine_name'])) {
      return check_plain($configuration['machine_name']);
    }
    else {
      return 'undefined';
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    $configuration = $this->getConfiguration();
    if (isset($configuration['name'])) {
      return check_plain($configuration['name']);
    }
    else {
      return 'undefined';
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getDescription() {
    $configuration = $this->getConfiguration();
    if (isset($configuration['description'])) {
      return check_plain($configuration['description']);
    }
    else {
      return 'undefined';
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getFactoryService() {
    $configuration = $this->getConfiguration();
    if (isset($configuration['factory_service'])) {
      return check_plain($configuration['factory_service']);
    }
    else {
      return 'undefined';
    }
  }

  /**
   * {@inheritdoc}
   */
  public function getOption($parents, $default_value = NULL) {
    if (is_string($parents)) {
      $parents = array($parents);
    }

    if (is_array($parents)) {
      $notfound = FALSE;

      if (!isset($this->options)) {
        $notfound = TRUE;
        $parents = array();
        $options = array();
      }
      else {
        $options = $this->options;
      }

      foreach ($parents as $parent) {
        if (isset($options[$parent])) {
          $options = $options[$parent];
        }
        else {
          $notfound = TRUE;
          break;
        }
      }
      if (!$notfound) {
        return $options;
      }
    }

    if (is_null($default_value)) {
      return FALSE;
    }

    return $default_value;
  }

  /**
   * {@inheritdoc}
   */
  public function attached() {
    if ($plugin = $this->getPluginDefinition()) {
      $path = $this->getClassDirectory();

      $jsdir = $path . '/js';
      $cssdir = $path . '/css';
      if (file_exists($jsdir)) {
        foreach (file_scan_directory($jsdir, '/.*\.js$/') as $file) {
          $this->attached['js'][$file->uri] = array(
            'data' => $file->uri,
            'type' => 'file',
            'group' => Config::get('openlayers.js_css.group'),
            'weight' => Config::get('openlayers.js_css.weight'),
          );
        }
      }
      if (file_exists($cssdir)) {
        foreach (file_scan_directory($cssdir, '/.*\.css$/') as $file) {
          $this->attached['css'][$file->uri] = array(
            'data' => $file->uri,
            'type' => 'file',
            'group' => Config::get('openlayers.js_css.group'),
            'weight' => Config::get('openlayers.js_css.weight'),
            'media' => Config::get('openlayers.js_css.media'),
          );
        }
      }
    }

    return $this->attached;
  }

  /**
   * {@inheritdoc}
   */
  public function getObjects($type = NULL) {
    return array_values($this->getCollection()->getObjects($type));
  }

  /**
   * {@inheritdoc}
   */
  public function getParents() {
    return array_filter(Openlayers::loadAll('Map'), function($map) {
      return array_filter($map->getObjects($this->getType()), function($object) {
        return $object->getMachineName() == $this->getMachineName();
      });
    });
  }

  /**
   * {@inheritdoc}
   */
  public function dependencies() {
    return array();
  }

  /**
   * {@inheritdoc}
   */
  public function getProvider() {
    $class = explode('\\', $this->pluginDefinition['class']);
    return $class[1];
  }

  /**
   * {@inheritdoc}
   */
  public function getClassDirectory() {
    $class = explode('\\', $this->pluginDefinition['class']);
    return drupal_get_path('module', $this->getProvider()) . '/src/' . implode('/', array_slice($class, 2, -1));
  }

  /**
   * {@inheritdoc}
   */
  public function getClassPath() {
    $class = explode('\\', $this->pluginDefinition['class']);
    return drupal_get_path('module', $this->getProvider()) . '/src/' . implode('/', array_slice($class, 2)) . '.php';
  }

  /**
   * {@inheritdoc}
   */
  public function isAsynchronous() {
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function getType() {
    $class = explode('\\', get_class($this));
    return drupal_strtolower($class[3]);
  }

  /**
   * {@inheritdoc}
   */
  public function getCollection() {
    if (is_null($this->collection) || !($this->collection instanceof Collection)) {
      $this->collection = \Drupal::service('openlayers.Types')->createInstance('Collection');
      $this->collection->import($this->optionsToObjects());
      $this->collection->append($this);
    }
    return $this->collection;
  }

  /**
   * {@inheritdoc}
   */
  public function optionsToObjects() {
    return array();
  }

  /**
   * {@inheritdoc}
   *
   * !Attention! This function will remove any option that is named after a
   * plugin type e.g.: layers, controls, styles, interactions, components .
   */
  public function getJS() {
    $export = $this->getExport();

    array_map(function($type) use ($export) {
      unset($export->options[$type . 's']);
    }, Openlayers::getPluginTypes());

    $js = array(
      'mn' => $export->machine_name,
      'fs' => $export->factory_service,
    );

    if (!empty($export->options)) {
      $js['opt'] = $export->options;
    }

    return $js;
  }

  /**
   * {@inheritdoc}
   */
  public function setWeight($weight) {
    $this->weight = $weight;
  }

  /**
   * {@inheritdoc}
   */
  public function getWeight() {
    return intval($this->weight);
  }

  /**
   * {@inheritdoc}
   */
  public function getPluginDescription() {
    $plugin_definition = $this->getPluginDefinition();
    return isset($plugin_definition['description']) ? $plugin_definition['description'] : '';
  }

  /**
   * {@inheritdoc}
   */
  public function i18nStringsRefresh() {}

}
