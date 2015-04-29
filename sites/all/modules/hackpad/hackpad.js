(function($){

/**
 * Behavior for loading Hackpads in a page.
 */
Drupal.behaviors.hackpadPad = {
  attach: function(context) {
    var settings = Drupal.settings.hackpad;

    // Find each unprocessed target div and attach the pad to it.
    $.each(settings.pads, function(padId, pad) {
      $('#' + pad.target).not('.hackpad-pad-processed').addClass('hackpad-pad-processed').each(function() {
        Drupal.hackPadAttach(pad.target, pad.url);
      });
    });

    $(window).bind('message', Drupal.hackPadResize);
  }
};

/**
 * Attach a hackpad to a target element.
 *
 * @param padId
 *   The Hackpad pad ID to load.
 * @param padSettings
 *   The ID of the DOM element to load the pad into.
 */
Drupal.hackPadAttach = function(target, url) {
  hackpad.render_url($('#' + target), url);
};

/**
 * Set the height for a hackpad div based on the height postMessage'd to us by
 * the editing widget.
 *
 * @param e
 *   The event object passed to by the message handler.
 */
Drupal.hackPadResize = function(e) {
  // jQuery doesn't process the event data properly, so grab it from
  // e.originalEvent.
  var oe = e.originalEvent;
  if (oe.origin != 'https://' + Drupal.settings.hackpad.hackpad_subdomain + '.hackpad.com') {
    return;
  }

  // The data passed to us consists of hackpad-ID:<dimension>:<pixels>.
  var parts = oe.data.split(':');
  if (parts[1] == 'height') {
    // There is a bug currently where the height doesn't include the toolbar or
    // status bar. Add 100px to cover for those.
    var h = parseInt(parts[2]) + 100;
    $('#' + parts[0]).height(h);
  }
}

})(jQuery);
