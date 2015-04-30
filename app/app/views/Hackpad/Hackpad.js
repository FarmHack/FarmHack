$(function() {

  App.Views.Hackpad = Backbone.View.extend({

    className: "hackpad",

    template: _.template($('#template-hackpad').html()),

    render: function () {
//      this.model.on('sync', function() {
        var vars = this.model.toJSON()
        this.$el.append(this.template(vars))
  //    }, this)
 //     this.model.fetch()
    }

  })

})
