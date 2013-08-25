$(function() {
  App.Views.UpcomingEvents = Backbone.View.extend({

    template: $('#template-block-Upcoming-Events').html(),

    addOne: function(model){
      var item = new App.Views.Node({model: model})
      item.render()  
      this.$el.children('.content').append(item.el)

    },

    addAll: function(){
      _.each(this.collection.models, this.addOne, this)
    },

    render: function() {
      this.$el.html(_.template(this.template))
      this.addAll()
    }

  })

})


