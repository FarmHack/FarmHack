$(function(){

   App.Router = new (Backbone.Router.extend({

      routes:{
        '': 'home',
      },

      home: function() {

        $('.main-region').html('')
        var featuredToolsCollection = new App.Collections.FeaturedTools()
        var toolCards = new App.Views.ToolCards()
        var frontPageBanner = new App.Views.FrontPageBanner()

        frontPageBanner.render()
        $('.main-region').append(frontPageBanner.el)

        featuredToolsCollection.on('sync', function() {
          toolCards.collection = featuredToolsCollection
          toolCards.render()
          $('.main-region').append(toolCards.el)
        })
        featuredToolsCollection.fetch()
      }

  }))

})
