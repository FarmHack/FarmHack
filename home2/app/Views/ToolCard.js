$(function() {

  App.Views.ToolCard = Backbone.View.extend({

    template : _.template(' \
      <div class="col-sm-4"> \
        <div class="thumbnail"> \
          <img src="<%= image %>" alt="..."> \
          <div class="caption"> \
           <h3><%= name %></h3> \
            <p><%= description %></p> \
          </div> \
        </div> \
      </div>'),

    render: function () {
      var $output = this.template(this.model.toJSON())
      this.$el.append($output)
    },

  })

})
