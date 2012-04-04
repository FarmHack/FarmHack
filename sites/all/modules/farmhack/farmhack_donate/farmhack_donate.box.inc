<?php
/**
 * @file
 * farmhack_donate.box.inc
 */

/**
 * Implements hook_default_box().
 */
function farmhack_donate_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'farmhack_donate';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Farm Hack Donate';
  $box->options = array(
    'body' => array(
      'value' => '<a class="donate" href="https://org2.democracyinaction.org/o/7323/donate_page/membership">
  <img class="donate-red" src="/sites/all/modules/farmhack/farmhack_donate/images/donate-red.png">
  <img class="donate-green" src="/sites/all/modules/farmhack/farmhack_donate/images/donate-green.png">
</a>

<style>
#block-boxes-farmhack-donate {
position: absolute;
bottom: 192px;
right: 205px;
}

#block-boxes-farmhack-donate a {
position: relative;
}

#block-boxes-farmhack-donate .donate-green {
position: absolute;
top: 0px;
right; 0px; 
display: none;
z-index: 3;
}

#block-boxes-farmhack-donate .donate-red {
position: absolute;
top: 0px;
right; 0px; 
z-index:2;
}
</style>


<script>
jQuery("#block-boxes-farmhack-donate > *").hover(
  function () {
    jQuery(".donate-green").fadeIn();
  },
  function () {
    jQuery(".donate-green").fadeOut(250);
  }
);

</script>',
      'format' => 'php_code',
    ),
  );
  $export['farmhack_donate'] = $box;

  return $export;
}
