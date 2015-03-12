$(function() {

  App.Collections.FeaturedTools = Backbone.Collection.extend({

    url: '/ajax/homepage-view',

    model: App.Models.Tool,

    parse: function(response) {
      var nodes = _.map(response.nodes, function(row) {
        return row.node
      })
      return docs
    },

  })

})
