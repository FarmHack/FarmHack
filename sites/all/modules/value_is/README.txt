Value is (form element validators)
====

Adds element validators to Drupal that Drupal itself should have had.
Instead of writing the (almost) same `_validate` function over and over,
you can use the element's `#element_validate` property when building a
custom form. Drupal doesn't provide decent functions to assign to
that. (You'd still have to write the validation shell yourself.) This
module does.

Implemented
----

* Integer (with optional `#min` and/or `#max`)
* Number (with optional `#min` and/or `#max`)
* E-mail (with optional `#max` for multiple addresses separated by comma's)
* User name (with optional `#exists` if it has to exist in the `{users}` table)

To do
----

See issue queue: http://drupal.org/project/issues/value_is?status=Open&categories=feature
