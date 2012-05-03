# jQuery UI Multiselect #

I've merged some of the pull requests from the original author's repo to make this plugin useable for me.

If you submit patches I'll try be a little more on top of maintaining them.

## Options (default) ##

* sortable (true) : enable sorting the selected items.
* dragToAdd (true) : enable adding selected items by dragging.
* searchable (true) : enable searching for available items.
* doubleClickable (true) : enable adding selected item by double clicking.
* animated (fast) : animation option.
* show (slideDown) : show effect.
* hide (slideUp) : hide effect.
* dividerLocation (0.6) : the ratio of the size of the left column versus the right column.
* selectedContainerOnLeft : controls which side the selected container is on.
* width (null) : width of widget.
* height (null) : height of widget.
* nodeComparator : the function for comparing nodes.
* includeRemoveAll (true): include the Remove All feature.
* includeAddAll (true): include the Add All feature.
* pressEnterKeyToAddAll (false): enable pressing enter to add any items in the filtered list to the Selected List. Pressing enter acts the same as clicking "Add All" would.

## Example ##

<pre><code>
&lt;!--HTML--&gt;
&lt;select class=&quot;multiselect&quot; multiple=&quot;multiple&quot; id=&quot;colors&quot; name=&quot;colors&quot;&gt;
    &lt;option value=&quot;red&quot;&gt;Red&lt;/option&gt;
    &lt;option value=&quot;blue&quot;&gt;Blue&lt;/option&gt;
    &lt;option value=&quot;green&quot;&gt;Green&lt;/option&gt;
&lt;/select&gt;
</pre></code>

<pre><code>
//Javascript: setup multiselect.
$(&quot;#colors&quot;).multiselect({
    dividerLocation: .5
}).change(function (e) {
    //output values.
    console.log($('#colors').val());
});
</pre></code>

## History ##
### 4/4/2012 ###
Merged the following contributions from NateEag:

*Tweak word-wrap to handle very long single words

### 2/10/2012 ###
Merged the following contributions from ryoe:

* Support for pressing Enter key to "Add All"

### 12/11/2011 ###
Merged the following contributions from Garyzhu:

* Added options to exclude the Remove all and Add all controls.

### 11/20/2011 ###
Merged the following contributions from NateEag:

* Added 'refresh' method to change the selections in a multiselect programmatically

### 11/01/2011 ###
Merged the following contributions from NateEag:

* Set overflow to hidden for select items to fix issue where if you add a long option to a select that has little space, it'll overflow into the next one.

### 10/23/2011 ###
Merged the following contributions from NateEag:

* Rename selectedColumnOnRight to selectedColumnOnLeft
* Unfixed math fix

### 10/18/2011 ###
Merged the following contributions from NateEag:

* Removed trailing whitespace. 
* Prevent multi-clicks from duplicating items.
* Add option to set which side the selected items are shown on.
* Add public method for dynamically adding options.
* Fix a one-pixel error in size calculations.

### 9/22/2011 ###
* Added "DragToAdd" option that can turn off support for dragging to add. Since you currently can't drag to remove.
* Added Example and Options documentation to this ReadMe

### 8/30/2011 ###
* Updated so change event is fired on Remove All and Add All

### 8/9/2011 ###

* Merged code from NateEag to fix duplicate items - issues 90 & 91
* Merged code from chickenchan to fix issue with loosing sort order - issue 22
* Updated so width doesn't expand past what the target elements width is. Borders were causing this to happen.
* Add code to trigger the original select boxes change event whenever the list changes.
* Added support for specifying width and height. If not specified it will default to using the target element's dimensions which can be inconsistent if the target is a select element and it's not visisble.

## Original Author's comments ##

This repository is no longer actively maintained by the author. However, pull requests are always welcome. If there's someone interested in officially maintaining the plugin, please let me know.

In case you are looking for an AJAX version, please also consider "Yanick Rochon's":http://github.com/michael/multiselect/tree/next version.