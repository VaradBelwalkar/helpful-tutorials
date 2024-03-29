To return all documents from the sample_mflix.movies collection:
```
use sample_mflix
db.movies.find()
```

To return all movies where the title equals Titanic from the sample_mflix.movies collection:
```
use sample_mflix
db.movies.find( { "title": "Titanic" } )
```
To return all movies from the sample_mflix.movies collection which are either rated PG or PG-13:
```
use sample_mflix
db.movies.find( { rated: { $in: [ "PG", "PG-13" ] } } )
```

To return movies which were released in Mexico and have an IMDB rating of at least 7:
```
use sample_mflix
db.movies.find( { countries: "Mexico", "imdb.rating": { $gte: 7 } } )
```

To return movies from the sample_mflix.movies collection which were released in 2010 and either won at least 5 awards or have a genre of Drama:
```
use sample_mflix
db.movies.find( {
        year: 2010,
        $or: [ { "awards.wins": { $gte: 5 } }, { genres: "Drama" } ]
} )
```


We can add projection to the find command: 
```
db.inventory.find( { status: "A" }, { item: 1, status: 1, _id: 0 } )
```


