The MongoDB shell provides the following methods to delete documents from a collection:

To delete multiple documents, 
```
use db.collection.deleteMany().
```

To delete a single document, use db.collection.deleteOne().

To delete all documents from the sample_mflix.movies collection:
```
use sample_mflix
db.movies.deleteMany({})    // Here you give empty filter, means catch all filter
```

To delete all documents from the sample_mflix.movies collection where the title equals "Titanic":
```
use sample_mflix
db.movies.deleteMany( { title: "Titanic" } )
```

To delete the first document from the sample_mflix.movies collection where the cast array contains "Brad Pitt":
```
use sample_mflix
db.movies.deleteOne( { cast: "Brad Pitt" } )
```