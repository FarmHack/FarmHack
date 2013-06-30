$(function() {

  App.Collections.Comments = Backbone.Collection.extend({

    url: "/api/comments/changed",
/*
    parse: function(response) {
      var docs = _.map(response.rows, function(row) {
        return row.doc
      })
      return docs
    },
 */    
    model: App.Models.Comments,

  })

})
