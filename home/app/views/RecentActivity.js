$(function() {
  App.Views.RecentActivity = Backbone.View.extend({

    models: {},

    tagName: "div",

    addOne: function(model){
      var item = new App.Views[model.view]({model: model})
      item.render()  
      this.$el.append(item.el)
    },

    addAll: function(){
      _.each(this.models, this.addOne)
    },

    render: function() {
      var models = {}
      this.options.nodes.each(function(node){
        models[node.get('changed')] = node
        models[node.get('changed')].view = 'Node'
      })
      this.options.comments.each(function(comment){
        models[comment.get('changed')] = comment
        models[comment.get('changed')].view = 'Comment'
      })
      this.models = models
      this.addAll()
    }

  })

})


