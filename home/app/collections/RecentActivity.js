$(function() {

	// This Collection is a Collection of Collections
  App.Collections.RecentActivity = Backbone.Collection.extend({
    fetch: function() {
      var recentActivity = this
      var comments = new App.Collections.Comments()
      var nodes = new App.Collections.Nodes()
      nodes.on('sync', function() {
        recentActivity.add(nodes.models)
        recentActivity.trigger('sync')
      })
      comments.on('sync', function(){
        recentActivity.add(comments.models)
        nodes.fetch()
      })
      // Go!
      comments.fetch()
    },
    comparator: function(model) {
      return -(model.get('changed'))
    }

  })

})
