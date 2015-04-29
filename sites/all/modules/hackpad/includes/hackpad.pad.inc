<?php

/**
 * Class representing a Hackpad pad.
 */
class HackpadPad {
  var $api;
  var $pad_id;
  var $revision_id;
  var $format;
  var $body;
  var $hackpad_user;

  /**
   * Construct a pad.
   *
   * @param $pad_id
   *   Optional parameter of the pad ID to load. If $format is specified the
   *   pad will be loaded in that format, otherwise it will default to HTML.
   * @param $format
   *   Optional parameter of the format of the pad.
   * @param $account
   *   Optional parameter of the Drupal user account to load and modify this
   *   pad as.
   */
  function __construct($pad_id = NULL, $format = NULL, $account = NULL) {
    $this->api = HackpadApi::api();

    if (!$account) {
      $account = $GLOBALS['user'];
    }
    $className = hackpad_class_info('HackpadUser');
    $this->hackpad_user = $className::fromAccount($account);

    if (!$format) {
      $format = 'native';
    }

    $this->formatValidate($format);
    $this->format = $format;

    if (!$pad_id) {
      $response = $this->api->padCreate($this->mimeType(), $this->hackpad_user, '');
      $this->pad_id = $response->padId;
    }
    else {
      $this->pad_id = $pad_id;
      $this->load();
    }
  }

  /**
   * Validate a Hackpad pad format is supported.
   *
   * @param $format
   *   The format to validate, matching the file extension used when fetching
   *   the pad resource.
   *
   * @throws HackpadInvalidFormatException
   */
  public static function formatValidate($format) {
    switch ($format) {
      case 'md':
        return;
      case 'text':
        return;
      case 'html':
        return;
      case 'native':
        return;
      default:
        throw new HackpadInvalidFormatException("$format is an invalid Hackpad format.");
    }
  }

  /**
   * Search Hackpad pads.
   *
   * @param $query
   *   The text string to search for.
   * @param $account
   *   Optional parameter of the Drupal account to search as.
   * @param $start
   *   Optional parameter of the index to start search results at, used for
   *   paging.
   * @param $limit
   *   Optional parameter of the number of results to return, defaulting to 10.
   *
   * @return
   *   An array of objects containing the pad title, ID, and matched snippet.
   */
  public static function search($query, $account = NULL, $start = 0, $limit = 10) {
    $api = HackpadApi::api();

    if (!$account) {
      $account = $GLOBALS['user'];
    }
    $className = hackpad_class_info('HackpadUser');
    $hu = $className::fromAccount($account);

    return $api->search($query, $hu, $start, $limit);
  }

  /**
   * Return the mime type for a given Hackpad format.
   *
   * @param $format
   *   Optional parameter of the format return the mime type for.
   *
   * @return
   *   The mime type of the hackpad format.
   */
  function mimeType($format = NULL) {
    if (!$format) {
      $format = $this->format;
    }

    $this->formatValidate($format);

    switch ($format) {
      case 'md':
        return 'text/x-web-markdown';
      case 'text':
        return 'text/plain';
      case 'html':
        return 'text/html';
    }
  }

  /**
   * Retreive or set the contents of this pad.
   *
   * @param $content
   *   Optional parameter of the string to set as the contents of this pad.
   *
   * @return
   *   The pad contents.
   */
  function content($content = NULL) {
    if ($content) {
      $this->body = $content;
    }

    return $this->body;
  }

  /**
   * Save this pad to Hackpad.
   *
   * @throws HackpadSaveException
   */
  function save() {
    $response = $this->api->padContent($this->pad_id, $this->hackpad_user, $this->mimeType(), $this->body);
    if (!isset($response['success']) || $response['success'] != true) {
      throw new HackpadSaveException("Hackpad save failed.");
    }
  }

  /**
   * Load the contents of this pad from Hackpad.
   */
  function load() {
    $response = $this->export($this->format);
    $this->revision_id = $response->revision_id;
    return $response;
  }

  /**
   * Export the contents of this pad.
   *
   * @param $format
   *   A valid Hackpad format.
   * @return
   *   A string with the contents of the pad export.
   */
  function export($format = 'html') {
    $response = $this->api->padContentLoad($this->pad_id, $this->hackpad_user, $format);
    return $response;
  }

  /**
   * Return a list of all revisions of this pad.
   */
  function revisions() {
    return $this->api->padRevisions($this->pad_id);
  }

  /**
   * Revert this pad to a given revision ID. The pad will be immediately
   * reloaded from Hackpad with the new contents.
   *
   * @param $revision_id
   *   The revision ID to revert to as returned by HackpadPad->revisions();
   */
  function revert($revision_id) {
    $this->api->padRevert($this->pad_id, $revision_id, $this->hackpad_user);
    $this->load();
  }

  /**
   * Return a signed URL for this pad.
   *
   * This call used to pass to the render_url() JavaScript API call for
   * embedding a pad.
   *
   * @return string
   *   A URL to pass to render_url() in JavaScript.
   */
  public function renderUrl() {
    return $this->api->padRenderUrl($this->pad_id, $this->hackpad_user);
  }
}

/**
 * Exception thrown if an invalid format is used to instantiate a Pad.
 */
class HackpadInvalidFormatException extends Exception {}

/**
 * Exception thrown if saving to a pad fails.
 */
class HackpadSaveException extends Exception {}

