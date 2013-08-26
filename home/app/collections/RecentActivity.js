$(function() {

	// This Collection is a Collection of Collections
  App.Collections.RecentActivity = Backbone.Collection.extend({
    fetch: function() {
    	var that = this
    	var comments = new App.Collections.Comments()
      var nodes = new App.Collections.Nodes()
      nodes.on('sync', function() {
        // Merge the nodes and comments collections, then sort
        var models = {}
        nodes.each(function(node){
          models[node.get('changed')] = node
          models[node.get('changed')].view = 'Node'
        })
        comments.each(function(comment){
          models[comment.get('changed')] = comment
          models[comment.get('changed')].view = 'Comment'
        })
        var sortedModels = []
        _.each(models, function(model) {
          sortedModels.unshift(model)
        })
        that.models = sortedModels
        that.trigger('sync')
      })
      comments.on('sync', function(){
        nodes.fetch()
      })
      // Go!
      comments.fetch()
    } 

  })

})
