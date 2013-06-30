$(function() {

  App.Views.Comment = Backbone.View.extend({

    template : function() {
      return $("#template-Comment").html()
    },

    render: function () {
      //this.$el.append(_.template(this.template(), this.model.toJSON()))
      //$('.recent-activity').append(_.template(this.template(), this.model.toJSON()))
      var template = $("#template-Comment").html()
      var vars = this.model.toJSON()
      var $el = _.template(template, vars)
      $('.recent-activity').append($el)
    }
  })

})
