(function($) {

  Drupal.behaviors.ace_editor_admin = {
	attach: function(context, settings) {
		
		// Contains the settings for the editors.
		var editorSettings;
		var formIdentifier;
		
		/**
		* If the user selected a text format configured to be used with the editor,
		* show it, else show the default textarea.
		*/
		function acifyWrapper($textFormatWrapper) {
			//console.log("Acify");
			// The select list for chosing the text format that will be used.
			var $filterSelector = $textFormatWrapper.find('select.filter-list');
			
			// Checks if the currently selected filter is one that uses the editor.
			if ($.inArray($filterSelector.val(), Drupal.settings.ace_editor.admin.text_formats) != -1) {
				
				editorsJustAdded = false;
				
				/**
				 * If the settings has not been set I will copy them into a new object.
				 * if I don't the settings will be duplicated every time I add a textarea
				 * on fields that supports multiple values.
				 */
				if (!editorSettings) {
					editorSettings = $.extend({}, Drupal.settings.ace_editor.admin);
					formIdentifier = $textFormatWrapper.parents('form:first').find('input[name="ace_editor_identifier"]').val();
				}

				// Check to see if the editor has been added yet.
				if ($textFormatWrapper.find('div.ace-editor-container').length != 
					$textFormatWrapper.find('div.form-item.form-type-textarea').length) {
					
					// Init the array that will hold all editor elements and instances inside
					// of each text format wrapper.
					var editors = new Array();
					
					// Iterate through all textarea containers that and attach the editor.
					$('div.form-item.form-type-textarea:visible', $textFormatWrapper).each(function(i) {
						var $form_item = $(this);
						var editor_instance; 
						
						if (!$form_item.find('pre').length) {
							// Create the editors container.
							var $ace_editor_container = $('<div class="ace-editor-container"></div>');
							// Put the different parts together.
							var $pre = $('<pre id="' + $(this).find('textarea').attr('id') + '-aced"></pre>');
							$ace_editor_container.append($pre);
							
							// Get the stored height for the fields if it exists.
							var sizeId = formIdentifier + '_' + $form_item.find('textArea').attr('id').replace(new RegExp('-', 'g'), '_')
							var storedHeight = localStorageGet('ace_editor_' + sizeId + '_height');
							var height = storedHeight ? storedHeight : null;
							
							// Only append controlls to the main form item.
							var $controls;
							if ($(this).attr('class').indexOf("-value") != -1) {
								
								$pre.css({'height': height ? height : '500px'});
								$controls = get_editor_controls();
								$ace_editor_container.append($controls);
								$(this).append($ace_editor_container);
							} else { // It's a summary form item.
								
								$pre.css({'height': height ? height : '200px', 'border-bottom': '1px solid #CCC'});
								$(this).find('div.form-textarea-wrapper').after($ace_editor_container);
							}
						
							// Initialize the editor and set the correct options.
							editor_instance = ace.edit($pre.attr('id'));
							editor_instance.setTheme("ace/theme/" + editorSettings.theme);
							var HTMLMode = require("ace/mode/html").Mode;
							editor_instance.getSession().setMode(new HTMLMode());
							editor_instance.setShowPrintMargin(editorSettings['printmargin']);
							editor_instance.renderer.setHScrollBarAlwaysVisible(false);
							$pre.css('font-size', editorSettings['fontsize']);
							$pre.data('editor_instance', editor_instance);
							
							// Adds handles to the editors for vertical resizing.
							$pre.resizable({
								handles: 's',
								resize: function(event, ui) {
									$pre.width('100%');
									editor_instance.resize();
								},
								stop: function(event, ui) {
									var sizeId = formIdentifier + '_' + $form_item.find('textArea').attr('id').replace(new RegExp('-', 'g'), '_')
									localStorageSet('ace_editor_' + sizeId + '_height', $pre.height());
								}
							});
							
							// Add event listeners.
							editor_instance.getSession().on('change', function(editor) {
								editorContentChange($form_item, editorObject);
							});
							
							editorsJustAdded = true;
						} else {
							$pre = $form_item.find('pre');
							editor_instance = $pre.data('editor_instance');
						}
						
						var editorObject = {
							editor: editor_instance,
							element: $pre
						};
						editors.push(editorObject);
					});
					
					// Store the newly created editor instances for later use
					$textFormatWrapper.data('ace-editors', editors);
					
					// Set control states.
					$textFormatWrapper.find('div.ace-editor-controls').each(function(i) {
						var $controls = $(this);
						
						var $textArea = $textFormatWrapper.find('textarea');
						var textAreaID = formIdentifier + '_' + $textArea.attr('id').replace(new RegExp('-', 'g'), '_');
						
						var showHidden = localStorageGet('ace_editor_' + textAreaID + '_show_hidden');
						var lineNumbers = localStorageGet('ace_editor_' + textAreaID + '_show_line_numbers');
						var mode = localStorageGet('ace_editor_' + textAreaID + '_mode');
						
						$controls.find('input.show_hidden').attr('checked', (showHidden == 1) ? true : false);
						$controls.find('input.show_line_numbers').attr('checked', (lineNumbers == 1) ? true : false);
						$controls.find('select.mode').val(mode ? mode : 'html');
						
						// Trigger controls.
						$controls.find('div.control input, div.control select').trigger('change');
					});
				}
				
				// Get all of the editor objects for the text format wrapper.
				var editorObjects;
				if (editorsJustAdded) {
					editorObjects = editors;
				} else {
					editorObjects = $textFormatWrapper.data('ace-editors');
				}
				
				// Show the editor containers and hide the textarea containers.
				$(editorObjects).each(function(i) {
					var $formItem = $(this["element"]).parents('div.form-item:first');
					var $textAreaWrapper = $formItem.find('div.form-textarea-wrapper');
					
					if ($textAreaWrapper.is(":visible")) {
						var $editorContainer = $formItem.find('div.ace-editor-container');
				
						// Add the content of the field to the editors current session.
						this["editor"].getSession().setValue($textAreaWrapper.find('textarea').val());
				
						$textAreaWrapper.hide();
						$editorContainer.show();
					}
				});
					
			} else { // Show the textarea.
				
				var editorObjects = $textFormatWrapper.data('ace-editors');
				if (editorObjects) {
					
					// Only switch of editors are shown.
					var $firstElement = $(editorObjects[0]["element"]);
					if ($firstElement.is(':visible') || !$firstElement.parent().parent().is(':visible')) {
						$(editorObjects).each(function(i) {
							var editorObj = editorObjects[i];
						
							var $formItem = $(editorObj["element"]).parents('div.form-item:first');
							var $textAreaWrapper = $formItem.find('div.form-textarea-wrapper');
							var $editorContainer = $formItem.find('div.ace-editor-container');
						
							// Transfer content from editor to textarea.
							$textAreaWrapper.find('textarea').val(editorObj['editor'].getSession().getValue())
						
							// Hide the editor containers and show the textarea containers.
							$textAreaWrapper.show();
							$editorContainer.hide();
						});
					}
				}
				
			}
		}
		
		/**
		* Bind the change event to all text format select lists.
		*/
		$('div.text-format-wrapper fieldset.filter-wrapper select.filter-list').live('change', function(e) {
			var $textFormatWrapper = $(this).parents('div.text-format-wrapper:first');
			acifyWrapper($textFormatWrapper);
		});
			
		/**
		 * Update the editors to reflect the toggled option.
		 */
		$('div.text-format-wrapper div.control input, div.text-format-wrapper div.control select').live('change', function(e) {
			
			var $control = $(this);
			var $textFormatWrapper = $(this).parents('div.text-format-wrapper:first');
			var editorObjects = $textFormatWrapper.data('ace-editors');
			var $textArea = $textFormatWrapper.find('textarea');
			var textAreaID = formIdentifier + '_' + $textArea.attr('id').replace(new RegExp('-', 'g'), '_');
					
			var checked;
			if ($control.attr('type') == 'checkbox') {
				checked = $(this).is(':checked') ? 1 : 0;
			}
			
			
			if ($control.attr('name') == 'mode') {
				if ($control.val() == 'html') {
					// Apply settings to all editors.
					$(editorObjects).each(function(i) {
						var HTMLMode = require("ace/mode/html").Mode;
						this['editor'].getSession().setMode(new HTMLMode());
					});
				} else {
					$.getScript(editorSettings['ace_src_dir'] + 'mode-' + $control.val() + '.js', function(data, textStatus) {
						$(editorObjects).each(function(i) {
							var Mode = require("ace/mode/" + $control.val()).Mode;
							this['editor'].getSession().setMode(new Mode());
						});
					});
				}
			} else {
				// Apply settings to all editors.
				$(editorObjects).each(function(i) {
					switch ($control.attr('name')) {
						case "show_hidden":
							this['editor'].setShowInvisibles(checked);
							break;
						case "show_line_numbers":
							this['editor'].renderer.setShowGutter(checked);
							break;
					}
				});
			}
			
			// Save settings 'till next time.
			switch ($control.attr('name')) {
				case "show_hidden":
					localStorageSet('ace_editor_' + textAreaID + '_show_hidden', checked);
					break;
				case "show_line_numbers":
					localStorageSet('ace_editor_' + textAreaID + '_show_line_numbers', checked);
					break;
				case "mode":
					localStorageSet('ace_editor_' + textAreaID + '_mode', $control.val());
					break;
			}
		});
		
		/**
		 * Add the editor to the summary field.
		 * Seems that drupal blocks the use of click here, so we need to use
		 * mouseup with a small delay to get it to work.
		 */
		$('a.link-edit-summary').live('mouseup', function(e) {
			var $link = $(this);
			window.setTimeout(function() {
				acifyWrapper($link.parents('div.text-format-wrapper:first'));
			}, 10);
		});
		
		/**
		 * The content of the editor has changed, update the span showing line numbers.
		 * Also transfer the content of the editors to their related textareas.
		 *
		 * TODO: Think about a better way to transfer the data between the editor and the textarea,
		 * I have tried doing this in a the 'blur'-event of the editor, but content wont get saved
		 * every time...
		 */
		function editorContentChange($form_item, editorObject) {
			$(editorObject['element']).parents('div.ace-editor-container:first').find('div.ace-editor-controls span.num-lines').text(editorObject['editor'].getSession().getValue().split("\n").length + " lines");
			
			var $textarea = $form_item.find('textarea');
			var val = editorObject['editor'].getSession().getValue();
			$textarea.html(val);
		}
	
		
		/**
		*	Returns the controls for an editor.
		*/
		function get_editor_controls() {
			$controls = $('<div class="ace-editor-controls"></div>');
			$controls.append('<div class="control"><input type="checkbox" name="show_hidden" class="show_hidden" checked>' + 
							  '<label>Invisibles</label></div>');
			$controls.append('<div class="control"><input type="checkbox" name="show_line_numbers" class="show_line_numbers" checked>' + 
							  '<label>Line numbers</label></div>');
			$modes_select = $('<div class="control"><select name="mode" class="mode"></select></div>');
			$.each(editorSettings['available_modes'], function(key, value) {
				var selected = (key == 'html') ? ' selected' : '';
				$('select', $modes_select).append('<option value="' + key + '"' + selected + '>' + value + '</option>');
			});
			$controls.append($modes_select);
							
			$controls.append('<div class="info"><span class="num-lines">1 lines</span><a class="key-bindings" target="_blank" href="https://github.com/ajaxorg/ace/wiki/Default-Keyboard-Shortcuts">Show key bindings</a></div>');
			
			return $controls;
		}
		
		/**
		 * Saves data to localStorage if available.
		 */
		function localStorageSet($key, $value) {
			if (localStorageAvailable()) {
				localStorage[$key] = $value;
			}
		}
		
		/**
		 * Gets data from localStorage if available.
		 */
		function localStorageGet($key) {
			if (localStorageAvailable()) {
				return localStorage[$key];
			}
			
			return null
		}
		
		/**
		 *
		 */
		function localStorageAvailable() {
			return 'localStorage' in window && window['localStorage'] !== null;
		}
	}
};

})(jQuery);
