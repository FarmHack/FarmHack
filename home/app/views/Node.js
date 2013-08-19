$(function() {

  App.Views.Node = Backbone.View.extend({

    template : function() {
      return $("#template-Node").html()
    },

    typeMap: {
      opentools_tool: {
        name: "Tool",
        color: "brown"
      },
      wiki: {
        name: "Wiki Page",
        color: "blue"
      },
      organization: {
        name: "Open Shop",
        color: "purple"
      },
      user_profile: {
        name: "Farm Hacker",
        color: "orange"
      },
      event: { 
        name: "Event",
        color: "yellow"
      },
      page: {
        name: "Page",
        color: "black"
      },
      forum: {
        name: "Forum Topic",
        color: "red"
      }
    },

    className: "activity-item",

    render: function () {
      var vars = this.model.toJSON()
      vars.changed = moment(vars.changed, "X").format("MMMM D h:mma")
      vars.typeColor = this.typeMap[this.model.get('type')].color
      vars.typeName = this.typeMap[this.model.get('type')].name
      this.$el.append(_.template(this.template(), vars))
    }

  })

})
