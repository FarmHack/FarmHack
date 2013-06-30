$(function() {

  App.Views.Comment = Backbone.View.extend({

    render: function () {
      this.$el.append(_.template($("#template-Comment").html(), this.model.toJSON()))
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
