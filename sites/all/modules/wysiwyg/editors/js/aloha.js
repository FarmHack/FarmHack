(function($) {
/**
 * Rather dirty hack to get the plugins to be loaded in the correct
 * attribute in a script tag.
 * Aloha doesn't seem to care what script tag, but placing it on any
 * random tag causes undefined errors.
 * Also, for some reason, using the data method doesn't work.
 */
$(function() {
  $('script').eq(0).attr('data-aloha-plugins', Aloha.settings.plugins.load);
});

/**
 * Attach this editor to a target element.
 */
Drupal.wysiwyg.editor.attach.aloha = function(context, params, settings) {
  // Setup configuration.
  settings.jQuery = $;
  Aloha.settings = $.extend(Aloha.settings, settings);
  // @todo: This is where we would want to reset the editor so it loads with the new settings.

  // Attach editor.
  Aloha.ready(function() {
    Aloha.jQuery('#' + params.field).aloha();
  });
};

/**
 * Detach a single or all editors.
 *
 * See Drupal.wysiwyg.editor.detach.none() for a full desciption of this hook.
 */
Drupal.wysiwyg.editor.detach.aloha = function(context, params) {
  if (typeof params != 'undefined') {
    Aloha.jQuery('#' + params.field).mahalo();
  }
  else {
    for (var e in GENTICS.Aloha.editables) {
      window.Aloha.editables[e].destroy();
    }
  }
};

})(jQuery);
