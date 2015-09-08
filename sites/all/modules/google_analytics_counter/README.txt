Google Analytics Counter is a scalable, lightweight page view counter drawing on data collected by Google Analytics.

Drupal project page is at http://drupal.org/project/issues/google_analytics_counter
Installation, demo and tips are at http://vacilando.org/en/article/google-analytics-counter
If you encounter a problem or need support, see http://drupal.org/project/issues/google_analytics_counter

Author: Tomas Fulopp (Vacilando)
The author can also be contacted at http://vacilando.org/contact for paid customizations of this and other Drupal modules.
Development of this module is sponsored by Vacilando ( http://vacilando.org/ )

CONFIGURATION TO USE OAUTH 2.0
------------------------------
Google Account Api Access Configuration:
1. Visit https://code.google.com/apis/console
2. Create a new project.
3. Enable "Analytics API" (Some other APIs are automatically enabled, you can
   disable them if you want).
4. Under "APIs & auth >> Credentials" create an Oauth 2.0 Client ID with
   application type "Web application", configure consent screen as you wish.
5. Configure Client ID settings:
    -Redirect URIs: http://example.com/admin/config/system/google_analytics_counter/authentication
    -JavaScript origins: http://example.com
6. Copy the client id and client secret to the configuration form of the module
   in admin/config/system/google_analytics_counter/authentication.
