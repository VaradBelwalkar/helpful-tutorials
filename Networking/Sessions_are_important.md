## Why Server Side Sessions are required?

Sessions play a crucial role in web applications, even when utilizing JWT for authentication. Despite relying on JWT to trust embedded claims, there are scenarios where session objects become essential on the server.

Consider the following scenario:

### Login Process:

John initiates a login page via a GET request to the endpoint /login.
He submits credentials secured by a CSRF token through a POST request to /login.

### Authentication:

Upon successful backend authentication, a JWT is generated, containing claims with information about John, such as his username.
John's client retrieves this token from the response, enabling authorized requests to the backend.

### Logout Process:

When John completes his tasks and decides to log out, he triggers a specific action on the frontend.
This action sends a logout request along with the specified JWT.

### Challenge:
 
At this point, the backend faces a challenge: it cannot invalidate the JWT, as it is self-expiring after a specified time.
Storing all JWTs of logged-in users is impractical and goes against the nature of JWTs.

### Introduction of Sessions:

Create a backend structure comprising a simple "username" and a boolean field, e.g., "isActive" (set to "True" if the user is logged in).
When a user logs out, this structure is destroyed.

### Session Storage:

A map can efficiently store sessions:
```
var sessions = map[string]bool{}
```
Using a map is preferred for its efficient hashing capabilities, eliminating the need for arrays or slices.
So everytime a user sends JWT, the username or whatever predefined key is taken from the JWT token, and checked against stored session,
if session doesn't exist, it will simply discard the request. 
