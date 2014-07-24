$(function() {

  App.Views.Node = Backbone.View.extend({

    template : function() {
      return $("#template-Node").html()
    },

    typeMap: {
      opentools_tool: {
        name: "TOOL",
        color: "brown"
      },
      wiki: {
        name: "WIKI",
        color: "blue"
      },
      organization: {
        name: "OPEN SHOP",
        color: "purple"
      },
      user_profile: {
        name: "FARM HACKER",
        color: "orange"
      },
      event: { 
        name: "EVENT",
        color: "#ffee2b"//"#f7e950"
      },
      page: {
        name: "PAGE",
        color: "black"
      },
      forum: {
        name: "FORUM TOPIC",
        color: "red"
      },
      blog: {
        name: "BLOG",
        color: "red"
      }
    },

    className: "activity-item",

    render: function () {
      var vars = this.model.toJSON()
      vars.changed = moment(vars.changed, "X").format("MMMM D h:mma")
      //vars.typeColor = this.typeMap[this.model.get('type')].color
      vars.typeColor = ''
      vars.typeName = this.typeMap[this.model.get('type')].name
      this.$el.append(_.template(this.template(), vars))
    }

  })

})
