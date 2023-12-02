# JSON Web Tokens (JWT) Introduction

[JWT.io](https://jwt.io/introduction)

JSON Web Tokens (JWTs) are commonly passed in the Authorization header of an HTTP request. The Authorization header is used to send authentication information to the server, and JWTs are a common way to authenticate requests.

It is also possible to pass a JWT in the body of a request, although this is not as common. To do this, you can include the JWT in the request body as a string and set the Content-Type header to "application/jwt". However, keep in mind that most servers expect JWTs to be passed in the Authorization header and may not support passing them in the body.

## Working

When the server creates a new JWT token, it takes the token information (header) and claims (payload) and combines them with a secret key to generate a signature. This signature is included as the last part of the JWT token (signature), and the token is sent to the client.

When the client sends a request to the server, it includes the JWT token in the request headers. The server then decodes the token, which separates the header, payload, and signature. The server uses the same secret key that it used to create the token and the algorithm to generate a new signature from the header and payload. If the newly generated signature matches the signature included in the token, it means that the token has not been tampered with, and the server can proceed with the request.

```javascript
// Authorization is one of the headers available in the HTTP request
// Authorization -----------> "Bearer <JWT-Token>"
// This indicates the authorization method, which is JWT
```

After the user login, a user token is generated, which will look like this:

```
"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWV9.TJVA95OrM7E2cBab30RMHrHDcEfxjoYZgeFONFh7HgQ".

```

It consists of three parts, each separated with a dot(.). The first part is the header, which is Base64 encoded. After decoding, we get something like:

```json
{
  "alg": "HS256", // Algorithm used
  "typ": "JWT"
}

```

The second part is the claims and is Base64 encoded. After decoding, we get something like:

```json
{
  "sub": "1234567890",
  "name": "John Doe",
  "admin": true
}

```

The third part is the signature and is generated with:

```javascript
HMACSHA256(
 base64UrlEncode(header) + "." +
 base64UrlEncode(payload),
 *secret base64 encoded*
)

```
