$(function() {
  App.Views.RecentActivity = Backbone.View.extend({

    tagName: "table",

    className: "table table-striped",

    template: $('#template-block-Recent-Online-Activity').html(),

    addOne: function(model){
      var item = new App.Views[model.view]({model: model})
      item.render()  
      this.$el.children('.content').append(item.el)
    },

    addAll: function(){
      _.each(this.models, this.addOne, this)
    },

    render: function() {
      this.$el.html(_.template(this.template))
      // Merge the nodes and comments collections
      var models = {}
      this.options.nodes.each(function(node){
        models[node.get('changed')] = node
        models[node.get('changed')].view = 'Node'
      })
      this.options.comments.each(function(comment){
        models[comment.get('changed')] = comment
        models[comment.get('changed')].view = 'Comment'
      })
      // Sort the merged collection
      var sortedModels = []
      _.each(models, function(model) {
        sortedModels.unshift(model)
      })
      this.models = sortedModels
      this.addAll()
    }

  })

})


