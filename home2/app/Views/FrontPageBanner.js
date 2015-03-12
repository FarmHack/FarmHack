$(function() {

  App.Views.FrontPageBanner = Backbone.View.extend({

    template: ' \
      <p class="logo"> \
        <img src="images/farm-hack-logo.png"> \
      </p> \
      <p class="slogan"> \
        We are a worldwide community of farmers that build and modify our own tools. \
        We share our hacks <a href="#hacks">online</a> and at <a href="#meet-ups">meet ups</a> \
        because we become better farmers when we work together. \
      </p>',

    render: function() {
      this.$el.append(_.template(this.template))
    }

  })

})
