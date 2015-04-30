$(function(){

   App.Router = new (Backbone.Router.extend({


      routes:{
        '': 'hacksRoute',
        'hacks': 'hacksRoute',
        'meet-ups': 'meetUpsRoute',
        'tool/:toolId': 'toolRead',
        'tool/:toolId/read': 'toolRead',
        'tool/:toolId/edit': 'toolEdit',
        'tool/:toolId/comment': 'toolComment',
        'tool/:toolId/favorite': 'toolFavorite'
      },

      toolRead: function(toolId) {
        $('#main-region').html('')
        var toolNavTpl = _.template(jQuery('#template-tool-nav').html())
        var toolReadTpl = _.template(jQuery('#template-hackpad-iframe').html())
        $('#main-region').html(toolNavTpl() + toolReadTpl())
        $('iframe.hackpad').width(window.innerWidth - 132)
        $('iframe.hackpad').height(window.innerHeight - 113)
        $('.col-xs-3 img').css('margin-right', '31px')
      },

      toolEdit: function(toolId) {

      },

      toolComment: function(toolId) {

      },

      toolFavorite: function(toolId) {
        
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

})(jQuery)
