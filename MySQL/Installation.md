Official MySQL server installation on linux is not straightforward

What you need to do is visit the [https://dev.mysql.com/doc/mysql-apt-repo-quick-guide/en/#apt-repo-setup]
and those steps are also mentioned there.

Adding the MySQL APT Repository:
Here you need to download a deb package which is going to configure the apt repositories for installing and maintaing MySQL server on your pc
it also installs the GPG keys on the right path so that APT can use it to verify the packages installed from the URL configured in the 
/etc/apt/sources.list.d/mysql.list,
don't worry this all is taken care by that single .deb file

When you go to that oracle website if you have account then fine otherwise need to creat one 
after that you can download that tiny 17k .deb file and then do the following:

```
sudo dpkg -i <path to file>
```

once that is done, it will prompt you for selecting packages go with default if you don't want anything else,
then once done, it will automatically configure the things i told above i.e mysql.list file and the GPG key 

Once done, 

Run 
```
sudo apt-get update
```
So that APT can download the Packages file from that URL so that it can know which packages are offered on that URL,


After this, you can run,

```
sudo apt-get install mysql-server
```

To officially install mysql server on you pc, along with the shell as well i.e client





---

Another method (for Kali linux):

This is required, weird but true in case of kali linux:
```
sudo mkdir -p /etc/mysql
sudo touch /etc/mysql/mariadb.cnf
```

This will setup both client and the server part:

```
apt install mariadb-server
```

After this, whatever you try, mysqld or mariadbd won't start, either start by yourself with binaries or through services, they won't start.

The reason behind this is mysql/mariadb is just installed, and not configured, configuring it manually is a headache, you have create various directories and make sure that the mysql is able to access them, lots of errors will come, and after that you need to create some default tables 
in mysql to be able to actually start the the server successfully and be able to work with it.

the recommended way is to use the `mysql_secure_installation` binary which comes along with the above package.


It removes the above headache and configures the mysql for our use.














