$(function() {

  App.Views.NavBar = Backbone.View.extend({

    className: 'hidden-md hidden-lg hidden-xl',

    template: $('#template-nav-bar').html(),

    render: function() {
      this.$el.append(this.template)
    }

  })

})
