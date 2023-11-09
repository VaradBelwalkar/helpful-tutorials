
Update a column

```
UPDATE employees
SET salary = 5000;


(Here all the tuples are going to get affected by this)
```


Update specific row/s

```
UPDATE customers
SET status = 'Inactive'
WHERE last_purchase_date < '2022-01-01';
```


Updating multiple columns

```
UPDATE products
SET price = price * 1.1, stock = stock - 1
WHERE category = 'Electronics';
```

Updation with subquery

```
UPDATE orders
SET total_price = (
    SELECT SUM(price)
    FROM order_items
    WHERE order_id = orders.order_id
)
WHERE order_status = 'Pending';
```










