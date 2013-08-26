$(function() {
  App.Views.UpcomingEvents = Backbone.View.extend({

    template: $('#template--collection-view').html(),

    className: 'block block--upcoming-events',

    title: 'Upcoming Events',

    initialize: function() {
      vars = {
        title: this.title
      }
      this.$el.html(_.template(this.template, vars))
      this.$content = this.$el.children('.content')
    },

    addOne: function(model){
      var item = new App.Views.Node({model: model})
      item.render()  
      this.$el.children('.content').append(item.el)
    },

    addAll: function(){
      _.each(this.collection.models, this.addOne, this)
    },

    render: function() {
      this.$content.fadeOut(400)
      var that = this
      setTimeout(function() {
        that.$content
          .css('margin', '0px auto')
          .css('width', that.collection.models.length*320 + 'px')
          .spin(false)
        that.addAll()
        that.$content.fadeIn(800)
      }, 400)
    },

    spin: function(status) {
      if (status == null || status == true) {
        this.$content.spin()
      }
      if (status == false) {
        this.$content.spin(false)
      }
    }

  })

})


