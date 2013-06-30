$(function() {

  App.Models.Node = Backbone.Model.extend({

    idAttribute: "nid",

    url: function() {
      // No REST API for nodes
      return ''
    },

  })

})
