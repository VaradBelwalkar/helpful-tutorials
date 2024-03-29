```
DELIMITER //

CREATE PROCEDURE get_customer_count()
BEGIN
    DECLARE customer_count INT;
    
    SELECT COUNT(*) INTO customer_count FROM customers;
    
    SELECT customer_count;
END //  

DELIMITER ;
```

Here, first understand that INTO is going to store that `COUNT(*)` value in the customer_count variable as it is a single value


Here  to call the procedure type,

```
CALL get_customer_count();
```


To see the list of procedures on a database

```
SELECT ROUTINE_NAME, ROUTINE_TYPE
FROM information_schema.ROUTINES
WHERE ROUTINE_SCHEMA = 'your_database_name';
```

To drop the procedure 

```
DROP PROCEDURE IF EXISTS get_customer_count;
```






***SOME MORE PROCEDURE EXAMPLES***


```
DELIMITER //

CREATE PROCEDURE get_customers_by_country(IN country_name VARCHAR(50))
BEGIN
    SELECT * FROM customers WHERE country = country_name;
END //

DELIMITER ;
```


Here, the IN means that the variable is local scoped and can only be used in this procedure


```
DELIMITER //

CREATE PROCEDURE get_customer_count(OUT customer_count INT)
BEGIN
    SELECT COUNT(*) INTO customer_count FROM customers;
END //

DELIMITER ;
```

and calling the procedure:

```
SET @result = 0;

CALL get_customer_count(@result);

SELECT @result;
```


Here, the procedure is having variable with OUT attr, meaning that the variable is global scoped i.e referenced variable








