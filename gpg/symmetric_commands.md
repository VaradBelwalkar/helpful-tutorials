To encrypt the file with passphrase:
```
gpg --symmetric file_to_encrypt
```
This will prompt you for the passphrase to enter to encrypt the file,  
To strongly encrypt, create first a symmetric key and use this as passphrase  

To decrypt simply run, and give passphrase when prompted:  
```
gpg --decrypt file_to_decrypt
```   
Here gpg will know whether to use symmetric or asymmtric decryption here

Here gpg after taking the passphrase, uses a key-derivation-function(kdf) to derive a key from the passphrase and use that key to   encrypt the file
