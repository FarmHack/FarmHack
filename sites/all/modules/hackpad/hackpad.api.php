<?php

/**
 * @file
 * Describe hooks provided by the Hackpad module.
 */

/**
 * Describe the class names to be used for Hackpad classes.
 *
 * This hook allows for additional classes to be registered with the Hackpad
 * module. To instantiate any Hackpad class, use hackpad_class_info() to
 * determine the class to actually load.
 *
 * @code
 *     global $user;
 *     $user_class = hackpad_class_info('HackpadUser');
 *     $hackpad_user = $user_class::fromAccount($user);
 * @endcode
 *
 * @return array
 *   An associative array with the key names containing the "base class" name
 *   of the new class, and the key values containing the name of the class to
 *   instantiate. Normally the keys and the values will be identical. Each
 *   class must be registered within your module's .info file as a files[]
 *   entery so it can be autoloaded.
 */
function hook_hackpad_class_info() {
  return array(
    'HackpadApi' => 'HackpadApi',
    'HackpadPad' => 'HackpadPad',
    'HackpadUser' => 'HackpadUser',
  );
}

/**
 * Alter the class names to be used for Hackpad classes.
 *
 * This hook allows for alternate classes to be used in place of any class
 * defined by the Hackpad module.
 *
 * Any class with a static factory method (like HackpadApi::api() and
 * HackpadUser::fromAccount()) must override the className() static method.
 * Otherwise, PHP will return the superclass for __CLASS__ instead of the
 * subclass name.
 *
 * @param array &$classes
 *   An array of class mappings. Each key corresponds to the base class, and
 *   each value corresponds to the actual class name to instantiate.
 */
function hook_hackpad_class_info_alter(&$classes) {
  $classes['HackpadUser'] = 'MyModuleHackpadUser';
}
