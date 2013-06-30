$(function() {

  App = new (Backbone.View.extend({

    Models: {},
    Views: {},
    Collections: {},

    start: function(){
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
          $('#jumbotron').hide()
          $('#jumbotron').html("<div class='frame'><h1 class='content'>Welcome back " + user.name + "</h1></div>")
          $('#jumbotron .frame').hide()
          $('#jumbotron .content').hide()
          $('#jumbotron').show()
          $('#jumbotron .frame').css('height', '80px')
          $('#jumbotron .frame').delay(500).slideDown(700)
          $('#jumbotron .content').delay(1200).fadeIn()
        }
      })
    }

  }))
  
})