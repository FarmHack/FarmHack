$(function() {
  App.Views.RecentActivity = Backbone.View.extend({

    className: "recent-activity",

    models: {},

    addOne: function(model){
      var item = new App.Views[model.view]({model: model})
      item.render()  
      this.$el.append(item.el)
    },

    addAll: function(){
      _.each(this.models, this.addOne())
    },

    render: function() {
      var that = this
      this.nodes.each(function(node){
        that.models[node.changed] = node
        that.models[node.changed].view = 'Node'
      })
      this.comments.each(function(comment){
        that.models[comment.changed] = comment
        that.models[comment.changed].view = 'Comment'
      })
      this.addAll()
    }

  })

})


