<?php

/**
 * @file
 * A class representing a Hackpad User.
 */

class HackpadUser {
  protected $api;
  public $name;
  public $email;

  /**
   * Construct a HackpadUser.
   *
   * This method will check our local cache to see if the user has already been
   * created. Otherwise, it will try to create the user if needed.
   *
   * @param string $email
   *   The email address of the user to load or create.
   * @param string $name
   *   The name of the user of this Hackpad account.
   */
  public function __construct($email, $name) {
    $this->api = HackpadApi::api();

    if (!$cached = cache_get('hackpad:user:' . $email)) {
      // There's no "user exists" or "user load" Hackpad API, so instead we try
      // to create a user and ignore the error if it already exists.
      try {
        $success = $this->api->userCreate($name, $email);
      }
      catch (HackpadRequestException $e) {
        if ($e->getCode() == 403) {
          // We don't log the exception itself, but still put something in the
          // log so it's clear this exception case happened.
          watchdog('hackpad', 'A Hackpad user account with !email already exists.', array('!email' => $email), WATCHDOG_INFO);
        }
        else {
          // Some other HTTP error occured, so throw it back out.
          throw $e;
        }
      }
      cache_set('hackpad:user:' . $email, TRUE, 'cache', CACHE_PERMANENT);
    }

    $this->email = $email;
    $this->name = $name;
  }

  /**
   * Delete this Hackpad user.
   */
  public function delete() {
    $this->api->userDelete($this->email);
    cache_clear_all('hackpad:user:' . $this->email, 'cache');
  }

  /**
   * Enable Hackpad email notifications for this user.
   */
  public function enableNotifications() {
    $this->api->userNotifications($this->email, TRUE);
  }

  /**
   * Disable Hackpad email notifications for this user.
   */
  public function disableNotifications() {
    $this->api->userNotifications($this->email, FALSE);
  }

  /**
   * Return the name of this class.
   *
   * This is needed as __CLASS__ won't resolve static subclasses if the method
   * isn't overridden in the subclass.
   */
  public static function className() {
    return __CLASS__;
  }

  /**
   * Factory to load a HackpadUser from a Drupal account.
   *
   * @param stdClass $account
   *   The Drupal account to load the Hackpad user for.
   *
   * @return HackpadUser
   *   A HackpadUser.
   */
  public static function fromAccount($account) {
    $name = format_username($account);
    $className = static::className();
    return new $className($account->mail, $name);
  }
}
