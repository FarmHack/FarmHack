$(function () {

    App = {
      Views: {},
      Collections: {},
      Models: {},
      start: function() {
        Backbone.history.start({ pushState: false })
        // @todo Manage layout, maintain padding of main region given width of
        // the fixed right and left region widths.
      }
    }
})
