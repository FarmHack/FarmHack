$(function() {

  App.Views.ToolCard = Backbone.View.extend({

    template : _.template(' \
      <div class="col-sm-4"> \
        <div class="thumbnail"> \
          <a href="<%= link %>" alt="<%= title %>"><img src="<%= image.src %>" alt="..."></a> \
          <div class="caption"> \
           <h3><a href="<%= link %>" alt="<%= title %>"><%= title %></a></h3> \
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
