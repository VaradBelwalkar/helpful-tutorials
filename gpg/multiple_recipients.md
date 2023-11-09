When you run the following command:
```    
gpg --encrypt --recipent <recipent name or email as per pubkey> file_to_encrypt
```

here there is only single recipient, so the gpg will directly encrypt the file with the public key of the recipient and create a .gpg file


but supppose you give multiple recipients like this:
```
gpg --encrypt --recipient <r1> --recipient <r2> --recipient <r3> file_to_encrypt
```

Here the gpg first, creates a symmetric key and encrypts the file, and then encrypts the symmetric key each with public key of the recipient so if there are 3 recipients
3 encrypted symmetric keys will get created and they are going to get appended to the encrypted file along with their metadata
