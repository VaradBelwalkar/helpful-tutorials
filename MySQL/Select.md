Select all fields from table customers

```
SELECT * FROM customers;
```

Select Specific Columns from a Table

```
SELECT name, email FROM customers;
```

Alias Columns

```
SELECT name AS customer_name, email AS customer_email FROM customers;
```

Select Distinct Values
```
SELECT DISTINCT country FROM customers; ( here there will not be any duplicate entry for what you chosen, remember for what you chosen 
                                          i.e for only the fields you considered, of course this would not do anything when you choose
                                          all the fields as that would be an entire tuple which will always be unique)
```



Limit the Number of Rows Returned

```
SELECT name, email FROM customers LIMIT 10;    (This is mostly used with the ORDER BY in order to get First X tuples according to sorting)
```



Sort the Result Set

```
SELECT name, email FROM customers ORDER BY name ASC;    (DESC for descending)
```


Filter Rows with WHERE Clause

```
SELECT name, email FROM customers WHERE country = 'USA';    (Here understand that the priority of WHERE clause is MAX and thus,  
                                                             the mysql selects only those tuples which satisfy the criteria
                                                             rather than applying filter afterwards)
(Here the mysql goes tuple by tuple and sees first if the tuple is matching the criteria if given then actually considers the fields to be selected)
```

Use Logical Operators in WHERE Clause

```
SELECT name, email FROM customers WHERE age >= 18 AND city = 'New York';     (Here you can use OR as well and also IN operator)
```





Aggregate Functions (e.g., COUNT, SUM, AVG)

```
SELECT COUNT(*) FROM customers;

(here COUNT is an aggregate function in SQL, where * defines which columns to choose, abviously, you can give any field name here
 as it won't affect the result 
 It is similar to having something like this:
  SELECT * FROM customers  >>>>>>>  COUNT 
Remember COUNT only counts the tuples i.e number of results
) 
```

```
SELECT name, COUNT(*) FROM customers;
(
Here, mysql starts iterating through the table, when a tuple matches the WHERE criteria if present, then the required field i.e name
is appended in the result table which is stored in the buffer, here, as mysql encounters there is not GROUP BY involved in the query
it simply increments the COUNTER associated with the result table each time a pseudo entry is made or you may say a tuple matches the
criteria, the COUNTER is incremented
when entire tuples exaust and if atleast one field is selected then the result table is complete and then mysql has to come up 
with a single result table to show us, well, this result table may contain lots of tuples, but our COUNTER has single value,
so what mysql does is simply selects the FIRST tuple from the RESULT TABLE and combines that with the COUNTER and
gives us the result as result table with fields name and COUNT(*) or names otherwise

)
```



```
SELECT AVG(age) FROM customers WHERE country = 'USA';

(Here the AVG is again an aggregate function which finds average of given field, here becomes important aspect
It is similar to 

SELECT age FROM customers WHERE country = 'USA'    >>>>>>>>>  AVG

Here the AVG function is getting tuples containing only one field i.e age, so it is easy for it to calculate average and return it
)
```

```
SELECT SUM(quantity) FROM sales;

(Here the SUM is an aggregate just like the AVG but instead of calculating the average it simply sums up the result
It is like,
SELECT quantity FROM sales   >>>>>>>  SUM

Here it gets the tuples just containing quantity as the field and then the SUM just sums it up
)
```





Grouping and Aggregation (e.g., GROUP BY, HAVING)

```
SELECT country, COUNT(*) as customer_count
FROM customers
GROUP BY country
HAVING customer_count > 5;

( 
Here firstly, the mysql starts iterates from the table and when it finds a tuple matching the WHERE criteria if present,
if mysql encounters GROUP BY clause in the query, what it does is simply appends the the required field/s from the tuple matching the 
criteria to the result table only if the field specified by GROUP BY clause doesn't already exist in the result table
Here, mysql maintains a SEPARATE COUNTER for every tuple in this result table
suppose at the start itself when result table is empty, when the mysql finds a matching tuple with country germany, and the result 
table is empty, then it simply appends the required field that is germany in the result table and associates that entry with a COUNTER and 
incrementes it initially(of course!)
then suppose it finds a tuple with country USA, then it sees that there is no entry in the result table with the entry USA as per the 
GROUP BY clause, then it makes an entry and then does same as above
then when it encounters again a tuple with country germany, it sees ther is already an entry in the result table according to the GROUP BY
clause,then it simply increments the counter
after all done, the mysql has all the distinct country names with their respective counters, then it simply returns them by simply joining

Here one needs to understand that GROUP BY clause doesn't need the field which is being taken into the result in this case, the country,
it can have other criteria as well, such as company, then
what does mysql does it makes a virtual entry in the table by which it groups the result with the company name as it is not being considered in 
the result table, so according to that, when a tuple matches it first sees wether the field told by GROUP BY clause in that tuple is already 
there or not in the result's virtual field which is company, if it is, simply increment the counter else make an entry.

After this is done, the HAVING clause is evaluated, 
which filters out the joined result table, here you can see tha HAVING clause can use aggregate functions as their filtering criterias
whereas WHERE clause CANNOT

Here you need to use HAVING CLAUSE when you have to filter the result table on the basis of some aggregate functions 


)
 
```






Subqueries

```
SELECT name, email
FROM customers
WHERE country IN (SELECT country FROM suppliers WHERE category = 'Electronics');
```



SUM up the fields

```
SELECT column1 + column2 AS total_sum FROM table_name;
```


SELECT distinct values 

```
SELECT DISTINCT column_name FROM table_name;
```



LIKE operator

```
SELECT column1 FROM table_name WHERE column2 LIKE '%pattern%';
```


MIN MAX aggregators
```
SELECT MIN(column1), MAX(column2) FROM table_name;

(here the workflow is same, what mysql does is makes two field result table here, and then starts iterating through tuples
when tuple matches the criteria, if the result table is empty, the respective fields are written as it is in the fields 
i.e MIN(column1) and MAX(column2)
but when a tuple satisfies criteria, and mysql sees already entered value/s in the result table, it then takes the value/s from the 
tuple and then compares it with one present in the result table, according to MIN and MAX, it then decides whether to update it or not
)
```


JOIN

```
SELECT table1.column, table2.column FROM table1 JOIN table2 ON table1.id = table2.id;
```



