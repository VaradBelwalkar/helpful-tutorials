## Understanding MySQL Authentication
MySQL authentication can be intricate, especially when running scripts or programmatically connecting to the MySQL instance. The complexity arises from MySQL's use of authentication plugins to verify the user interacting with the MySQL daemon.

### Authentication Plugin Challenges

When using MySQL with sudo privileges:

```
sudo mysql
```

Being a superuser grants direct access to the root account without requesting a password. However, attempting to log in manually without `sudo`:

```
mysql
```

Results in a permission denied error. Even providing the correct password for the root account:

```
mysql -u root -p
```

Leads to permission denied issues. This is because the default authentication mechanism for the root account is set to auth_socket (Unix socket). Consequently, accessing /var/run/mysql.sock is necessary for authentication, which normal user can't.

### Authentication Plugin Switch
To resolve this challenge, change the authentication plugin to `mysql_native_password`. This plugin authenticates based on the password, independent of machine privileges or local/remote execution.

Now, you can successfully execute:

```
mysql -u root -p
```
Simply provide the password, and access is granted. This solution also ensures remote or programmatic interactions work seamlessly.

### Checking and Updating Authentication Plugin

To check the current authentication plugin:

```sql
SELECT user, host, plugin FROM mysql.user WHERE user = 'root';
```

If the plugin is set to `auth_socket` or `unix_socket`, it implies root user authentication relies on system credentials. To enable password-based authentication, update the plugin:

```sql

ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'new_password';
```

After updating the authentication plugin, reload the grant tables and apply the changes:

```sql
FLUSH PRIVILEGES;
```
This approach ensures a smooth MySQL authentication experience, making it accessible via various methods while maintaining security measures.
