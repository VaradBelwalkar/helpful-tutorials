Primary Key Constraint

```
CREATE TABLE employees (
  employee_id INT PRIMARY KEY,                (The primary key is defaulty NOT NULL & UNIQUE)
  first_name VARCHAR(50),
  last_name VARCHAR(50)
);
```


Foreign Key Constraint

```
CREATE TABLE orders (
  order_id INT PRIMARY KEY,
  customer_id INT,
  order_date DATE,
  FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);
```


Unique Constraint

```
CREATE TABLE employees (
  employee_id INT PRIMARY KEY,                                  
  email VARCHAR(50) UNIQUE,
  ...
);
```



Not Null Constraint

```
CREATE TABLE customers (
  customer_id INT PRIMARY KEY,
  first_name VARCHAR(50) NOT NULL,
  last_name VARCHAR(50) NOT NULL,
  ...
);
```


Check Constraint

```
CREATE TABLE products (
  product_id INT PRIMARY KEY,
  product_name VARCHAR(50),
  price DECIMAL(10, 2),
  quantity INT,
  CHECK (price > 0 AND quantity >= 0)
);
```

This CHECK constraint will always evaluate whenever an entry is made, if it comes to false, error will occur, else normal workflow



***TO ADD CONSTRAINTS TO ALREADY EXISTING TABLE***


Add a Primary Key Constraint

```
ALTER TABLE employees
ADD CONSTRAINT pk_employee_id PRIMARY KEY (employee_id);
```




Foreign key 

```
ALTER TABLE orders
ADD CONSTRAINT fk_customer_id FOREIGN KEY (customer_id) REFERENCES customers(customer_id);
```



UNIQUE constraint

```
ALTER TABLE employees
ADD CONSTRAINT uk_email UNIQUE (email);
```


NOT NULL WITH DATA TYPE MODIFY
```
ALTER TABLE customers
MODIFY COLUMN first_name VARCHAR(50) NOT NULL;             (We can do as above as well using add constraint or vice versa)
```



Add check constraint
```
ALTER TABLE products
ADD CONSTRAINT chk_price CHECK (price > 0);
```













