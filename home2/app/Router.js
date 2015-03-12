$(function(){

   App.Router = new (Backbone.Router.extend({

      routes:{
        '': 'home',
      },
      home: function() {
        var frontPageBanner = new App.Views.FrontPageBanner()
        frontPageBanner.render()
        $('.main-region').html(frontPageBanner.el)
      }
  }))

})
