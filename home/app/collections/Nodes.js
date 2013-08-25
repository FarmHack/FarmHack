$(function() {

  App.Collections.Nodes = Backbone.Collection.extend({
    url: "http://test.farmhack.gotpantheon.com/api/nodes/changed",
    model: App.Models.Node,

    comparator: function(node) {
      return -(node.get('changed'))
    },
  })

})
