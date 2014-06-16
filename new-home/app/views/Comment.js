$(function() {

  App.Views.Comment = Backbone.View.extend({

    className: "activity-item",

    render: function () {
      var vars = this.model.toJSON()
      vars.created = moment(vars.created, "X").format("MMMM D h:mma")
      this.$el.append(_.template($("#template-Comment").html(), vars))
    }
    
  })

})
