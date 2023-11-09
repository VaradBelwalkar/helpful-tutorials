(NOTE NEVER CREATE KEYS WITH SAME NAME OR EMAIL, THIS CAN MAKE BIG PROBLEMS WHILE USING OR DELETING THE KEYS)

To create new key : 
```
gpg --full-generate-key
```        
To show public keys with their fingerprints:
```
gpg --list-keys
```   

To show private keys with their fingerprints(same as their associated public keys' fingerprints)
```
gpg --list-secret-keys
```       
        
To export public key:
```
gpg --armor --export <fingerprint>
(armor means export in ascii format)
```
To export private key:
```
gpg --armor --export-private-keys <fingerprint>
```

To encrypt file with pubkey of one recipient:
```
gpg --encrypt --recipient <name or email as per pubkey>  file_to_encrypt
```

To encrypt file with pubkey of multiple recipients (follow another file along with this file to understand the workflow)
```
gpg --encrypt --recipient <r1> --recipient <r2> --recipient <r3>  file_to_encrypt
```    
        
To decrypt the file with the private key ( Please note that
there is always associated a metadata with the file which
tells the key id i.e name or email so gnupg takes only that

(private key which matches the metadata, if it doesn't find it returns error that it cannot\ decode)\
```
gpg --decrypt file_to_decrypt
```

To get keygrip:
```
gpg --list-keys --with-keygrip
```

To get in machine readable format:
```
gpg --list-keys --with-colons
```

To delete a key-pair, you first need to delete the private key:
```
gpg --delete-secret-keys <name or email or fingerprint>
```     

Then delete the public key:
```
gpg --delete-key <name or email or fingerprint>
```     
        
To import a key (doesn't matter whether it is public key or private key)
```
gpg --import <key_file>
```
To dearmor a .asc key, i.e key in ascii format do this :
```
sudo gpg -o <path_to_outout_key.gpg> .asc_key --dearmor
```