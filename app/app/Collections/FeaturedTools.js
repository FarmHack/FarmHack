$(function() {

  App.Collections.FeaturedTools = Backbone.Collection.extend({

    url: '/api/tools/featured',

    model: App.Models.Tool,

    parse: function(response) {
      var nodes = _.map(response.nodes, function(row) {
        row.node.id = row.node.nid
        return row.node
      })
      return nodes
    },

  })

})
