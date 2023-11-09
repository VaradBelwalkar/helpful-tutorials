
When you upload your key to any keyserver, that keyserver sends an email to the email associated with the publickey    
and only when that email is authorized by the email holder, that key becomes available to others to see and search and download on basis oc email search   
the email typically includes a link which you need to click on in order to authorize that key and let it be publically available    
This minimises the risk of anyone putting publickey on the name of anyone pretending to be someone on the internet    
so you can't just put your publickey with email of other organisation and hope to man-in-the-middle in organization's communication    



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
