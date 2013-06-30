$(function() {

  App.Views.Node = Backbone.View.extend({

    template : function() {
      return $("#template-Node").html()
    },

    render: function () {
      this.$el.append(_.template(this.template(), this.model.toJSON()))
    }
  })

})
