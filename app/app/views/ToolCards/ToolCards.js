$(function() {

  App.Views.ToolCards = Backbone.View.extend({

    className: "tool-cards",

    itemView: "ToolCard",

    numberOfColumns: 3,

    currentColumn: 1,

    initialize: function(){
      this.$el.html('<div style="text-align: center;"><img align="center" src="images/spinner.gif"/></div>')
    },

    addItem: function(model){
      var itemView = new App.Views[this.itemView]({model: model})
      itemView.render()
      this.$el.append(itemView.el)
      if (this.currentColumn ===  3) {
        this.endRow()
        this.startRow()
        this.currentColumn = 1
      }
      else {
        this.currentColumn++
      }
    },

    addAll: function(){
      this.collection.forEach(this.addItem, this)
    },

    render: function() {
      var view = this
      this.collection.on('sync', function() {
        this.$el.fadeOut(300)
        setTimeout(function() {
          view.$el.html('')
          view.startRow()
          view.addAll()
          view.endRow()
          view.$el.fadeIn(700)
        }, 300)
      }, this)
      this.collection.fetch()
    },

    startRow: function() {
      this.$el.append('<div class="row">')
    },

    endRow: function() {
      this.$el.append('</div> <!--/row-->')
    }

  })

})
