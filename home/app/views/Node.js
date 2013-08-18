$(function() {

  App.Views.Node = Backbone.View.extend({

    template : function() {
      return $("#template-Node").html()
    },

    className: "activity-item",

    render: function () {
      var vars = this.model.toJSON()
      vars.changed = moment(vars.changed, "X").format("MMM D h:mma")
      this.$el.append(_.template(this.template(), this.model.toJSON()))
    }
  })

})
