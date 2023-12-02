## Key Distribution
The process of making your key publicly available on a keyserver is coupled with an important security measure - email authorization. Upon upload, the keyserver sends an email to the associated address with a link for authorization. Clicking on this link is mandatory for the key to be accessible to others for search and download, primarily based on email search.

This approach not only ensures the legitimacy of key ownership but also safeguards against attempts to manipulate key distribution for malicious purposes. The email authorization step adds an extra layer of protection, making the key distribution process more resilient against potential threats.



To send the publickey to the key-server:
```
gpg --keyserver <keyserverurl> --send-keys <fingerprint>
```

For example:
```
gpg --keyserver hkps://keys.openpgp.org --send-keys <fingerprint>
```
          
Now to search for a key on keyserver: (NOTE: Reflection of uploaded publickey takes some time)
```
gpg --keyserver hkps://keys.openpgp.org --search-keys <username or email>
```

Once you find the key on the keyserver, along with the metadata, it will also show the fingerprint for that key,
So to download that public key:
```
gpg --keyserver hkps://keys.openpgp.org --recv-keys <fingerprint>
```

Also other than openpgp,

we have pgp.mit.edu keyserver available
so you can change above url to, [hkp://pgp.mit.edu]
