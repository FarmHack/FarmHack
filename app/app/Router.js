$(function(){

   App.Router = new (Backbone.Router.extend({

      routes:{
        '': 'home',
        'tool/:id': 'tool'
      },

      home: function() {

        // Declare View instances
        var toolCardsView = new App.Views.ToolCards()
        var allInOneBannerView = new App.Views.AllInOneBanner()
        var statementView = new App.Views.Statement()
        var blogView = new App.Views.JumboBlog()
        var searchForm = new App.Views.SearchForm()
        var navBarView = new App.Views.NavBar()

        // Give the Views data
        toolCardsView.collection = new App.Collections.FeaturedTools()
        blogView.collection = new App.Collections.Blogs()

        // Assign View instances to Regions
        $('body').prepend(navBarView.el)
        $('.main-region').html('')
        $('.main-region').append(allInOneBannerView.el)
        $('.main-region').append(statementView.el)
        $('.main-region').append(blogView.el)
        $('.main-region').append('<img class="hidden-sm hidden-xs" src="images/hr.png" width=990 style="margin: 15px 0px 15px;">')
        $('.main-region').append(searchForm.el)
        $('.main-region').append(toolCardsView.el)

        // Render
        allInOneBannerView.render()
        statementView.render()
        blogView.render()
        toolCardsView.render()
        searchForm.render()
        navBarView.render()

      },

      tool: function(toolId) {
        var tool = new App.Models.Tool()
        tool.set('hackpadId', toolId)
        tool.set('title', 'test')
        var hackpadView = new App.Views.Hackpad({model: tool})

        $('.main-region').html('')
        $('.main-region').append(hackpadView.el)

        hackpadView.render()

      }

  }))

})
