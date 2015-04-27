$(function() {

  App.Views.PillarMenu = Backbone.View.extend({

    className: 'pillar-menu affix affix-top',

    template: ` \
      <div class="menu-item faq"> \
        <a href="#faq"> \
          <span class="glyphicon glyphicon-question-sign icon" aria-hidden="true"></span> <br> \
          FAQ \
        </a> \
      </div> \
      <div class="menu-item hacks"> \
        <a href="#hacks"> \
          <span class="glyphicon glyphicon-wrench icon" aria-hidden="true"></span> <br> \
          Hacks \
        </a> \
      </div> \
      <div class="menu-item meet-ups"> \
        <a href="#meet-ups"> \
          <span class="glyphicon glyphicon-calendar icon" aria-hidden="true"></span> <br> \
          Meet Ups \
        </a> \
      </div> \
      <div class="menu-item meet-ups"> \
        <a href="#forum"> \
          <span class="glyphicon glyphicon-comment icon" aria-hidden="true"></span> <br> \
          Forum \
        </a> \
      </div> \
      <div class="menu-item groups"> \
        <a href="#groups"> \
          <span class="glyphicon glyphicon-user icon" aria-hidden="true"></span> <br> \
          Groups \
        </a> \
      </div>`,

    render: function() {
      this.$el.append(this.template)
    }

  })

})
