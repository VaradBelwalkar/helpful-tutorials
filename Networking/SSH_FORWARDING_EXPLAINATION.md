

# Establishing Encrypted Communication with SSH Tunneling

## Scenario Overview
Consider the following scenario:
- I have access to two PCs in a network full of intruders.
- A service is running on machine 2, which I need to access from my machine 1, physically located elsewhere.
- I have root privileges, and SSH is running on machine 2, accessible only with my private key (password authentication turned off).
- Setting up certificates is cumbersome in client code, making it time-consuming.

## SSH Tunneling Solution
To address the plaintext communication issue, SSH Tunneling can be utilized for encrypted communication between machine 1 and machine 2.

### Local Forwarding
Suppose the command:

```shell
ssh -L 8080:localhost:80 user@remotehost
```

This command creates a "Local Forwarding" of SSH, allowing access to a service on port 80 on the remote host. Requests to machine 1's port 8080 are tunneled to machine 2, establishing a TCP connection to localhost:80.

### Reverse SSH Tunnel
Suppose the command:

```shell
ssh -R 8080:localhost:80 user@remotehost
```

In this "Reverse SSH Tunnel," machine 2's port 8080 is tunneled, meaning traffic to machine 2's 8080 port is forwarded to machine 1. The TCP connection is established, and the response is sent back through the tunnel.

This is particularly useful for scenarios behind NAT where services need to be exposed to the public.

## How to Establish Reverse SSH Tunnel Between Two PCs Behind NAT Using Relay Server

### Prerequisites
- Relay server's hostname or IP address
- Your username and password for the relay server

### On the Machine to Be Accessed Remotely
Run:
```shell
ssh -N -R 49101:localhost:21001 relayuser@relayhost
```
Explanation:
- `-N`: Forwards ports only without logging in.
- `49101`: Port on the relay server (adjust if not available).
- `21001`: Port on the remote machine where the service will run.

### On the Client Machine
Run:
```shell
ssh -N -L 8080:localhost:49101 relayuser@relayhost
```

Explanation:
- `-N`: Forwards ports only.
- `8080`: Any request to this port on the client machine will be tunneled to the relay server, creating a TCP connection to port 49101.

This workflow establishes a reverse SSH tunnel, allowing secure access to the remote machine's services.

### Logging into Remote Machine Using SSH Through SSH Tunneling
No need to change anything on the client side. Just make an SSH connection like this:

```shell
ssh -p 8080 username_on_remote_machine@localhost
```

This ensures that traffic is forwarded to port 22 on the remote machine, where SSHD is listening.


