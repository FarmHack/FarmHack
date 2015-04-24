$(function() {

  App.Views.SearchForm = Backbone.View.extend({

    events: {
      'click button': 'submit',
    },

    template: $('#template-search-form').html(),

    render: function() {
      this.$el.append(this.template)
    },

    submit: function() {
      window.location.href = '/search/tools/' + this.$el.find('.tool-search-text').val()
    }
  })

})
