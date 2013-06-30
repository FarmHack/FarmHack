$(function() {

  App = new (Backbone.View.extend({

    Models: {},
    Views: {},
    Collections: {},

    start: function(){
      this.renderJumboTron()
      this.renderRecentActivity()
    },

    renderJumboTron: function () {
      $.getJSON('/api/user', function(user) {
        if (user.uid == 0) {
          // @todo I could simplify this using transparency instead of tricky hides and css?
          $('#jumbotron').hide()
          $('#jumbotron').html($('#jumbotron-anonymous').html())
          $('#jumbotron .frame').hide()
          $('#jumbotron .content').hide()
          $('#jumbotron').show()
          $('#jumbotron .frame').css('height', '210px')
          $('#jumbotron .frame').delay(500).slideDown(700)
          $('#jumbotron .content').delay(1200).fadeIn()
        }
        else {
          $('#jumbotron').html("<h1 style='display:none; margin:0;' class='content'>Welcome back " + user.name + "</h1>")
          $('#jumbotron .content').delay(500).fadeIn()
        }
      })
    },

    renderRecentActivity: function() {
      var comments = new App.Collections.Comments()
      var nodes = new App.Collections.Nodes()
      comments.fetch()
      nodes.on('sync', function() {
        $('.recent-activity').hide()
        var recentActivity = new App.Views.RecentActivity({nodes:nodes,comments:comments})
        recentActivity.render()
        $('.recent-activity').fadeIn(1000)
        //$('.recent-activity').html(recentActivity.el)
      })
      comments.on('sync', function(){
        nodes.fetch()
      })
    }

  }))
  
})