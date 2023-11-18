This command line utility is great for watching a particular path for any changes, that too recursively for any nested changes that happen, 
suppose when you run it against a directory `/dir`

Here, any changes under that directory will be shown, be them standard CRUD operations or any other, it will be logged onto the screen.

Example,

```
inotifywait -r -m -e modify,create,delete /path/to/directory
```

This will recursively check, specifically for modify, create and delete. I haven't figured out other options, but these are enough as of now.
