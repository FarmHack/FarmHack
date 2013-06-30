$(function() {

  App.Models.Comment = Backbone.Model.extend({

    idAttribute: "cid",

    url: function() {
      // No REST API for comments
      return 'api'
    }

  })

})
