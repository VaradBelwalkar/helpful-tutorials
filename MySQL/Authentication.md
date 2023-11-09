MySQL authentication is a bit tricky, you might have noticed this when running scripts or programmatically connecting to the MySQL instance,

The reason behind flacky experience in MySQL authentication are its AUTHENTICATION PLUGINS, yes
MySQL uses different authentication plugins to authenticate the user going to interact with the MySQL daemon

Here, the MySQL is running on your computer, and there, if you try to authenticate yourself from the cli like this,

```
sudo mysql
```

Here, as you are using sudo, and most likely it will grant you root previleges, the thing is that, if you are superuser, then MySQL doesn't 
ask for password nor for user account you want to login into,
It logs you in the root account directly, because well you are **SUPERUSER!**

But when you try to do this manually like,

```
mysql
```

Obviously, it will return error with permisson denied!

But, what if you provide user account and password for that, like this

```
mysql -u root -p
```

Here, even if you provide correct password that is associated with the root account, you will get error as permisson denied, why?

Well, you password is right, but the authentication mechanism for root account is defaultaly set to auth_socket, i.e Unix socket!

This means, to log into root account, you should be able to access ```/var/run/mysql.sock``` which is the socket on which MySQL listens on

Here, the frontend or the MySQL Client first tries to setup Socket connection to the MySQL daemon, if it doesn't have permisson, then it fallbacks
to using network socket, i.e using mysql protocol on the port on which it listens

But here is the catch! 
When you run 

```
mysql -u root -p 
```

as you are seeing, it is running as normal user, which means it has no access to the unix socket on which MySQL is listening on,
So it fallbacks to using network socket, which here, will not work why,

Because the root account in the MySQL is configured to have authentication plugin as auth_socket, so if you try to access it without machine's
root privileges even if by providing correct password, it is not going to let you in.
This also prevents any remote logins into the account as ofcourse, it needs local machine's privileges and ofcourse that unix socket!

So what is the solution, well, just change the authentication plugin!

Yes, you just need to change that plugin to mysql_native_password !

Yes, this will authenticate you purely based on password and not on the basis of privileges you have on the machine or whether you are local or remote
executor.
So with this, you will be able to do this:

```
mysql -u root -p
```

and by providing password, you are in!

and even the remote or programmatic ways are then able to work with it without a problem!

But then how to change the plugin or see which plugin is being used ?



To check which authentication plugin is there:

```
SELECT user, host, plugin FROM mysql.user WHERE user = 'root';
```


 If the authentication plugin is set to auth_socket or unix_socket, it means the root user is authenticated based on the system credentials. 
You can update the plugin to ```mysql_native_password``` to enable password-based authentication for the root user. 
Execute the following query to update the plugin:

```
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'new_password';
```



After updating the authentication plugin, run the following command to reload the grant tables and apply the changes:\

```
FLUSH PRIVILEGES;
```







