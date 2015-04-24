$(function(){

   App.Router = new (Backbone.Router.extend({

      routes:{
        '': 'home2',
        'home2': 'home2'
      },

      home: function() {

        // Declare View instances
        var toolCardsView = new App.Views.ToolCards()
        var allInOneBannerView = new App.Views.AllInOneBanner()
        var farmHackMovieView = new App.Views.FarmHackMovie()
        var blogView = new App.Views.JumboBlog()

        // Give the Views data
        toolCardsView.collection = new App.Collections.FeaturedTools()
        blogView.collection = new App.Collections.Blogs()

        // Assign View instances to Regions
        $('.main-region').html('')
        $('.main-region').append(allInOneBannerView.el)
        $('.main-region').append(farmHackMovieView.el)
        $('.main-region').append(blogView.el)
        $('.main-region').append('<img src="images/hr.png" width=990 style="margin: 15px 0px 15px;">')
        $('.main-region').append(toolCardsView.el)

        // Render
        allInOneBannerView.render()
        farmHackMovieView.render()
        blogView.render()
        toolCardsView.render()

      },

      home2: function() {

        // Declare View instances
        var toolCardsView = new App.Views.ToolCards()
        var allInOneBannerView = new App.Views.AllInOneBanner()
        var farmHackMovieView = new App.Views.FarmHackMovie()
        var blogView = new App.Views.JumboBlog()
        var searchForm = new App.Views.SearchForm()

        // Give the Views data
        toolCardsView.collection = new App.Collections.FeaturedTools()
        blogView.collection = new App.Collections.Blogs()

        // Assign View instances to Regions
        $('.main-region').html('')
        $('.main-region').append(allInOneBannerView.el)
        $('.main-region').append(farmHackMovieView.el)
        $('.main-region').append(blogView.el)
        $('.main-region').append('<img src="images/hr.png" width=990 style="margin: 15px 0px 15px;">')
        $('.main-region').append(searchForm.el)
        $('.main-region').append(toolCardsView.el)

        // Render
        allInOneBannerView.render()
        farmHackMovieView.render()
        blogView.render()
        toolCardsView.render()
        searchForm.render()

      }

  }))

})
