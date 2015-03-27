
$(function() {

  App.Views.FarmHackMovie = Backbone.View.extend({

    className: 'farm-hack-movie pull-left',

    template: _.template(' \
        <iframe src="//player.vimeo.com/video/73504647?portrait=0" width="600" height="337" frameborder="0" webkitallowfullscreen="" mozallowfullscreen="" allowfullscreen=""></iframe> \
    '),

    render: function () {
      this.$el.append(this.template())
    }

  })

})
