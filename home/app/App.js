$(function() {

  App = new (Backbone.View.extend({

    Models: {},
    Views: {},
    Collections: {},

    start: function(){
      this.renderJumboTron()
      this.renderUpcomingEvents()
      this.renderRecentActivity()

      window.onscroll = function() {
        var speed = 3.0;
        $("#top-region").css("background-position",(window.pageXOffset / speed) + "px " + (window.pageYOffset / speed) + "px");
      }
    },

    renderUpcomingEvents: function() {
      var events = new App.Collections.UpcomingEvents()
      events.on('sync', function(){
        var UpcomingEvents = new App.Views.UpcomingEvents({collection: events})
        UpcomingEvents.render()
        $('#bottom-region .row-1').html(UpcomingEvents.el)
      })
      events.fetch()
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
        $('#bottom-region .row-2').hide()
        var recentActivity = new App.Views.RecentActivity({nodes:nodes,comments:comments})
        recentActivity.render()
        $('#bottom-region .row-2').html(recentActivity.el)
        $('#bottom-region .row-2').fadeIn(800)
      })
      comments.on('sync', function(){
        nodes.fetch()
      })
    }

  }))
  
})
