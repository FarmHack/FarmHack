
## Install FarmHak.org on your computer using Docker
```
# Get the code
git clone git@github.com:FarmHack/FarmHack.org.git 
# Uncompress the default database
cd FarmHack.org/default-database
tar xvf farmhack.dev.2015-03-13.sanitized.sql.tgz
cd ..
# Start the containers
docker-compose up
```

## Install FarmHack.org on your computer in 6 commands
Prereq is having `drush` installed. See [drush.org](http://www.drush.org).
```
git clone git@github.com:FarmHack/FarmHack.org.git 
cd FarmHack.org
mysql -uroot -ppassword -e 'create database farmhack;'
tar xzvf backups/farmhack.dev.2015-03-13.sanitized.sql.tgz
echo "<?php \$databases['default']['default'] = array(  'driver' => 'mysql',  'database' => 'farmhack',  'username' => 'root',  'password' => 'password',  'host' => '127.0.0.1',  'port' => '3306',  'prefix' => '',); \$base_url = 'http://local.farmhack.org';" >> sites/default/settings.local.php
drush sql-cli < farmhack.dev.2015-03-13.sanitized.sql
```
Now setup Apache with a VHOST with name of `local.farmhack.org` and point it to the `FarmHack` folder. You can log in as root using `drush uli`.  Note, these directions do not include downloading the files directory (pictures), it's a Gigabyte large so we have to find some place to host it.
