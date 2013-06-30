$(function() {

  App.Collections.Nodes = Backbone.Collection.extend({

    url: "/api/nodes/changed",
/*
    parse: function(response) {
      var docs = _.map(response.rows, function(row) {
        return row.doc
      })
      return docs
    },
 */    
    model: App.Models.Node,

  })

})
