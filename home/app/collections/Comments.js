$(function() {

  App.Collections.Comments = Backbone.Collection.extend({
    url: "/api/comments/changed",
    model: App.Models.Comment
  })

})
