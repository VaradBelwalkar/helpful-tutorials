
## What is VPN in the first place?

VPN is what it says, Virtual Private Network.
**but what does that exactly mean?**

Suppose you are using internet connection available in your university, and connecting to internet,
in this case, university has private network setup which allows you to access internet, but here,
you can definitely get traced because well, ultimately the traffic will be coming and going to your 
univerisity's main router, and of course, the ISP has records for that,
and your university might as well keep records of what you are visiting through firewall which is common scenario.

But with the VPN, you can get into private network, but here in this case it is virtual in some 
other geographical region, which keeps your identity private(mostly!)
Here, it is very hard to trace your identity and what you have visited, when you are visiting VPN

If you are accessing VPN in your university, university will find a normal valid ip address that you are visiting, but mostly it doesn't know it is VPN, and has no control over what you are accessing and how you are accessing.

it is like you are virtually in that private network, i.e your PC or laptop is in the private network which is on some server which you don't handle.

Fine now you understand how VPN works, lets understand how AWS allows you to create a VPN and let you connect  to it...

---

When creating a VPN in AWS, you can do following things:
- access private resources not routable on the internet. e.g instance not having public IP.
- access internet securely to access some content which is restricted in your geographical location
- have controlled connectivity for VPN clients to be able to access internet.
- Only allow connectivity from your VPN for a particular resource and not from internet though the resources are publically available. e.g. having administrative previlledges work only when admin connected from VPN and not exposing the admin API over internet
- etc.

There are more use-cases of-course than this. But you got the point.

---

### Well, lets dive deep into how everything fits together.


When you need to create a VPN, what basically you are doing is creating a VPN service, which, will
let users connect to it.
you can, 
- restrict which users can access the VPN using mutual authentication
- restrict users over subnets and internet connectivity.

VPN is of-course over HTTPS, so who is going to provide the secure connection?

VPN is a kind of lightweight service which listens for client connection requests and based on required auth, it lets users connect to it.

But to provide secure connection, you need an SSL certificate right?

You can request a certificate from the AWS certificate manager, but wait, should you do it?


Requesting a certificate from the AWS Cert Manager will authorize a certificate for a domain.
suppose you have bought ```example.com``` domain, and setup static hosting on s3-bucket, and want to secure your client connections, so you request a certificate from Cert Manager,
where you **prove** your domain ownership.
So then you can use that cert in cloudfront to secure your domain.

But here is the catch, your clients can get the Secure connection when they connect to your domain whcih you have validated when requesting the certificate right?


But when you create a VPN client in the AWS, that has different endpoint, something like,

```text
cvpn-endpoint-06cfc1ca6ccea985c.prod.clientvpn.us-east-1.amazonaws.com
```

This is the endpoint that I got when I created a client VPN.

So do you handle this domain?
is there any point in requesting a cert from AWS for this domain?
Of course not!

What you simply need to do is create a custom certificate and sign it with certificate authority of your own!

### Create client and server Certs in your linux machine.

To create client and server certificates, you must have a certificate authority which signs those certificates right?


> Here understand that we need to have **mutual authentication**, meaning we also need to authorize the clients which are connecting to the VPN, and allow only them for connecting.

> steps are taken from [AWS VPN Guide](https://docs.aws.amazon.com/vpn/latest/clientvpn-admin/mutual.html)

1. Clone the OpenVPN easy-rsa repo to your local computer and navigate to the easy-rsa/easyrsa3 folder.

```shell
git clone https://github.com/OpenVPN/easy-rsa.git
```
> this provides easy workflow for creating and managing certs.

2. Initialize a new PKI environment.

```shell
./easyrsa init-pki
```

3. To build a new **certificate authority (CA)**, run this command and follow the prompts.

```shell
./easyrsa build-ca nopass
```
> no pass means you don't require passphrase to use that ca-cert.
Basically you are creating `ca-cert` which will act as root-certificate and `private-key` for that certificate


4. Generate the server certificate and key.

```shell
./easyrsa build-server-full server nopass
```
>This creates server certificate and its private key, here certificate gets created which means it is also signed by the certificate authority by using its private key.


Now you can optionally can generate client certificates. 
This means that you can generate separate certificate for each client or use the same for everyone.
However it is recommended that you use separate certificate for each client, so in case that employee
leaves your organization, you can simply revoke that certificate, rather than revoking the common one and giving everyone a new cert.

But for our usecase one cert is enough. so lets go ahead and create it.

5. Generate the client certificate and key.

```
./easyrsa build-client-full client1.domain.tld nopass
```

6. Copy the server certificate and key and the client certificate and key to a custom folder and then navigate into the custom folder.

```shell
mkdir ~/custom_folder/
cp pki/ca.crt ~/custom_folder/
cp pki/issued/server.crt ~/custom_folder/
cp pki/private/server.key ~/custom_folder/
cp pki/issued/client1.domain.tld.crt ~/custom_folder
cp pki/private/client1.domain.tld.key ~/custom_folder/
cd ~/custom_folder/
```

This is to simplify the workflow for uploading this certs to AWS.

---

### Uploading certificates to AWS Certificate Manager

here, you can either use ```aws-cli``` or aws-console to upload the certificates.

But we will follow console based method for simplicity.

Head towards **AWS Certificate Manager**, and click **import Certificate**.

{{< figure src="/images/VPN-AWS/certimport.png#center" link="/images/VPN-AWS/certimport.png" target="_blank" class="align-center" >}}

Here, give the details, like **server certificate**, **Private Key** and optionally the certificate chain.
But here, you must provide the certificate of CA.

Here if you don't provide CA Cert, even in normal cases of simply attaching to a domain, your client browser will request certificate, and when it gets this, will try to authorize with the built in CA certs that it trusts, and when it don't find any CA cert that can authorize this server certificate
it fails to authorize it and doesn't setup TLS.

But when you also provide the CA cert along with the server certificate, the client can authorize it and can establish the secure connection, but of course, it will try to backout as the certificate is custom and not globally accredited.

But in our case for VPN connections, this is fine and the recommended way of managing certs.

So when client connects, it will be able to authorize the server using the CA cert, and successfully establish connection to the server via **TLS**.

Now, when you provide the CA cert in the certificate chain, of course you have only two hierarchy in the certificate chain, one is server cert ,and the other is the root cert or ca cert which actually signs the server cert.

So you simply need to give CA cert in the certificate chain.

Now your certificate is imported! Congrats!

---

Now you can optionally import Client certificate here.
But in our case, it is **not required**.
Why?

Because when our VPN service requests the client to bring its own certificate, and client sends it,
the VPN service authorizes it on the basis of certificate chain right?
but if client doesn't send the CA cert, then how this service authorises it?
Well it fallbacks to using the certificate chain provided by us for the server.

And as we have created the client certificate and signed it using the same **CA authority**
The service will successfully be able to authorize the client certificate.

But if you have used different **CA**, you need to import exactly the same you imported the server cert.

This also proves security. why?

Because **no one** can use any certificate other than signed by your **CA authority**, which is residing in your linux machine!

So even if a person has globally accredited certificate for his server, his of-course won't be able to access our VPN service as the server would fail to authorize it as its certificate is not signed by our **CA Authority**

---

### Creating Client VPN Endpoint

This step actually creates a VPN where users can connect.

Here, go to the **Client VPN Endpoints** section in the VPC.

{{< figure src="/images/VPN-AWS/vpnendpoint.png#center" link="/images/VPN-AWS/vpnendpoint.png" target="_blank" class="align-center" >}}

Create an Endpoint.

Here, give,
- name for the endpoint (optional)
- Give the CIDR block from which your clients will get private IP addresses.
Don't give CIDR block which can conflit with the subnet that you want to work with.
- Give server certificate that will be used for secure connection.
- Check the mutual Authentication box to authorize clients as well
Here for ```Client Certificate ARN```, choose the same server certificate. 
This makes sure that the VPN service will authorize the clients based on the CA cert of the server itself. i.e it will use the certificate chain of server certificate to authorize the client certificate. If you have used different ```CA``` for client certificate, make sure to import that first and choose it.
- You can optionally set the DNS server to use here. remember there is no default DNS server configured for your VPN, so if you plan to access internet from this, make sure to add DNS server here.

Leave everything blank as we don't require other things for this demonstration.

Now you have setup the Client VPN.
Its now time to give Clients access to a particular **subnet** or **subnets**.

To configure this, simply go to the **target network associations**

and then choose **Associate target network**

{{< figure src="/images/VPN-AWS/network-association.png#center" link="/images/VPN-AWS/network-association.png" target="_blank" class="align-center" >}}

Here, choose the subnet that you want to access from your VPN.

There is a **route table** associated with this VPN, and when you associate the subnet, 
it automatically creates entry in the route table.

{{< figure src="/images/VPN-AWS/vpn-route-table.png#center" link="/images/VPN-AWS/vpn-route-table.png" target="_blank" class="align-center" >}}

Here, you can also add custom route entries, like for accessing internet.


But remember, you can only access internet with the help of a subnet.

So if you have configured Internet Gateway for that VPC, you can go on the internet from the VPN
when you add ```0.0.0.0/0``` route in the route table and select the ```target network``` as the subnet which has internet access.

Here remember that **by-default**, VPN configures NAT by which you can reach the internet, so even if the subnet doesn't have access to the internet, but if internet gateway is there, you can access the internet from the VPN without any extra configuration. That's great!

But small things are remaining which are needed to do in order to full setup your VPN.

First, head towards **Authorization Rules** and create the rule where all or some of your clients are able to access what they want.

If you want to allow all the clients wherever they need to go according to route table, simply
allow them for ```0.0.0.0/0``` network.

These rules allow you to give fine-grained access for your VPN clients, so even if the route table of the VPN has multiple routes, it is your resposibility to give each client specific access or give all of them full access to all the networks(subnets) that you have associated.

---

### Testing

Now everything setup, try creating an **EC2 instance** in the region same as your VPN, and make it private purposefully.
Also make sure to create it in the subnet that you have associated with the VPN.

Now you can't access this instance from the internet right?
And before this there was no way with which you could gain access to this instance right?

Meaning if you headed towards connect, and try connecting, AWS would error out that the instance is private.

In order to connect to it, there was only one way there, **bastion host**, which is again not that secure considered you still require a public endpoint from which you will access private resource.

But now, with the **Client VPN**, you can successfully access the instance as the subnet in which it lies is associated with the VPN.

So download the Client configuration from the top bar.

You get an ```.ovpn``` file.

Now before start using it, few changes are required.

The changes are because, if you didn't setup **mutual authentication** for VPN, you can use this file directly to connect to the VPN.

But as you have **mutual authentication** enabled, you need to provide the **certificate path** and **private key** path in this ```.ovpn``` file.

So before changes the file looks like,

```text
client
dev tun
proto udp
remote cvpn-endpoint-00e16cdbf058cc151.prod.clientvpn.us-east-1.amazonaws.com 443
remote-random-hostname
resolv-retry infinite
nobind
remote-cert-tls server
cipher AES-256-GCM
verb 3
<ca>
-----BEGIN CERTIFICATE-----
<the certificate here>
-----END CERTIFICATE-----

</ca>


reneg-sec 0

verify-x509-name server name
```
Here you don't see any configuration for client certificate and its private key.

Now as I previously told you to store all the files in ```custom_folder```, including client certificate and its private key.
grab there fully qualified path and paste them like this so the end result is like,

```text
client
dev tun
proto udp
remote cvpn-endpoint-00e16cdbf058cc151.prod.clientvpn.us-east-1.amazonaws.com 443
remote-random-hostname
resolv-retry infinite
nobind
remote-cert-tls server
cipher AES-256-GCM
--cert "/home/varad/custom_folder/client.domain.tld.crt"
--key "/home/varad/custom_folder/client.domain.tld.key"
verb 3
<ca>
-----BEGIN CERTIFICATE-----
<the certificate here>
-----END CERTIFICATE-----

</ca>


reneg-sec 0

verify-x509-name server name

```
see those ```--cert``` and ```--key```, and paste your paths in front of them.

Now when that is done, it's done!

You **cannot** use the aws-cli for connecting to this VPN.

So Now head over to the [aws vpn client download]()
to download the appropriate client for your system with which you can connect to the VPN you just set up.

I prefer the **windows/macos client** as for linux, you require outdated linux machines (18.04 & 20.04) and i bet most of you people won't even have it.
And don't even try to download this client in suitable docker container or VM, as this might cause unnecessary troubles(I tried a lot :| )

So if you are having windows client, make sure to change path in the certificate accordingly, and have double back-slashes instead of single in the path.

Now after all this, you can now successfully connect to the VPN!
