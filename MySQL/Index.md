
Create and index

```
CREATE INDEX idx_category_price ON products (category, price);
```

To show index for a particular table

```
SHOW INDEX FROM table_name;
```

To drop a particular index

```
ALTER TABLE table_name DROP INDEX index_name;
```
