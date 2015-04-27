$(function() {

  App.Views.NavBar = Backbone.View.extend({

    className: 'hidden-md hidden-lg hidden-xl',

    template: `
        <nav class="navbar navbar-inverse navbar-fixed-top">
          <div class="container">
            <div class="navbar-header">
              <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
              </button>
              <a class="navbar-brand" href="#">Farm Hack</a>
            </div>
            <div id="navbar" class="collapse navbar-collapse">
              <ul class="nav navbar-nav">
                <li class="active"><a href="#">Home</a></li>
                <li><a href="/tools">Tools</a></li>
                <li><a href="/wiki/getting-started">Getting Started</a></li>
                <li><a href="/forum">Forum</a></li>
                <li><a href="/shops">Shops</a></li>
                <li><a href="/people">People</a></li>
                <li><a href="/user/register">Sign up</a></li>
                <li><a href="/user">Log in</a></li>
              </ul>
            </div><!--/.nav-collapse -->
          </div>
        </nav>
        <div class='nav-floateys'>
        </div>
  `,

    render: function() {
      this.$el.append(this.template)
    }

  })

})
