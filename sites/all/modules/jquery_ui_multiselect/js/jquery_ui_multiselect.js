/**
 * @file Attaches the jQuery UI Multiselect widget.
 */
(function($) {
  Drupal.behaviors.jQueryUIMultiselect = {
    attach: function(context, settings) {
      $('select.jquery-ui-multiselect', context).each(function(index) {
        var multiselectSettings = $.parseJSON($(this).attr('data-jquery-ui-multiselect'));
        $(this).multiselect(multiselectSettings);
      });
    }
  }
})(jQuery);
