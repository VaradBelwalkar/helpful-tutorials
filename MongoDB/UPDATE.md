The MongoDB shell provides the following methods to update documents in a collection:

To update a single document, use 
```
db.collection.updateOne().
```
To update multiple documents, use 
```
db.collection.updateMany().
```
To replace a document, use 
```
db.collection.replaceOne().
```


To update the first document in the sample_mflix.movies collection where title equals "Twilight":
```
use sample_mflix
db.movies.updateOne( { title: "Twilight" },
{
  $set: {
    plot: "A teenage girl risks everything–including her life–when she falls in love with a vampire."
  },
  $currentDate: { lastUpdated: true }
})
```
The update operation:

Uses the ```$set``` operator to update the value of the plot field for the movie Twilight.

Uses the ```$currentDate``` operator to update the value of the lastUpdated field to the current date. If lastUpdated field does not exist, $currentDate will create the field.




To update all documents in the sample_airbnb.listingsAndReviews collection to update where security_deposit is less than 100:
```
use sample_airbnb
db.listingsAndReviews.updateMany(
  { security_deposit: { $lt: 100 } },
  {
            $set: { security_deposit: 100, minimum_nights: 1 }
  }
 )
```


To replace the first document from the sample_analytics.accounts collection where account_id: 371138:
```
db.accounts.replaceOne(
  { account_id: 371138 },
  { account_id: 893421, limit: 5000, products: [ "Investment", "Brokerage" ] }
)
```

        Here understand that second argument is entire document to replace with the original one.

