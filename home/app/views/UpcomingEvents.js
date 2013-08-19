$(function() {
  App.Views.UpcomingEvents = Backbone.View.extend({

    addOne: function(model){
      var item = new App.Views.Node({model: model})
      item.render()  
      this.$el.append(item.el)

    },

    addAll: function(){
      _.each(this.collection.models, this.addOne, this)
    },

    render: function() {
      this.addAll()
    }

  })

})


