To display the database we are using (default one is test): 
```
db
```
To switch to an existing database or create new database and switch to it:
```
use <db_name>
```
To insert a document in a particular collection:
```
db.myCollection.insertOne( { x: 1 } );
```
if the collection doesn't exist, mongodb will create one and insert the document in it

Clear the mongosh Console

The cls command clears the console. You can also clear the console with Ctrl + L and console.clear().
