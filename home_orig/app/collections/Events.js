$(function() {

  App.Collections.Events = Backbone.Collection.extend({
    //url: "http://dev.farmhack.gotpantheon.com/api/events",
    url: "/api/events",
    model: App.Models.Node,
  })

})
