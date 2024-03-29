In databases, a cursor is a database object used to retrieve and manipulate rows from a result set or query. 
Cursors provide a way to navigate through the records returned by a SELECT statement or perform row-level operations on a result set

---

Cursor is not something like triggers and procedures in mysql,
Triggers and procedures are independent SQL units which run autonomously (although procedure needs to be called, but you got it)
But, Cursor are not something like that, what cursors do is they help you to ITERATE over a RESULT TABLE,
Yes, that is only there job, and you have to do all the aspects to use it i.e fetching the value in a variable, then using it,
So, CURSORS are helping units that help you to iterate over a result, nothing else,
So that is the REASON, CURSORS cannot be created, but only can bed DECLARED INSIDE a PROCEDURE OR A TRIGGER to HELP 
the WORKFLOW, and that is the reason they lie only in MEMORY, and not on the secondary storage i.e not stored.

FOR EXAMPLE,

You can consider a BASH script as a TRIGGER which is going to run on specific interval, while the LOOP
inside it is going to run only when the BASH IS GOING TO RUN, and it makes no sense to use the loop outside the script right?

Similar goes with procedures as you can imagine them to be functions in programming languages, and loops are being used in 
that

---

**MOST IMPORTANT**
You can only declare and use the CURSORS in the procedure only,
as you use DECLARE keyword to declare the cursor, and that KEYWORD
is only valid inside a PROCEDURE
And the cursor can only be used with the SELECT statement as that is the only statement which brings in the result table
or tuples.



So what happens using the CURSOR is, the cursor allows us to use the result tuples individually, step by step or you may say
allows LOOPING through the result table, 
and work on each result tuple individually



To declare a CURSOR (of course in the PROCEDURE)

```
DECLARE cursor_name CURSOR FOR SELECT column1, column2 FROM table_name;
```

Now you can open the cursor to actually use it, this would execute the query and buffer the result to be used 
```
OPEN cursor_name;
```






**Consider the following CURSOR**
```
CREATE PROCEDURE GetEmployeeNames
AS
  DECLARE
    cursor_employee CURSOR FOR
      SELECT employee_name FROM employees;
    employee_name employees.employee_name%TYPE;
  BEGIN
    -- Open the cursor
    OPEN cursor_employee;

    -- Fetch and process each row from the cursor
    LOOP
      FETCH cursor_employee INTO employee_name;
      EXIT WHEN cursor_employee%NOTFOUND;

      -- Process the employee name (e.g., display or manipulate it)
      DBMS_OUTPUT.PUT_LINE('Employee: ' || employee_name);
    END LOOP;

    -- Close the cursor
    CLOSE cursor_employee;
  END;
```



Here, we don't necessarilly require AS keyword, we can declare the things after the BEGIN as well
Here, inside AS,
we have a single DECLARE for CURSOR as well as for VARIABLE, which takes the type of the employee_name from that employees table
Here we have declared a single variable as we know that a single field is returned by the SELECT each time

Then what we do in BEGIN is,
We open the CURSOR for usage,

Then, we apply LOOP
then, as we know that looping through the result tuple is nothing but looping through different values of a single field, so we only have one variable
here,
So,

We FETCH the value from that CURSOR INTO the declared variable

Then after that we have CONDITION for the LOOP, which says that when cursor_employee%NOTFOUND, then EXIT the loop
```
DBMS_OUTPUT.PUT_LINE('Employee: ' || employee_name);
```
This line simply displays the Line on the screen, and then

END LOOP,

But this doesn't evaluate directly, you MUST obviously NEED EXIT condition else the LOOP will be INFINITE

And after you LOOP successfully,
YOU JUST NEED TO CLOSE THE CURSOR

And of course you work is done, then close the PROCEDURE.









