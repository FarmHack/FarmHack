<?php

/**
 * Access the Hackpad REST API.
 */
class HackpadApi {
  // This ensures that if we subclass this we don't have to change the api()
  // method.
  var $base_uri;
  var $subdomain;
  var $client_id;
  var $secret;

  /**
   * Static function to use to create a new Hackpad connection or return an
   * existing connection. Calling methods should almost always use this to
   * return a connection to the API.
   */
  public static function api() {
    $className = self::className();
    $api = &drupal_static($className);
    if (!$api) {
      $api = new $className();
    }

    return $api;
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
   * Construct a new API connection.
   */
  public function __construct() {
    $this->subdomain = variable_get('hackpad_subdomain', FALSE);
    $this->base_uri = 'https://' . $this->subdomain . '.hackpad.com/api/1.0';

    $this->client_id = variable_get('hackpad_client_id', FALSE);
    $this->secret = variable_get('hackpad_secret', FALSE);
  }

  /**
   * Make a request to the Hackpad API.
   *
   * @param string $resource
   *   The resource within the Hackpad API to access, such as 'pad/create'.
   * @param array $options
   *   An array of options to pass to drupal_http_request(). Can also contain a
   *   'query' key containing an array of query parameters.
   * @param bool $post_body
   *   Optional parameter indicating that this request contains the OAuth
   *   parameters within the body of the request. In this case, $options['data']
   *   must be set.
   *
   * @throws HackpadRequestException
   *
   * @see drupal_http_request()
   *
   * @return stdClass
   *   An object decoded from the response data.
   */
  protected function request($resource, $options = array(), $post_body = FALSE) {
    $uri = $this->base_uri . "/$resource";
    $method = isset($options['method']) ? $options['method'] : 'GET';

    if ($post_body) {
      $query = $options['data'];
      $options['headers'] = array('Content-type' => 'application/x-www-form-urlencoded');
      $options['data'] = $this->signRequest($uri, $method, $query);
    }
    else {
      isset($options['query']) ? $query = $options['query'] : $query = array();
      $signed_query = $this->signRequest($uri, $method, $query);
      $uri = url($uri . '?' . $signed_query);
    }

    $response = drupal_http_request($uri, $options);

    if ($response->code != 200) {
      if (module_exists('devel')) {
        dpm($response);
      }

      throw new HackpadRequestException(t('!error calling !resource', array('!error' => $response->error, '!resource' => $resource)), $response->code);
    }

    return $response;
  }

  /**
   * Helper function to return JSON-decoded data.
   */
  protected function request_json($resource, $options = array(), $post_body = FALSE) {
    return json_decode($this->request($resource, $options, $post_body)->data);
  }

  /**
   * Sign a request to the Hackpad API using oauth 1.0.
   *
   * @param string $uri
   *   The URI to make the request to.
   * @param string $method
   *   The HTTP method used for the request.
   * @param array $parameters
   *   An optional array of parameters to include in the signed data.
   *
   * @return array
   *   An array of URL parameters suitable for appending to a request made to
   *   $uri.
   */
  protected function signRequest($uri, $method, $parameters = array()) {
    $parameters['oauth_consumer_key'] = $this->client_id;
    $parameters['oauth_version'] = '1.0';
    $parameters['oauth_nonce'] = $this->nonce();
    $parameters['oauth_timestamp'] = REQUEST_TIME;

    $osm = new OAuthSignatureMethod_HMAC_SHA1();
    $o = new OAuthRequest($method, $uri, $parameters);
    $c = new OAuthConsumer($this->client_id, $this->secret);
    $o->sign_request($osm, $c, NULL);
    return $o->to_postdata();
  }

  /**
    * Generate a unique string for use with oauth requests.
    *
    * @return
    *   A unique string suitable to use with an oauth nonce parameter.
    */
  protected static function nonce() {
    $mt = microtime();
    $rand = mt_rand();

    return md5($mt . $rand); // md5s look nicer than numbers
  }

  /**
   * Create a new HackPad with the given type and body.
   *
   * @param string $content_type
   *   A MIME content type indicating the type of $body. One of text/html,
   *   text/x-web-markdown, or text/plain.
   * @param HackpadUser $hackpad_user
   *   A HackpadUser representing the user to create the pad as.
   * @param string $body
   *   The body of the new pad to create.
   *
   * @return string
   *   The object returned by the HackPad API containing a padId property.
   */
  public function padCreate($content_type, HackpadUser $hackpad_user, $body) {
    $options = array(
      'headers' => array(
        'content-type' => $content_type,
      ),
      'method' => 'POST',
      'data' => $body,
      'query' => array(
        'asUser' => $hackpad_user->email,
      ),
    );

    return $this->request_json("pad/create", $options);
  }

  /**
   * Set the contents of a pad.
   *
   * @param string $pad_id
   *   The Pad ID to set the contents of.
   * @param HackpadUser $hackpad_user
   *   A HackpadUser representing the user to set the pad contents as.
   * @param string $content_type
   *   A MIME content type indicating the type of $body. One of text/html,
   *   text/x-web-markdown, or text/plain.
   * @param string $body
   *   The new body of the pad.
   *
   * @return stdClass
   *   The response data from the request.
   */
  public function padContent($pad_id, HackpadUser $hackpad_user, $content_type, $body) {
    $resource = "pad/$pad_id/content";

    $options = array(
      'headers' => array(
        'content-type' => $content_type,
      ),
      'method' => 'POST',
      'data' => $body,
      'query' => array(
        'asUser' => $hackpad_user->email,
      ),
    );

    return $this->request_json($resource, $options);
  }

  /**
   * Revert the contents of a pad.
   *
   * @param string $pad_id
   *   The ID of the pad to revert.
   * @param string $revision_id
   *   The revision ID to revert to.
   * @param HackpadUser $hackpad_user
   *   Parameter of the email address of the user to run the revert as.
   *
   * @return stdClass
   *   A JSON object indicating if the revert was successful.
   */
  public function padRevert($pad_id, $revision_id, HackpadUser $hackpad_user) {
    $resource = "pad/$pad_id/revert-to/$revision_id";

    $options = array(
      'method' => 'POST',
      'query' => array(
        'asUser' => $hackpad_user->email,
      ),
    );

    return $this->request($resource, $options)->data;
  }

  /**
   * Load the contents of a pad.
   *
   * @param $pad_id
   *   The ID of the pad to load.
   * @param $as_user
   *   Parameter of the email address of the user to run the revert as.
   * @param $format
   *   Optional parameter of the format ('html', 'md', 'native', 'text') of the
   *   pad to load. Defaults to 'html'.
   * @param $revision_id
   *   Optional parameter of the revision of the pad to load. Defaults to
   *   'latest'.
   *
   * @return
   *   An object with 'revision' and 'body' properties containing the data
   *   loaded from the pad.
   */
  public function padContentLoad($pad_id, $as_user, $format = 'html', $revision_id = 'latest') {
    $resource = "pad/$pad_id/content/$revision_id.$format";
    $response = $this->request($resource);

    $pad = new stdClass();
    $pad->revision_id = $response->headers['x-hackpad-revision'];
    $pad->body = $response->data;

    return $pad;
  }

  /**
   * Return all of the revisions of a given pad.
   *
   * @param $pad_id
   *   The ID of the pad to load.
   *
   * @return
   *   An array of revision objects.
   */
  public function padRevisions($pad_id) {
    $resource = "pad/$pad_id/revisions";
    return $this->request_json($resource);
  }

  /**
   * Return an array of all pads that can be accessed by the calling user.
   *
   * @return
   *   An array of all pads that can be accessed by the calling user.
   */
  public function padsAll() {
    $resource = "pads/all";
    return $this->request_json($resource);
  }

  /**
   * Search Hackpad pads.
   *
   * @param string $query
   *   The text string to search for.
   * @param HackpadUser $hackpad_user
   *   The user to search as.
   * @param int $start
   *   Optional parameter of the index to start search results at, used for
   *   paging.
   * @param int $limit
   *   Optional parameter of the number of results to return, defaulting to 10.
   *
   * @return array
   *   An array of objects containing the pad title, ID, and matched snippet.
   */
  public function search($query, HackpadUser $hackpad_user, $start = 0, $limit = 10) {
    $resource = "search";
    $params = array(
      'q' => $query,
      'asUser' => $hackpad_user->email,
      'start' => $start,
      'limit' => $limit,
    );

    return $this->request_json($resource, array('query' => $params));
  }

  /**
   * Return an array of pad IDs that have been edited since a given time.
   *
   * @param $timestamp
   *   A Unix timestamp.
   *
   * @return
   *   An array of pad IDs, limited to 1000.
   */
  public function editedSince($timestamp) {
    return $this->request_json("edited-since/$timestamp");
  }

  /**
   * Revoke access to a pad for a user.
   *
   * @param $pad_id
   *   The ID of the pad to revoke access for.
   * @param $user
   *   The email addres sof the user to revoke access for.
   * @param $as_user
   *   The user who performs the revokation.
   *
   * @return
   *   A JSON object indicating if the request was successful.
   */
  public function revokeAccess($pad_id, $user, $as_user) {
    return $this->request_json("pad/$pad_id/revoke-access/$user?$as_user");
  }

  /**
   * Set custom user settings on a Hackpad user.
   *
   * @param $user
   *   The user's email address.
   * @param $settings
   *   An array of settings, keyed by the setting name.
   *
   * @return
   *   A JSON success object.
   */
  public function userSettings($user, $settings) {
    return $this->request_json("user/$user/settings", array('query' => $settings, 'method' => 'POST'));
  }

  /**
   * Enable or disable Hackpad notifications for a user.
   *
   * @param $user
   *   The user's email address to disable notifications for.
   *
   * @param $enabled
   *   Boolean of the desired setting for notifications.
   *
   * @param
   *  A JSON success object.
   */
  public function userNotifications($user, $enabled) {
    if ($enabled) {
      $settings['send-email'] = 'true';
    }
    else {
      $settings['send-email'] = 'false';
    }

    return $this->userSettings($user, $settings);
  }

  /**
   * Return a URL suitable for passing as the url parameter to render_url() in
   * the JavaScript API.
   *
   * @param $pad_id
   *   The ID of the pad to embed.
   * @param HackpadUser $hackpad_user
   *   A HackpadUser representing the user to create the pad as.
   *
   * @return
   *   A signed URL.
   */
  public function padRenderUrl($pad_id, HackpadUser $hackpad_user) {
    $params = array(
      'padId' => $pad_id,
      'name' => $hackpad_user->name,
      'email' => $hackpad_user->email,
    );

    $url = 'https://' . $this->subdomain . '.hackpad.com/ep/api/embed-pad';

    return url($url . '?' . $this->signRequest($url, 'GET', $params));
  }

  /**
   * Create a user in Hackpad.
   *
   * @param string $name
   *   The name of the user to create.
   * @param string $mail
   *   The email address of the user to create.
   * @param bool $isFullMember
   *   Optional parameter to indicate the user should have normal "full"
   *   account permissions.
   *
   * @return stdClass
   *   A JSON success object.
   */
  public function userCreate($name, $mail, $isFullMember = TRUE) {
    $params = array(
      'name' => $name,
      'email' => $mail,
      'isFullMember' => (int) $isFullMember,
    );

    $options = array(
      'method' => 'POST',
      'data' => $params,
    );

    return $this->request_json("user/create", $options, TRUE);
  }

  /**
   * Delete a Hackpad user account.
   *
   * @param string $mail
   *   The email address of the user to create.
   *
   * @return stdClass
   *   A JSON success object.
   */
  public function userDelete($mail) {
    $resource = "user/$mail/remove";
    $options = array(
      'method' => 'POST',
    );

    return $this->request_json($resource, $options);
  }
}

/**
 * Exception thrown if a HTTP request to HackPad fails.
 */
class HackpadRequestException extends Exception {}

