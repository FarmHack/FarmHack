$(function() {

  App.Collections.Nodes = Backbone.Collection.extend({
    url: "/api/nodes/changed",
    model: App.Models.Node,

    comparator: function(node) {
      return -(node.get('changed'))
    },
  })

})
