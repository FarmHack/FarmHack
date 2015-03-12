$(function(){

   App.Router = new (Backbone.Router.extend({

      routes:{
        '': 'home',
      },

      home: function() {

        $('.main-region').html('')

        var frontPageBanner = new App.Views.FrontPageBanner()
        frontPageBanner.render()
        $('.main-region').append(frontPageBanner.el)

        var featuredToolsCollection = new App.Collections.FeaturedTools()
        // @todo fake data for now
        // featuredToolsCollection.fetch()
        featuredToolsCollection.models = [
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
          new App.Models.Tool({name: 'Foo', image: 'images/biodiesel.jpg', description: 'Lorem Ipsum.'}),
        ]

        var toolCards = new App.Views.ToolCards()
        toolCards.collection = featuredToolsCollection
        toolCards.render()
        $('.main-region').append(toolCards.el)

      }

  }))

})
