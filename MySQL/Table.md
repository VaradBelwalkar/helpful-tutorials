Create a table:

```
CREATE TABLE customers (
  id INT PRIMARY KEY,
  name VARCHAR(50),
  email VARCHAR(100)
);
```


Alter the table - Add the column

```
ALTER TABLE customers
ADD COLUMN age INT;
```


Alter table -  modify column

```
ALTER TABLE customers
MODIFY COLUMN email VARCHAR(150);
```

Alter table - Rename Column

```
ALTER TABLE customers
CHANGE COLUMN old_name  new_name  data_type;
```


Alter table - drop column

```
ALTER TABLE customers
DROP COLUMN age;
```


Rename table - rename table

```
RENAME TABLE customers TO clients;
```

Drop table 

```
DROP TABLE customers;
```

Truncate the table:

```
TRUNCATE TABLE customers;
```

Update foreign key constraint
```
ALTER TABLE table1
ADD CONSTRAINT fk_constraint_name
FOREIGN KEY (column_in_table1)
REFERENCES table2(column_in_table2);
```


Set not null for a single column

```
ALTER TABLE registration MODIFY COLUMN password TEXT NOT NULL;
```






















