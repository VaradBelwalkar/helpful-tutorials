Union is an alternative to FULL join as MySQL doesn't suppose full join

It simply accepts two queries one on left one on right of it,and simply stacks up the second result on the first provided that,

      1.) The number of columns for both the results are same
      2.) The datatypes of respective columns which are going to get stacked up must be same or supportive/convertible 
          and also bind the size limitations

Example,

```
SELECT *
FROM TableA
LEFT JOIN TableB ON TableA.id = TableB.id
UNION
SELECT *
FROM TableA
RIGHT JOIN TableB ON TableA.id = TableB.id
WHERE TableA.id IS NULL;
```

Here, we are first making left join in the first select query then a right join in the second select query and then uniting them together

Here, you need to ensure what columns you are considering in both the queries as per above considerations

So, you have already understood that Union just works by stacking the results together but also ENSURES that no duplicate entries are going to be 
there in the final result

What it does is simply gets the result table from the first result, and maintains the table attrs from there itself and then takes the tuples from
the second result and tries to stack down actually on the first result and thus removes duplicate entries from that second result and then stacks down




