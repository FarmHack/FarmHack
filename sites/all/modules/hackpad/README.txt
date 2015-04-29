Hackpad Integration for Drupal
==============================

 * This module requires the OAuth Common module, which is part of the Oauth
   project. If you're using Drush to install Hackpad, it won't automatically
   detect the missing dependency if OAuth isn't already downloaded. Work around
   this by running:

     drush dl oauth && drush en hackpad

 * Obtain your Hackpad API keys by logging in to your hackpad instance with an
   administrator account. The API keys are available in your account settings
   at https://<my-subdomain>.hackpad.com/ep/account/settings/.

Once installed, add your keys to the Hackpad settings page, and then add a
Hackpad field to a content type. For displaying pads, both a static HTML
display modes and an editor widget are available.

