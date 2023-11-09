
Delete all the entries in the table (equivalant to truncate the table)

```
DELETE FROM customers;
```


Delete according to condition

```
DELETE FROM customers
WHERE age > 30;
```


Delete a single row based on a condition

```
DELETE FROM table_name
WHERE primary_key_column = value;
```


Deleting from multiple tables
```
DELETE c, o
FROM customers c
JOIN orders o ON c.customer_id = o.customer_id
WHERE c.country = 'USA';
```

(Here, understand that, we may have a situation where we need to compare two tables but delete from one of the table or may have situation where
from both the tables, hence we have to select the tables aliases here as c and o, if we want to delete from both the tables right,
if i just wanted to delee from customers table only, i would have given alias to only that table and would have mentioned that 
like DELETE c FROM ...
Here, when we do join operation, as mysql knows we have applied the DELETE before that, what it does, instead of actually joining the tables
which would be pretty inefficient for this scenario and non useful, it simply considers the evaluation condition for joining,
and when two tuples from both the tables join the condition, i.e customer_id condition here,
it would simply check the WHERE clause criteria, and if it does match for the tuples or any of the tuples, the delete operation is going to get 
peformed on the table or tables for that or those tuples

certainly we can use the INNER JOIN AND OUTER JOIN i think here, but I think the workflow would be more complex.
)


