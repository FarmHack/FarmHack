$(function() {

  App.Views.FrontPageBanner = Backbone.View.extend({

    template: '<p style="text-align: left; margin-left: 20px;margin-bottom: 15px;" class="logo"> <img src="images/farm-hack-logo.png"></p>',

    render: function() {
      this.$el.append(this.template)
    }

  })

})
