$(function() {

  App.Collections.Nodes = Backbone.Collection.extend({
    //url: "http://dev.farmhack.gotpantheon.com/api/nodes/changed",
    url: "/api/nodes/changed",
    model: App.Models.Node
  })

})
