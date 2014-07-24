$(function() {

  App.Views.JumboBlog = Backbone.View.extend({

    className: "activity-item",

    template: $("#template-JumboBlog").html(),

    render: function () {
      var vars = this.model.toJSON()
      vars.created = moment(vars.created, "X").format("MMMM D h:mma")
      vars.changed = moment(vars.changed, "X").format("MMMM D h:mma")
      vars.fileName = this.model.attributes.field_main_image.und[0].filename
      this.$el.append(_.template(this.template, vars))
    }
    
  })

})
