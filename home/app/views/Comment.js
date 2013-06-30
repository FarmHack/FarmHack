$(function() {

  App.Views.Comment = Backbone.View.extend({

    template : function() {
      return $("#template-Comment").html()
    },

    render: function () {
      this.$el.append(_.template(this.template(), this.model.toJSON))
    }
  })

})
