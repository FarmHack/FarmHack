$(function() {

  App.Views.JumboBlog = Backbone.View.extend({

    className: "jumbo-blog pull-right",

    template: _.template('  \
        <div class="activity-type"> \
          BLOG  \
        </div> \
        <center><img class="img-responsive" src="/sites/default/files/<%= fileName %>"></center> \
        <div class="activity-body"> \
          <a href="/node/<%= nid %>"><%= title %></a> \
        </div> \
        <div class="activity-by-line"> \
          <% if (userPhotoFileName) { %> \
            <div class="activity-user-photo"> \
              <img height=35 src="http://farmhack.net/sites/default/files/styles/thumbnail/public/pictures/<%= userPhotoFileName %>"> \
            </div> \
          <% } %> \
          by <a href="/user/<%= uid %>"><%= name %></a> <br/> \
          on <%= changed %> \
        </div> \
      '),

    render: function () {
      this.collection.on('sync', function() {
        var blogModel = this.collection.models[0]
        var vars = blogModel.toJSON()
        vars.created = moment(vars.created, "X").format("MMMM D h:mma")
        vars.changed = moment(vars.changed, "X").format("MMMM D h:mma")
        vars.fileName = blogModel.attributes.field_main_image.und[0].filename
        vars.typeName = "RECENT BLOG"
        this.$el.append(this.template(vars))
      }, this)
      this.collection.fetch()
    }

  })

})
