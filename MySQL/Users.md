
To show all users and from where they can get access to the mysql server

SELECT user, host FROM mysql.user;


Create a user 

```
CREATE USER 'username'@'host' IDENTIFIED BY 'password';
```

For example,

```
CREATE USER 'john'@'localhost' IDENTIFIED BY 'password123';
```




### UNDERSTAND THIS
The mysql previleges are only going to get applied on tables and not directly on the database
Hence it is important to write     db_name.*      if you want to have the privileges on all the
tables of this database, and you cannot simply write      db_name    as doing this 
would actually apply the privileges on the table named   db_name in your currently selected database

so if you have to a privilege on a table just write db_name.table_name

This is because you run SQL queries on tables and not on database itself





Grant previlages to the user just created 

```
GRANT ALL PRIVILEGES ON mydatabase.* TO 'john'@'localhost';
```

Here, the user john, gets access to the entire database mydatabase as the previleges it gets are ALL,


Grant select and insert privilege to the user

```
GRANT SELECT, INSERT ON mydatabase.* TO 'myuser'@'localhost';
```



See what privileges are assigned to a user

```
SHOW GRANTS FOR 'username'@'host';
```


Drop the user

```
DROP USER 'username'@'host';
```



Update the password of the user

```
ALTER USER 'username'@'host' IDENTIFIED BY 'new_password';
```



Revoke certain/all previlege from the user

```
REVOKE SELECT ON mydatabase.* FROM 'john'@'localhost';
```

Here this revokes the capability of the john user to be able to run SELECT query on the all the tables of the database


Here, if you want to revoke all the privileges 

```
REVOKE ALL ON mydatabase.* FROM 'john'@'localhost';
```







