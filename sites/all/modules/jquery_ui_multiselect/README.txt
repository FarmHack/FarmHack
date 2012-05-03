README file for the jQuery UI Multiselect module for Drupal


-- DESCRIPTION --

This module integrates the jQuery UI Multiselect plugin with existing
select list field widgets.

The jQuery plugin is demonstrated at:
http://www.quasipartikel.at/multiselect.

The advantages of this interface over regular selection lists are:

* Separate columns for selected and available items, offering a clear
  view of which items are selected, unlike regular list boxes where
  one has to scroll through the whole list to find out what is
  selected.

* Less risks of mistakenly unselecting everything. Remember ever
  having mispressed the Ctrl key in a multiselection list, losing a
  painfully crafted selection? Could not happen with this interface.

* The selection can be manually ordered with drag & drop operations
  (optional).

* The available options can be searched (live search) (optional).

* The number of selected items is displayed.

* Select All / Deselect All buttons are offered (optional).


-- HOW IT WORKS --

Instead of providing its own Field API widget, this module piggybacks
on existing field widgets through form alter hooks. That helps keep
the code simple, and free from duplication of existing widget logic.


-- SUPPORTED FIELDS --

The following fields are currently supported, when configured for the
"Select list" widget:

* Float
* Integer
* Term reference
* Text


-- REQUIREMENTS --

* jQuery UI Multiselect (jQuery plugin) (https://github.com/crdeutsch/multiselect)
* Drupal 7.x
* jQuery Update (http://drupal.org/project/jquery_update)
* Value is (http://drupal.org/project/value_is)


-- INSTALLATION AND CONFIGURATION --

1. Download and install the "jQuery Update" and "Value is" modules.
   See http://drupal.org/node/70151 for more information about module
   installation.

2. Download the jQuery UI Multiselect plugin from GitHub.

   The original repository is no longer being updated. I recommend
   using this fork, which is well maintained:
   https://github.com/crdeutsch/multiselect

   This module actually uses some features from that fork that are not
   available in the original repository.

3. Install the plugin in your site's libraries directory. Your directory
   structure might look like:

     sites/all/libraries/jquery_ui_multiselect

4. Enable the jQuery UI Multiselect module.

5. Enable jQuery UI Multiselect widget on the desired fields. Go to
   the field's settings, expand the jQuery UI Multiselect section, and
   check "Use jQuery UI Multiselect". This option is only offered on
   supported fields, when the field has been configured to use the
   "Select list" widget.
  

-- SIMILAR PROJECTS --

You might be interested in the following Drupal modules, which provide
similar functionality. 

* http://drupal.org/project/multiselect

  Provides a field widget and a UI that has some of the advantages of
  jQuery UI Multiselect.
  
* http://drupal.org/project/jquery_multiselect

  Currently for Drupal 6 only. Just a wrapper for the jQuery UI
  Multiselect plugin. Does not do anything by itself.

* http://drupal.org/project/fancy_multiselect

  Currently for Drupal 6 only. Relies on the above module to provide a
  full-blown CCK widget.


-- CREDITS --

Current maintainer:
* David Lesieur (http://drupal.org/user/17157)

This project has been sponsored by:
* Whisky Echo Bravo (http://whiskyechobravo.com)
* Laboratoire NT2 (http://nt2.uqam.ca)

