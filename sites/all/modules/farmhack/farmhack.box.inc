<?php
/**
 * @file
 * farmhack.box.inc
 */

/**
 * Implements hook_default_box().
 */
function farmhack_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'farmhack_about';
  $box->plugin_key = 'simple';
  $box->title = 'What is Farm Hack?';
  $box->description = 'About Farm Hack';
  $box->options = array(
    'body' => array(
      'value' => 'FarmHack is a community for those who embrace the long-standing farm traditions of tinkering, inventing, fabricating, tweaking, and improving things that break. We are farmers of all ages, but the project has special relevance to young and beginning farmers as a place to learn from their peers\' and their elders\' successes, mistakes and new ideas.
We also seek to bring our non-farmer allies on board: engineers, architects, designers, and the like. Together, with an open-source ethic, we can retool our farms for a sustainable future.
',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['farmhack_about'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'upcomingfarmhack_temp';
  $box->plugin_key = 'simple';
  $box->title = 'Upcoming Farmhacks';
  $box->description = 'Upcoming Farmhacks temp';
  $box->options = array(
    'body' => array(
      'value' => '<style>

.fm_block_wrap {
	padding:10px;
}
.fm_upcoming_strip {
	background:url(images/fm_box.jpg) repeat-x;
	height:5px;
}
.fm_upcoming_in {
	background:#f8ef27;
	margin: 3px 0;
	padding: 5px 10px
}
#fm_upcoming_bk {
	
}
#fm_upcoming_bk h3 {
	font-size: 22px;
	font-weight: normal;
	margin: 0 0 10px;
	padding: 0;
}
.fm_upc_item {
	font-size:13px;
	padding:3px 0;
	position:relative;
}
.fm_upc_date {
    float: left;
    padding-left: 6px;
    width: 152px;
}
.fm_upc_title {
	width: 375px;
	float:left;
}
.fm_upc_time {
	float: left;
	width: 150px;
	padding-left:10px;
}
.fm_upc_fcs {
	width:auto;
	float:left;
	width: 184px;
}
</style>

<div id="fm_upcoming_bk">
     <div class="fm_upcoming_strip"> </div>
        <div class="fm_upcoming_in">
        <div id="text-15" class="fm_widget widget_text">			<div class="textwidget"><div class="fm_upc_item">
<div class="fm_upc_arrow"></div>
          <div class="fm_upc_date">
           MARCH 10+11, 2012
          </div>
          <div class="fm_upc_title">
           <a href="http://www.youngfarmers.org/practical/farm-hack/risd/" <span="">FARM HACK/RISD in Rhode Island
          </a></div><a href="http://www.youngfarmers.org/practical/farm-hack/risd/" <span="">
          </a><div class="fm_upc_time"><a href="http://www.youngfarmers.org/practical/farm-hack/risd/" <span="">
          Click for details</a>
          </div>
          <div class="fm_upc_fcs">
           FOCUS:INDUSTRIAL DESIGN + ARCHITECTURE
          </div>
          <div class="clear"></div>
        </div>
<div class="fm_upc_item">
<div class="fm_upc_arrow"></div>
          <div class="fm_upc_date">
          APRIL 28+29, 2012
          </div>
          <div class="fm_upc_title">
           <span><a href="http://www.youngfarmers.org/practical/farm-hack/intervale/">FARM HACK</a></span><a href="http://www.youngfarmers.org/practical/farm-hack/intervale/">/INTERVALE in Burlington, VT / Essex, NY
          </a></div><a href="http://www.youngfarmers.org/practical/farm-hack/intervale/">
          </a><div class="fm_upc_time"><a href="http://www.youngfarmers.org/practical/farm-hack/intervale/">
          Click for details</a>
          </div>
          <div class="fm_upc_fcs">
           FOCUS: TOOLS
          </div>
          <div class="clear"></div>
        </div> 
        
        <div class="fm_upc_item">
<div class="fm_upc_arrow"></div>
          <div class="fm_upc_date">
           SPRING 2012
          </div>
          <div class="fm_upc_title">
           <span>FARM HACK</span>/STANFORD in California
          </div>
          <div class="fm_upc_time">
          Details soon
          </div>
          <div class="fm_upc_fcs">
           FOCUS:TOOLS
          </div>
          <div class="clear"></div>
        </div></div>
		</div>    


    
     </div>
      <div class="fm_upcoming_strip"> </div>
    </div>',
      'format' => 'php_code',
    ),
  );
  $export['upcomingfarmhack_temp'] = $box;

  return $export;
}
