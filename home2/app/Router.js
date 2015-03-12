$(function(){

   App.Router = new (Backbone.Router.extend({


      routes:{
        '': 'hacksRoute',
        'hacks': 'hacksRoute',
        'meet-ups': 'meetUpsRoute',
        'tool/:toolId': 'tool'
      },

      tool: function(toolId) {
        var tpl = _.template(jQuery('#template-tool-42').html())
        $('#main-region').html(tpl())

      },

      hacksRoute: function() {
        var tpl = _.template(jQuery('#template-hacks').html())
        jQuery('#main-region').html(tpl())
        jQuery('.search-form').one('click', function() {
          jQuery('.search-form .advanced')  .css('opacity', 0)
          .slideDown('slow')
          .animate(
            { opacity: 1 },
            { queue: false, duration: 'slow' }
          );
        })
        jQuery('.see-more').one('click', function() {
          jQuery('.page2')  .css('opacity', 0)
          .slideDown('slow')
          .animate(
            { opacity: 1 },
            { queue: false, duration: 'slow' }
          );
        })
      },

      meetUpsRoute: function() {
        jQuery('#main-region').html('meet ups')
      }
  }))

})($)
