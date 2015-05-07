$(function() {

  App.Views.Statement = Backbone.View.extend({

    className: 'statement col-sm-7',

    template: ' \
          <p class="section-description hand-written"> \
            We are a worldwide community of farmers that build and modify our own tools. \
            We share our hacks <a href="/tools">online</a> and at <a href="/calendar">meet ups</a> \
            because we become better farmers when we work together. \
            <a href="/wiki/getting-started">See our movie.</a> \
          </p> ',

    render: function() {
      this.$el.append(this.template)
    }

  })

})
