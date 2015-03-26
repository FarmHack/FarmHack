$(function() {

  App.Collections.UpcomingEvents = Backbone.Collection.extend({
    url: "/api/events/upcoming",
    model: App.Models.Node,
    comparator: function(node) {
      return -(node.get('changed'))
    },
  })

})
