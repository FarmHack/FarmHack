$(function(){

   App.Router = new (Backbone.Router.extend({

      routes:{
        '': 'home',
        'tool/:id': 'tool'
      },

      home: function() {

        // Declare View instances
        var toolCardsView = new App.Views.ToolCards()
        var frontPageBanner = new App.Views.FrontPageBanner() 
        var statementView = new App.Views.Statement()
        var blogView = new App.Views.JumboBlog()
        var searchForm = new App.Views.SearchForm()

        // Give the Views data
        toolCardsView.collection = new App.Collections.FeaturedTools()
        blogView.collection = new App.Collections.Blogs()

        // Assign View instances to Regions
        $('.main-region').html('')
        $('.main-region').append(frontPageBanner.el)
        $('.main-region').append(statementView.el)
        $('.main-region').append(blogView.el)
        $('.main-region').append('<img class="hidden-sm hidden-xs" src="images/hr.png" width=990 style="margin: 15px 0px 15px;">')
        $('.main-region').append(searchForm.el)
        $('.main-region').append(toolCardsView.el)

        // Render
        frontPageBanner.render()
        statementView.render()
        blogView.render()
        toolCardsView.render()
        searchForm.render()

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
