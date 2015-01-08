#FREELINKING README.md


## CONTENTS OF THIS FILE

* Introduction
* Recommended modules
* Installation
* Usage
* Indicators
* API
* Related modules
* Troubleshooting
* Maintainers


## INTRODUCTION

Freelinking implements a filter for the easier creation of HTML links
to other pages in the site or external sites with a wiki style format
such as [[indicator:identifier]].

For example: `[[nodetitle:Page One]]` becomes:

    <a href="/node/1" title="Page One" class="freelink freelink-nodetitle freelink-internal">Page One</a>

Note that there must be no space after the colon after the indicator.

If nodetitle is the default indicator and the title contains a colon,
make sure you spell out the indicator.
E.g.: `[[nodetitle:Title with: colon]]`.

Freelinking comes with a number of sample plugins (Google search,
Drupal search, Drupal projects, Wikipedia, etc.).

There is a framework that allow developers to add new plugins. Read
PLUGIN.txt for more instructions regarding how to add new plugin.


## RECOMMENDED MODULES

* [Markdown filter][1]:<br>
  When this module is enabled, display of the project's `README.md` will be
  rendered with markdown when you visit `/admin/help/freelinking_prepopulate`.


## INSTALLATION

1. Install as you would normally install a contributed drupal
   module. See: [Installing modules][2] for further information.
2. Optionally configure the module at Configuration > Content
   authoring > Freelinking settings
3. Go to Configuration > Text Formats and activate Freelinking filter
   at Filtered HTML and Full HTML filters.
4. Clean the cache.
5. Edit a node or open a new one and type in the body the above
   example to verify that it works.


## USAGE

The link format to use can be set on the FreeLinking configuration
page. The default format is:

    [[indicator:target|title|tooltip|arg1|arg2|...]]

Everything *except* the target is optional. If you do not specity a
indicator the default one configured at Freelinking Settings page will
be used.


## INDICATORS

There are four built-in indicators. Some of them will not generate links.

These are:

Nowiki: 

`[[nowiki:this is not a freelink]]` becomes:

    [[this is not a freelink]]

It will strip the nowiki-indicator and show the rest verbatim.

Showtext:

`[[showtext:this is not a freelink]]` becomes:

    this is not a freelink

It is similar to `nowiki`, but will also strip double brackets before
showing the text.

Redact: 

`[[redact:sensitive stuff]]` becomes:

    sensitive stuff

for logged in users, and 

    ******

for anonymous users.

The redact filter works like `showtext` for logged in users, but will
redact the content of marked up content before showing it to the
anonymous user.

External link:

`[[https://groups.drupal.org/frontpage]]` becomes:

    <a class="freelink freelink-external" title="Link to groups.drupal.org." href="https://groups.drupal.org/frontpage">groups.drupal.org</a>

In addition to these, the project comes with a small set of plugin
filters bundled.  These are in the subdirectory `plugins` of the
project.

These are listed below.

Nodetitle - `freelinking_nodetitle.inc`

`[[nodetitle:First page]]` becomes:

    <a class="freelink freelink-nodetitle freelink-internal" title="node/1" href="/node/1">test</a>

Notes: If you have two nodes with the same title, there is no way to control what node is linked to. 
If you change the title of the page linked to, the freelink will no longer work.

Node nid - `freelinking_nid.inc`

`[[nid:2]]` becomes:

    <a class="freelink freelink-nid freelink-internal" title="node/2" href="/node/2">First page</a>

User profile - `freelinking_user.inc`

`[[user:1]]` becomes:

    <a class="freelink freelink-user freelink-internal" title="user/1" href="/user/1">admin</a>

`[[user:admin]]` becomes:

    <a class="freelink freelink-user freelink-internal" title="user/1" href="/user/1">admin</a>

File - `freelinking_file.inc`

`[[file:logo.png]]` becomes

    <a class="freelink freelink-file freelink-internal" href="http://<siteroot>/sites/default/files/logo.png">logo.png</a>

Search - `freelinking_search.inc`

`[[search:test]]` becomes:

    <a class="freelink freelink-search freelink-internal" title="search/node/test" href="/search/node/test">test</a>

`[[google:drupal]]` becomes:

    <a class="freelink freelink-google freelink-external" title="http://www.google.com/search" href="http://www.google.com/search?q=drupal&hl=en">Google Search "drupal"</a>

Drupal.org - `freelinking_dev.inc`

`[[drupalproject:freelinking]]` becomes

    <a class="freelink freelink-drupalproject freelink-external" href="http://drupal.org/project/freelinking">freelinking</a>

`[[drupalorg:1]]` becomes

    <a class="freelink freelink-drupalorgnid freelink-external" href="http://drupal.org/node/1">Drupal.org: "About Drupal"</a>

Wikipedia, etc. - `freelinking_wiki.inc`

`[[wikipedia:Main Page]]` becomes:

    <a class="freelink freelink-wikipedia freelink-external" href="http://en.wikipedia.org/wiki/Main_Page">Main_Page</a>

The indicators supported by this plugin are: `wikibooks`, `wikipedia`,
`wikinews`, `wikiquote`, `wikisource` and `wiktionary`.


## API

For API functions and examples of their use, see
`freelinking.api.php`.


## RELATED MODULES

* The Freelinking distribution includes the Freelinking Prepopulate
  submodule that provides a plugin to create new nodes. Nodetitle may
  use this a fallback to provide links to create content that does not
  exist. This submodule requires Prepopulate.


## TROUBLESHOOTING

If you do not see freelinking working at all. There must be some
conflict with other input formats. Try first to disable all other
input formats and only leave Freelinking activated.  Clean the cache
and then test editing a node with a freelink and save it. If it works,
try adding other input formats until you get to the right order in
which they have to be in order to work correctly.


## MAINTAINERS

* [eafarris](https://www.drupal.org/user/812) (original creator)
* [grayside](https://www.drupal.org/u/grayside)
* [juampy](https://www.drupal.org/u/juampy)
* [gisle](https://www.drupal.org/u/gisle) (current maintainer)

Any help with development (patches, reviews, comments) are welcome.


[1]: https://www.drupal.org/project/markdown
[2]: https://drupal.org/documentation/install/modules-themes/modules-7