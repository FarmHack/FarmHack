$(function() {

  App.Views.Node = Backbone.View.extend({

    template : function() {
      return $("#template-CollectionRow").html()
    },

    render: function () {
      var vars = this.model.toJSON()
      vars.sendToDevice = '/hubble/_design/hubble-local/index.html#collections/add/' + 
          location.hostname + 
          (location.port && ":" + location.port) +
          this.model.get('database') 
      this.$el.append(_.template(this.template, vars))
    }
  })

})
