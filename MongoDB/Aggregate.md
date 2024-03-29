Consider this mongodb pipeline: 
```
        db.movies.aggregate([

          // First Stage

          { $project: { _id: 0, genres: 1, imdb: 1, title: 1 } },

          // Second Stage

          { $unwind: "$genres" },

          // Third Stage

          { $group:

            { _id: "$genres",

              averageGenreRating: { $avg: "$imdb.rating" }

            }

          },

           // Fourth Stage

           { $sort: { averageGenreRating: -1 } }

        ] )"
```




    $project: This stage selects and includes specific fields in the output while excluding the "_id" field. 
    It retains only the "genres", "imdb", and "title" fields from each document. The resulting documents will only have these fields.

    $unwind: This stage is used to deconstruct the "genres" array field from each document. 
    If a movie has multiple genres, it creates multiple documents with the same values for other fields but only one genre per document.
    This prepares the data for further aggregation based on individual genres.

    $group: In this stage, the documents are grouped based on the "genres" field.
    It creates a new field "_id" that contains the distinct values from the "genres" field. 
    Then, it calculates the average rating of movies in each genre using the $avg aggregation operator on the "imdb.rating" field.
    The resulting documents will have the "_id" field representing the genre and the "averageGenreRating" field containing the calculated average rating.

    $sort: This stage is responsible for sorting the resulting documents based on the "averageGenreRating" field in descending order. 
    The value -1 is used to indicate descending order, meaning genres with higher average ratings will appear first in the output.


You can understand the grouping like this: suppose 10 documents are there, with some documents having same genre i.e suppose sci-fi
then above group function evaluates on the basis of value of genre, when it takes first document suppose for processing, and it finds no result documents are created, then
it gets its genre and creates new document and assigns the avg field with the same value, suppose it identifies sci-fi genre document, as it just started processing and no result 
documents are there, it will generate result document with sci-fi _id and avg equal to actual value what that document holds,
suppose afte that it takes next document which has genre thriller, as no result document is there with genre thriller, it creates new one with above approach
suppose after that it finds another sci-fi genre document, then it knows it already has a result document with this genre, so it just calculates the avg field by taking avg of previous 
value and the current value from the document and updates the result, same happens with the other result genre documents until all input documents exaust




