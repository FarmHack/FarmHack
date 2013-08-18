$(function() {

  App.Views.Comment = Backbone.View.extend({

    className: "activity-item",

    render: function () {
      var vars = this.model.toJSON()
      vars.created = moment(vars.created, "X").format("MMMM D h:mma")
      this.$el.append(_.template($("#template-Comment").html(), vars))
      //$('.recent-activity').append(_.template(this.template(), this.model.toJSON()))

      /*
      var template = $("#template-Comment").html()
      var vars = {"subject":"yar"}
      var $el = _.template(template, vars)
      $('.recent-activity').append($el)

      var template = $("#template-Comment").html()
      var model = this.model.toJSON()
      var vars = {subject: model.subject}
      var $el = _.template(template, vars)
      $('.recent-activity').append($el)
      */
    }
  })

})
