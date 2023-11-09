 MySQL supports transactions, which allow you to group multiple database operations into a single logical unit. 
Transactions ensure data consistency and integrity by enforcing the ACID (Atomicity, Consistency, Isolation, Durability) properties.
You can use transactions to handle complex operations and maintain data integrity in multi-user environments.

For until now, we have run only single sql statements or statements that interact with the database only single time, while we workout on
our data most of the time, now consider the scenario, where you are making a real transaction, where you are simply deducing some amount 
from a person, i.e updating the money field suppose to a less of one person, and increasing the the value of money for suppose another person,
while here, you cannot do this in a single sql statement so what you do is do is Write two SQL statements in which first does deduction and another
incremental, while you might think it is easy, it is not, the databases do not store the previous state when they go in new state
it means, suppose you run the previous first SQL command and after that the machine on which database was running fails or the database fails,
or something else happen with which you cannot run the second query,and well, while you might remember what needs to be done, after the database 
starts again, machine does not,
and
important thing here is, these queries are going to run on automated systems which are going to generate these queries temporarily and execute,
and as you know these queries are buffered and if that machine fails, the buffer goes and thus those queries!

So, what to do?

Well you might think that see those logs on the database and revert those, well transactions exactly do that, 
When, you run 

```
START TRANSACTION;
```

The individual transction starts, and after this, whatever commands i.e SQL queries you execute, they are safe, 
i.e what you just need to do is after running those commands that modify the database, run 

```
COMMIT;
```

command and that ensures that the transaction has happened successfully, 
well before running this, if the machine fails or database fails,


You simply need to write 

```
ROLLBACK;
```


after the database starts, and the database sees any incomplete transactions, i.e transactions without commit, 

then it rollbacks those updates to the database according to the logs stored

```
but if you run ROLLBACK after commit has been done, it doesn't do anything
So, a ROLLBACK is always run after the machine hosting database restarts from failure or database itself starts after failure
This ensures any incomplete transactions are rollbacked and thus maintaining the integrity of the database
```




```
START TRANSACTION;  -- Start the transaction

-- Step 1: Deduct the ordered quantity from the inventory
UPDATE inventory
SET quantity = quantity - <ordered_quantity>
WHERE product_id = <product_id>;

-- Step 2: Insert a new order record
INSERT INTO orders (order_id, customer_id, order_status)
VALUES (<order_id>, <customer_id>, <order_status>);

COMMIT;  -- Commit the transaction, making the changes permanent
```

Here you can see we are having two steps in between the transaction, and if commit is not run, you can run rollback to redo the changes made.







