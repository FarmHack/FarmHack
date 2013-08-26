$(function() {

  App.Collections.Events = Backbone.Collection.extend({
    url: "/api/events",
    model: App.Models.Node,
    comparator: function(node) {
      return -(node.get('changed'))
    },
  })

})
