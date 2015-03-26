$(function() {

  App.Views.ToolCard = Backbone.View.extend({

    template : _.template(' \
      <div class="col-sm-4"> \
        <div class="thumbnail"> \
          <img src="<%= image.src %>" alt="..."> \
          <div class="caption"> \
           <h3><%= title %></h3> \
            <p><%= body %></p> \
          </div> \
        </div> \
      </div>'),

    render: function () {
      var $output = this.template(this.model.toJSON())
      this.$el.append($output)
    },

  })

})
