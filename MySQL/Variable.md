In MySQL, variables are used to store temporary values that can be used within a session or a stored program. 
Variables in MySQL are preceded by the @ symbol.

Create a new or update the original variable

```
SET @my_variable = 42;
```

*****To show the value

```
SELECT @variable_name
```



### IMPORTANT
Whenever you do SELECT @variable_name on non-existant variable, you get null value 




To delete the variable 

simply NULLify it 

i.e
```
SET @variable_name = NULL;
```




How to use it
To use a variable in a SQL statement or expression, simply reference it using the @ symbol. Here's an example of using a variable in a query:

```
SELECT column1, column2 FROM table_name WHERE column1 = @my_variable;
```
















