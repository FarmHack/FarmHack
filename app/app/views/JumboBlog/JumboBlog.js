$(function() {

  App.Views.JumboBlog = Backbone.View.extend({

    className: "jumbo-blog col-sm-5",

    template: _.template($('#template-jumbo-blog').html()),

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
