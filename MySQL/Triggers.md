Triggers in MySQL are database objects that are executed automatically in response to specific events, 
such as INSERT, UPDATE, or DELETE operations on a table. Triggers allow you to define custom logic that runs before or after these events occur, 
enabling you to enforce business rules, maintain data integrity, or automate certain tasks within the database.
Here's an explanation of triggers in MySQL with examples:

```
CREATE TRIGGER enforce_order_amount_limit
BEFORE INSERT ON orders
FOR EACH ROW
BEGIN
  IF NEW.total_amount > 1000 THEN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Order amount exceeds the limit.';  
  END IF;
END
```

the CREATE TRIGGER statement is used to define a new trigger.
You provide a trigger_name for the trigger and specify the event (INSERT, UPDATE, or DELETE) and the table (table_name) on which the
trigger should be associated. You can also specify whether the trigger should execute BEFORE or AFTER the event occurs. 
The FOR EACH ROW clause indicates that the trigger operates on each affected row.

So, when we return a SIGNAL, it prevents the updation or deletion or insertion which is happening there, and when it doesn't run, the query works fine
But, here, you can set your own update values or insert values by calculating them here, and directly updating or inserting like,

```
SET NEW.attr = Value;
```

This will override the value for the attr that is being passed

In the case of UPDATE,
You can access the original or OLD values whichc are there in the tuple selected like this,

```
OLD.attr
```

or to have some computation,

```
NEW.attr =  OLD.attr + 1000;
```

So this will override the value for the attr provided from the query, and then write it to the tuple.

Here, you can do pretty much same like what you can do INSIDE a PROCEDURE
i.e you can have here DECLARE statements to declare VARIABLES and CURSORS



```
CREATE TRIGGER prevent_order_deletion
BEFORE DELETE ON orders
FOR EACH ROW
BEGIN
  DECLARE item_count INT;
  SELECT COUNT(*) INTO item_count FROM order_items WHERE order_id = OLD.order_id;
  IF item_count > 0 THEN
    SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Cannot delete order with associated items.';
  END IF;
END;
```

Here, as you can see, we are using variables inside the trigger, and checking how much entries are there in the order_items which
have that order_id which we are going to delete,
and if there exists even one, as considered in the IF condition, then we are going to deny the DELETE operation on the current TUPLE
So that SIGNAL is important to convey the info.





```
SELECT TRIGGER_NAME, ACTION_TIMING, EVENT_MANIPULATION
FROM information_schema.TRIGGERS
WHERE EVENT_OBJECT_SCHEMA = 'your_database_name'
  AND EVENT_OBJECT_TABLE = 'your_table_name';
```

Here, you can see all the triggers on your table present in a particular database.




```
DROP TRIGGER [IF EXISTS] trigger_name;
```

This drops the trigger if exists, preventing any error messages to pop up 




