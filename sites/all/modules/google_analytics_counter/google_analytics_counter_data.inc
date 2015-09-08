<?php

/**
 * @file
 * Parsing and writing the fetched data.
 */

/**
 * Find how many distinct paths does Google Analytics have for this profile. This function is triggered by hook_cron().
 */
function google_analytics_counter_update_path_counts() {

  // Record how long did this chunk take to process.
  $chunkprocessbegin = time();

  // Needing to stay under the Google Analytics API quota, let's count how many API retrievals were made in the last 24 hours.
  // @todo We should better take into consideration that the quota is reset at midnight PST (note: time() always returns UTC).
  $dayquota = variable_get('google_analytics_counter_dayquota', array(0, 0));
  if (REQUEST_TIME - $dayquota[0] >= 86400) {
    // If last API request was more than a day ago, set monitoring time to now.
    $dayquota[0] = REQUEST_TIME;
    $dayquota[1] = 0;
    variable_set('google_analytics_counter_dayquota', array($dayquota[0], $dayquota[1]));
  }
  //dpm($dayquota);
  // Are we over the GA API limit?
  $maxdailyrequests = variable_get('google_analytics_counter_api_dayquota', 10000); // See http://code.google.com/apis/analytics/docs/gdata/gdataDeveloperGuide.html#quota
  if ($dayquota[1] > $maxdailyrequests) {
    watchdog(t('Google Analytics Counter'), t('Google Analytics API quota of %maxdailyrequests requests has been reached. Will NOT fetch data from Google Analytics for the next %dayquota seconds. See <a href="/admin/config/system/google_analytics_counter">the Google Analytics Counter settings page</a> for more info.', array('%maxdailyrequests' => check_plain($maxdailyrequests), '%dayquota' => check_plain(($dayquota[0]+86400-REQUEST_TIME)))), NULL, WATCHDOG_ERROR);
    return;
  }

  // How many results to ask from GA in one request. Default on 1000 to fit most systems (for example those with no external cron).
  $chunk = variable_get('google_analytics_counter_chunk_to_fetch', 1000);
  // In case there are more than $chunk path/counts to retrieve from GA, do just one chunk at a time and register that in $step.
  $step = variable_get('google_analytics_counter_data_step', 0);
  // Which GA result to look for first. Must be between 1 - infinity.
  $pointer = $step*$chunk+1;
  //dpm('START chunk '.$chunk);
  //dpm('START step '.$step);
  //dpm('START pointer '.$pointer);

  // The earliest valid start-date for Google Analytics is 2005-01-01.
  $request = array(
    'dimensions' => array('ga:pagePath'), // date would not be necessary for totals, but we also calculate stats of views per day, so we need it
    'metrics' => array('ga:pageviews'),
    'start_date' => strtotime('2005-01-01'),
      'end_date' => strtotime('tomorrow'), // Using 'tomorrow' to offset any timezone shift between the hosting and Google servers.
      'start_index' => $pointer,
      'max_results' => $chunk,
      //'filters' => 'ga:pagePath==/node/3',
      //'#start_date' => strtotime('2005-01-01'), // We want to retrieve all page views for this path. The earliest valid start-date for Google Analytics is 2005-01-01.
      //'sort_metric' => array('ga:date'),
      );

  $resultcount = FALSE;
  $cachehere = array(
    'cid' => 'google_analytics_counter_' . md5(serialize($request)),
    'expire' => google_analytics_counter_cache_time(),
      'refresh' => FALSE,
      );
  $new_data = @google_analytics_counter_report_data($request, $cachehere);

  if (!$new_data->fromCache) { // Don't write anything to google_analytics_counter if this GA data comes from cache (would be writing the same again).

    // This was a live request. Increase the GA request limit tracker.
    variable_set('google_analytics_counter_dayquota', array($dayquota[0], ($dayquota[1]+1)));

    if (!empty($new_data->error)) { // If NULL then there is no error.
      watchdog(t('Google Analytics Counter'), t('Problem fetching data from Google Analytics: %new_dataerror. Did you authenticate any Google Analytics profile? See <a href="/admin/config/system/google_analytics_counter/authentication">here</a>.', array('%new_dataerror' => $new_data->error)), NULL, WATCHDOG_ERROR);
      // Nothing to do; return.
      //return;
    }
    else {
      $resultsretrieved = $new_data->results->rows;
      foreach ($resultsretrieved as $val) {

        // http://drupal.org/node/310085
        db_merge('google_analytics_counter')
        ->key(array('pagepath_hash' => md5($val['pagePath'])))
        ->fields(array(
          'pagepath' => check_plain($val['pagePath']), // Added check_plain; see https://www.drupal.org/node/2381703
          'pageviews' => check_plain($val['pageviews']), // Added check_plain; see https://www.drupal.org/node/2381703
          ))
        ->execute();

      }
    }

  }

  // The total number of records for this profile.
  $resultcount = @$new_data->results->totalResults;
  // Store it in a variable.
  variable_set('google_analytics_counter_totalpaths', $resultcount);

  // The total number of hits for all records for this profile.
  $totalhits = @$new_data->results->totalsForAllResults['pageviews'];
  variable_set('google_analytics_counter_totalhits', $totalhits);
  //dpm('totalhits: '.$totalhits);

  // Set the pointer.
  $pointer += $chunk;

  //dpm('step: '.$step.' | '.$pointer . ' out of total ' .$resultcount);
  watchdog(t('Google Analytics Counter'), t('Retrieved %sizeof items from Google Analytics data for paths %first-%second.', array('%sizeof' => sizeof(@$new_data->results->rows), '%first' => ($pointer-$chunk), '%second' => ($pointer-$chunk-1+sizeof(@$new_data->results->rows)))), NULL, WATCHDOG_INFO);

  // OK now increase or zero $step
  if ($pointer <= $resultcount) {
    // If there are more results than what we've reached with this chunk, increase step to look further during the next run.
    $newstep = $step+1;
  }
  else {
    $newstep = 0;
  }
  //dpm('newstep: '.$newstep);
  variable_set('google_analytics_counter_data_step', $newstep);

  // Record how long did this chunk take to process.
  variable_set('google_analytics_counter_chunk_process_time', time()-$chunkprocessbegin);

}

/**
 * Calculate pageviews for one path (with any aliases).
 */
function google_analytics_counter_get_sum_per_path($path, $cacheon = TRUE) {

  //dpm('==============================================================');
  //dpm('requested path: '.$path);

  // Recognize special path 'all' to get the sum of all pageviews for the profile.
  if ($path == 'all') {
    //dpm('yep: '.variable_get('google_analytics_counter_totalhits', 0));
    return variable_get('google_analytics_counter_totalhits', 0);
  }

  $path = check_plain($path); // Esp. in case function is called directly.

  // Remove initial slash, if any.
  if (substr($path, 0, 1) == '/') $path = substr($path, 1);
  //dpm($path);

  // Get list of allowed languages to detect front pages such as http://mydomain.tld/en
  // Must come AFTER the possible initial slash is removed!
  $langs = language_list();
  $frontpages = array();
  foreach($langs as $lang=>$object){
    $frontpages[] = $lang;
  }
  $frontpages[] = '';
  $frontpages[] = '/';
  //dpm($frontpages);
  if (in_array($path, $frontpages)) {
    // This is the home page!
    $path = variable_get('site_frontpage', 'node');
  }

  //If it's a node we'll distinguish the language part of it, if any. Either format en/node/55 or node/55.
  $path_no_slashes_at_ends = trim($path, '/');
  $splitpath = explode('/', $path_no_slashes_at_ends);
  //dpm($splitpath);
  $lang_prefix = '';
  if (
      (sizeof($splitpath) == 3 AND strlen($splitpath[0]) == 2 AND $splitpath[1] == 'node' AND is_numeric($splitpath[2]))
      OR
      (sizeof($splitpath) == 2 AND $splitpath[0] == 'node' AND is_numeric($splitpath[1]))
     ){
    if (sizeof($splitpath) == 3) {
      $nidhere = $splitpath[2];
    }
    else if (sizeof($splitpath) == 2) {
      $nidhere = $splitpath[1];
    }
    $dbresults = db_select('node', 'n')
      ->fields('n', array('nid','language'))
      ->condition('nid', $nidhere, '=')
      ->execute();
    foreach ($dbresults as $dbresult) {
      //dpm($dbresult->language);
      if ($dbresult->language <> 'und' AND $dbresult->language <> '') {
        $lang_prefix = $dbresult->language.'/';
        // If this is a language-prefixed node we need its path without the prefix for later.
        if (sizeof($splitpath) == 3){
          $path = $splitpath[1].'/'.$splitpath[2];
        }
      }
      break; // Is just 1 result anyway.
    }
    //dpm('detected NODE path: '.$path);
    //dpm('detected NODE prefix: '.$lang_prefix);
  }

  //Now if it's a node but has a prefixed or unprefixed alias, e.g. en/my/path or my/path, we should also try to determine if it's a node and then count it's node/nid with it!
  if ($lang_prefix == ''){
    if (sizeof($splitpath) > 1 AND strlen($splitpath[0]) == 2 AND !is_numeric($splitpath[0])){ // E.g. en/view or nl/my/view or xx/view
      // Now we need to find which nid does it correspond (the language prefix + the alias)
      $withoutprefix = $splitpath;
      $lang = array_shift($withoutprefix);
      $withoutprefix = implode('/', $withoutprefix);
     //dpm('withoutprefix: '.$withoutprefix);
      $nodepath = drupal_lookup_path('source', $withoutprefix);
     //dpm('system path for alias: '.$nodepath);
      if ($nodepath !== FALSE) {
        $path = $nodepath;
        $lang_prefix = $lang.'/';
      }
      //dpm('detected ALIAS path: '.$path);
      //dpm('detected ALIAS prefix: '.$lang_prefix);
    }
  }

  //Now, it's also possible that it's a node alias but without prefix! E.g. my/path but in fact it's en/node/nid!
  if ($lang_prefix == ''){
    $path_no_slashes_at_ends = trim($path, '/');
    $nodepath = drupal_lookup_path('source', $path_no_slashes_at_ends);
    //dpm('path_no_slashes_at_ends: '.$path_no_slashes_at_ends);
    //dpm('nodepath: '.$nodepath);
    if ($nodepath !== FALSE) {
      $path = $nodepath;
      $splitnodepath = explode('/', $nodepath);
      if (sizeof($splitnodepath) == 2 AND $splitnodepath[0] == 'node' AND is_numeric($splitnodepath[1])){
        $dbresults = db_select('node', 'n')
          ->fields('n', array('nid','language'))
          ->condition('nid', $splitnodepath[1], '=')
          ->execute();
        foreach ($dbresults as $dbresult) {
          //dpm($dbresult->language);
          if ($dbresult->language <> 'und' AND $dbresult->language <> '') {
            $lang_prefix = $dbresult->language.'/';
          }
          break; // Is just 1 result anyway.
        }
        //$lang_prefix = $lang.'/';
      }
      //dpm('detected NODE path from ALIAS: '.$path);
      //dpm('detected NODE prefix from ALIAS: '.$lang_prefix);
    }
  }

  // But it also could be a redirect path!
  if (function_exists('redirect_load_by_source')){
    $path_no_slashes_at_ends = trim($path, '/');
    $redirect_object = redirect_load_by_source($path_no_slashes_at_ends, $GLOBALS['language']->language, drupal_get_query_parameters());
    //dpm($redirect_object);
    if (is_object($redirect_object)){
      //dpm('gotten from redirect object: '.$redirect_object->redirect);
      if (is_string($redirect_object->redirect)){
        $path = $redirect_object->redirect;
      }
      if (is_string($redirect_object->language)){
        $lang_prefix = $redirect_object->language.'/';
      }
      //dpm('detected NODE path from REDIRECT: '.$path);
      //dpm('detected NODE prefix from REDIRECT: '.$lang_prefix);
    }
  }

  // All right, finally we can calculate the sum of pageviews. This process is cached.
  $cacheid = md5($lang_prefix.$path);
  // $cacheon = FALSE; // Useful for debugging.
  if ($cache = cache_get('google_analytics_counter_page_' . $cacheid) AND $cacheon) {
    $sum_of_pageviews = $cache->data;
    //dpm('CACHED');
  }
  else {
    // Get pageviews for this path and all its aliases.
    /*
     * NOTE: Here $path does NOT have an initial slash because it's coming from either check_plain($_GET['q']) (block) or from a tag like [gac|node/N].
     * Remove a trailing slash (e.g. from node/3/) otherwise _google_analytics_counter_path_aliases() does not find anything.
     */
    $path_no_slashes_at_ends = trim($path, '/');
    //dpm('path_no_slashes_at_ends: '.$path_no_slashes_at_ends);
    $unprefixedaliases = _google_analytics_counter_path_aliases($path_no_slashes_at_ends);
    //dpm('unprefixedaliases:');
    //dpm($unprefixedaliases);
    $allpaths = array();
    $allpaths_dpm = array();
    foreach ($unprefixedaliases as $val) {
      // Google Analytics stores initial slash as well, so let's prefix them.
      $allpaths[] = md5('/'.$lang_prefix.$val); // With language prefix, if available, e.g. /en/node/55
      $allpaths_dpm[] = '/'.$lang_prefix.$val;
      // And its variant with trailing slash (https://www.drupal.org/node/2396057)
      $allpaths[] = md5('/'.$lang_prefix.$val.'/'); // With language prefix, if available, e.g. /en/node/55
      $allpaths_dpm[] = '/'.$lang_prefix.$val.'/';
      if ($lang_prefix <> ''){
        // Now, if we are counting NODE with language prefix, we also need to count the pageviews for that node without the prefix -- it could be that before it had no language prefix but it still was the same node!
        // BUT this will not work for non-nodes, e.g. views. There we depend on the path e.g. /en/myview because it would be tricky to get a valid language prefix out of the path. E.g. /en/myview could be a path of a view where "en" does not mean the English language. In other words, while prefix before node/id does not change the page (it's the same node), with views or other custom pages the prefix may actually contain completely different content.
        $allpaths[] = md5('/'.$val);
        $allpaths_dpm[] = '/'.$val;
        // And its variant with trailing slash (https://www.drupal.org/node/2396057)
        $allpaths[] = md5('/'.$val.'/');
        $allpaths_dpm[] = '/'.$val.'/';
        // @TODO ... obviously, here we should treat the possibility of the NODE/nid having a different language prefix. A niche case (how often do existing NODES change language?)
      }
    }

    // Find possible redirects for this path using redirect_load_multiple() from module Redirect http://drupal.org/project/redirect
    if (function_exists('redirect_load_multiple')){
      $path_no_slashes_at_ends = trim($path, '/');
      $redirectobjects = redirect_load_multiple(FALSE, array('redirect' => $path_no_slashes_at_ends));
      foreach($redirectobjects as $redirectobject){
        $allpaths[] = md5('/'.$redirectobject->source);
        $allpaths_dpm[] = '/'.$redirectobject->source;
        // And its variant with trailing slash (https://www.drupal.org/node/2396057)
        $allpaths[] = md5('/'.$redirectobject->source.'/');
        $allpaths_dpm[] = '/'.$redirectobject->source.'/';
        $allpaths[] = md5('/'.$redirectobject->language.'/'.$redirectobject->source);
        $allpaths_dpm[] = '/'.$redirectobject->language.'/'.$redirectobject->source;
        // And its variant with trailing slash (https://www.drupal.org/node/2396057)
        $allpaths[] = md5('/'.$redirectobject->language.'/'.$redirectobject->source.'/');
        $allpaths_dpm[] = '/'.$redirectobject->language.'/'.$redirectobject->source.'/';
      }
    }

    // Very useful for debugging. In face each variant: node/NID, alias, redirect, non-node ... with or without trailing slash, with or without language ... should always give the same count (sum of counts of all path variants).
    //dpm('allpaths_dpm:');
    //dpm($allpaths_dpm);

    // Get path counts for each of the path aliases.
    // Search hash values of path -- faster (primary key). E.g. SELECT pageviews FROM `google_analytics_counter` where pagepath_hash IN ('ee1c787bc14bec9945de3240101e919c', 'd884e66c2316317ef6294dc12aca9cef')
    $pathcounts = db_select('google_analytics_counter', 'gac')
    //->fields('gac', array('pagepath', 'pageviews'))
    ->fields('gac', array('pageviews'))
    //->condition('pagepath', array('/bg', '/node/3'), 'IN')
    ->condition('pagepath_hash', $allpaths, 'IN')
    ->execute();
    //dpm($pathcounts);
    $sum_of_pageviews = 0;
    foreach ($pathcounts as $pathcount) {
    //dpm($pathcount);
    //dpm('partial: '.$pathcount->pageviews);
      $sum_of_pageviews += $pathcount->pageviews;
    }
    //dpm('sum: '.$sum_of_pageviews);

    cache_set('google_analytics_counter_page_' . $cacheid, $sum_of_pageviews, 'cache', CACHE_TEMPORARY);
    //dpm('UNCACHED');
  }

  //dpm('total sum: '.$sum_of_pageviews);
  return $sum_of_pageviews;
}

/**
 * Return a list of paths that are aliased with the given path (including the given path).
 */
function _google_analytics_counter_path_aliases($node_path) {

  // Get the normal node path if it is a node.
  $node_path = drupal_get_normal_path($node_path);
  //dpm('nodepath: '.$node_path);

  // Grab all aliases.
  $aliases = array($node_path);
  $result = db_query("SELECT * FROM {url_alias} WHERE source = :source", array(':source' => $node_path));
  foreach ($result as $row) {
    $aliases[] = $row->alias;
  }

  // If this is the front page, add the base path too, and index.php for good measure. There may be other ways that the user is accessing the front page but we can't account for them all.
  if ($node_path == variable_get('site_frontpage', 'node')) {
    $aliases[] = '';
    $aliases[] = '/';
    $aliases[] = 'index.php';
  }

  return $aliases;
}

/**
 * Request report data.
 *
 * @param $params
 *   An associative array containing:
 *   - profile_id: required [default=variable_get('google_analytics_counter_profile_id')]
 *   - metrics: required.
 *   - dimensions: optional [default=none]
 *   - sort_metric: optional [default=none]
 *   - filters: optional [default=none]
 *   - segment: optional [default=none]
 *   - start_date: optional [default=GA release date]
 *   - end_date: optional [default=today]
 *   - start_index: optional [default=1]
 *   - max_results: optional [default=10,000]
 * @param $cache_options
 *   An optional associative array containing:
 *   - cid: optional [default=md5 hash]
 *   - expire: optional [default=CACHE_TEMPORARY]
 *   - refresh: optional [default=FALSE]
 */
function google_analytics_counter_report_data($params = array(), $cache_options = array()) {

  $params_defaults = array(
    'profile_id' => 'ga:' . variable_get('google_analytics_counter_profile_id', 0),
    );

  $params += $params_defaults;

  $GAFeed = google_analytics_counter_new_gafeed();
  $GAFeed->queryReportFeed($params, $cache_options);

  return $GAFeed;
}


/**
 * Get pageviews for nodes and write them either to the Drupal core table node_counter, or to the google_analytics_counter_storage table. This function is triggered by hook_cron().
 */
function google_analytics_counter_update_storage() {

  if(variable_get('google_analytics_counter_storage', 0) == 0 && module_exists('statistics')){ // See also https://www.drupal.org/node/2275575
    // Using core node_counter table.
    $storage = 'node_counter';
  }
  else {
    // Using table google_analytics_counter_storage.
    $storage = 'google_analytics_counter_storage';
  }

    // Record how long did this chunk take to process.
  $chunkprocessbegin = time();
  //dpm($chunkprocessbegin);

  // The total number of nodes.
  $dbresult = db_select('node', 'n')
  ->fields('n')
  ->execute();
  $resultcount = $dbresult->rowCount();
  //dpm('totalnodes: '.$resultcount);
  // Store it in a variable.
  variable_set('google_analytics_counter_totalnodes', $resultcount);

  // How many node counts to update one cron run.
  // We use the same chunk size as when getting paths in google_analytics_counter_update_path_counts().
  $chunk = variable_get('google_analytics_counter_chunk_to_fetch', 1000);
  // In case there are more than $chunk nodes to process, do just one chunk at a time and register that in $step.
  $step = variable_get('google_analytics_counter_node_data_step', 0);
  // Which node to look for first. Must be between 0 - infinity.
  $pointer = $step*$chunk;
  //dpm('START chunk '.$chunk);
  //dpm('START step '.$step);
  //dpm('START pointer '.$pointer);

  $dbresults = db_select('node', 'n')
  //->fields('n', array('nid','language'))
  ->fields('n', array('nid'))
  //->condition('pagepath', 'node/%', 'LIKE')
  ->range($pointer, $chunk)
  ->execute();
  foreach ($dbresults as $dbresult) {

    $path = 'node/'.$dbresult->nid;
   //dpm($path);

    // Get the count for this node (uncached)
    $sum_of_pageviews = google_analytics_counter_get_sum_per_path($path, FALSE);

    // Don't write zeroes.
    if ($sum_of_pageviews == 0) continue;

    // Write the count to the current storage table
    if ($storage == 'node_counter'){
      db_merge('node_counter')
        ->key(array('nid' => $dbresult->nid))
        ->fields(array(
          'daycount' => 0,
          'totalcount' => $sum_of_pageviews,
          'timestamp' => REQUEST_TIME,
        ))
        ->execute();
    }
    else {
      db_merge('google_analytics_counter_storage')
        ->key(array('nid' => $dbresult->nid))
        ->fields(array(
          'pageview_total' => $sum_of_pageviews,
        ))
        ->execute();
    }

  }

  // Set the pointer.
  $pointer += $chunk;
  //dpm('END pointer: '.$pointer);

  //dpm('step: '.$step.' | '.$pointer . ' out of total ' .$resultcount);
  watchdog(t('Google Analytics Counter'), t('Attempted updating %dbresults records in table '.$storage.' from Google Analytics data %first-%second.', array('%dbresults' => $dbresults->rowCount(), '%first' => ($pointer-$chunk+1), '%second' => ($pointer-$chunk+$dbresults->rowCount()))), NULL, WATCHDOG_INFO);

  // OK now increase or zero $step
  if ($pointer < $resultcount) {
    // If there are more results than what we've reached with this chunk, increase step to look further during the next run.
    $newstep = $step+1;
    //dpm('step +1: '.$newstep);
  }
  else {
    $newstep = 0;
    //dpm('step zero: '.$newstep);
  }
  //dpm('newstep: '.$newstep);
  variable_set('google_analytics_counter_node_data_step', $newstep);

  // Record how long did this chunk take to process.
  variable_set('google_analytics_counter_chunk_node_process_time', time()-$chunkprocessbegin);

}
