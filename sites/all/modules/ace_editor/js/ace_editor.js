(function($) {

  Drupal.behaviors.ace_editor_field_format = {
	attach: function(context, settings) {
		
		if (Drupal.settings.ace_editor.editor_instances.length) {
			
			$(Drupal.settings.ace_editor.editor_instances).each(function(i) {
				var $pre = $('#' + this['id']);
				var html = this['content'];
				var settings = this['settings'];
				
				var SyntaxMode = require("ace/mode/" + settings['syntax']).Mode;
				var themePath = "ace/theme/" + settings['theme'];
			
				var editor_instance = ace.edit(this['id']);
				editor_instance.getSession().setMode(new SyntaxMode());
				editor_instance.setTheme(themePath);
				editor_instance.renderer.setShowGutter(settings['line_numbers']);
				editor_instance.setShowPrintMargin(settings['print_margin']);
				editor_instance.setShowInvisibles(settings['invisibles']);
				editor_instance.renderer.setHScrollBarAlwaysVisible(false);
				editor_instance.setReadOnly(true);
				$pre.css({
					'font-size': settings['font_size'],
					'height': (settings['height'] == 'auto' || settings['height'] == '') ? '' : settings['height'],
					'width': settings['width']
				});
				
				/*
				if (settings['height'] == 'auto' || settings['height'] == '') {
					editor_instance.getSession().on('change', function(editor) {
						// after data update
				        var cell = $("div.ace_gutter-layer", $pre).find(".ace_gutter-cell:first");
				        var h = cell.height();
						alert(h);
				        var totalH = h * (editor_instance.getSession().getValue().split('\n').length + 1);
						$pre.height(totalH);
						$pre.find(":first-child").height($pre.height());
				        editor_instance.renderer.onResize(true);
					});
				}
				*/
				
				editor_instance.getSession().setValue(html);
				
								
				// TODO: Set the height of the editor if field_height is set to auto.	
				if (settings['height'] == 'auto') {
					/*
					console.log('Scrollbar: ' + editor_instance.renderer.scrollBar.getWidth());
					console.log('Lineheight: ' + editor_instance.renderer.lineHeight);
					console.log('Num lines: ' + editor_instance.getSession().getValue().split('\n').length);
					
					$pre.css('height', (editor_instance.renderer.lineHeight) * (editor_instance.getSession().getValue().split('\n').length + 2) + editor_instance.renderer.scrollBar.getWidth());
					*/
				}
				
			});
		}
		
		
	}
  };

})(jQuery);
