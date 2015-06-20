$(function() {

  App.Views.AllInOneBanner = Backbone.View.extend({

    className: 'hidden-sm hidden-xs',

    template: ' \
      <div style="text-align:center; width:1023px; margin-left:auto; margin-right:auto;"> \
        <img id="Image-Maps_3201309151126189" src="app/views/AllInOneBanner/AllInOneBanner.jpeg" usemap="#Image-Maps_3201309151126189" border="0" width="1023" height="176" alt="" /> \
        <map id="_Image-Maps_3201309151126189" name="Image-Maps_3201309151126189"> \
        <area shape="rect" coords="3,11,61,46" href="/tools" alt="Tools" title="Tools"    /> \
        <area shape="rect" coords="72,11,180,46" href="/forum" alt="Discussions" title="Discussions"    /> \
        <area shape="rect" coords="184,12,278,47" href="/calendar" alt="Calendar" title="Calendar"    /> \
        <area shape="rect" coords="289,11,409,46" href="/host-an-event" alt="Host to an event" title="Host to an event"    /> \
        <area shape="rect" coords="415,11,480,46" href="/shops" alt="Open Shops" title="Open Shops"    /> \
        <area shape="rect" coords="486,12,561,47" href="/people" alt="People" title="People"    /> \
        <area shape="rect" coords="629,3,717,95" href="/donate" alt="donate" title="donate"    /> \
        <area shape="rect" coords="930,15,961,48" href="http://twitter.com/#!/NYFCNYFC" alt="Contact us on Twitter" title="Contact us on Twitter"    /> \
        <area shape="rect" coords="961,14,989,47" href="http://www.facebook.com/pages/The-National-Young-Farmers-Coalition/157485677636655" alt="Contact us on Facebook" title="Contact us on Facebook"    /> \
        <area shape="rect" coords="990,13,1018,46" href="http://feeds.feedburner.com/nyfc" alt="Follow our RSS Feed" title="Follow our RSS Feed"    /> \
        <area shape="rect" coords="730,70,1005,116" href="/user" alt="Sign in or create an accout" title="Sign in or create an accout"    /> \
        <area shape="rect" coords="730,112,1005,158" href="/wiki/getting-started" alt="Guide to getting started in the Farm Hack community" title="Guide to getting started in the Farm Hack community"    /> \
        <area shape="rect" coords="637,186,1018,544" href="/shops" alt="Check out the new section, Open Shops!" title="Check out the new section, Open Shops!"    /> \
        <area shape="rect" coords="1021,567,1023,569" href="http://www.image-maps.com/index.php?aff=mapped_users_3201309151126189" alt="Image Map" title="Image Map" /> \
        </map> \
      </div> \
      <!-- Image map text links - End - --> \
      ',

    render: function() {
      this.$el.append(this.template)
    }

  })

})
