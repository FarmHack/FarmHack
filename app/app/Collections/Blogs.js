$(function() {

  App.Collections.Blogs = Backbone.Collection.extend({
    //url: "http://dev.farmhack.gotpantheon.com/api/blogs",
    url: "/api/blogs/recent",
    model: App.Models.Blog
  })

})
