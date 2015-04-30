$(function() {

  App.Views.Simple = Backbone.View.extend({

    className: "simple",

    template: _.template($('#template-simple').html()),

    render: function () {
      this.model.on('sync', function() {
        var vars = this.model.toJSON()
        this.$el.append(this.template(vars))
      }, this)
      this.model.fetch()
    }

  })

})
