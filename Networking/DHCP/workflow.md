Suppose you have a setup of routers and switches with all necessary subnetting done at the routers' end, but the pcs are not yet connected,

And you have the task of configuring the pcs with subnet-mask and gateway ip address with assigning ip addresses even unqiue ones, to ensure that they will not collide

You may say it is fine, as it is one time process right?

Well, it is not, you are only thinking about computers, but what about laptops which are portable and can be connected anywhere, perhaps in different-different subnets lots of time?

Here comes the problem, well you need to just change the subnet-mask and ya, the ip address, and here, again you need to check whether some pc already has that ip or not,
 here it becomes more problematic right, because finding out if some pc or computing device has this ip is difficult task isn't it?

This is more and more problematic in the cases of large private networks and wait,

When you have wireless communication infrastructure where devices can communicate wirelessly, how do you configure wireless devices (mostly cell phones) here?

Well simply configuring the unique IP and gateway IP and the subnet mask is not enough, why?

Because this is wireless network, and the connecting device needs to know at which frequency to operate, and the gateway needs to also know that a device with that frequency is 
listening and is authorized, how do you do all that, so here we need automation,


First we will talk only about DHCP in wired medium only...



The DHCP works on the principle of DORA,
Discover
Offer
Request 
Ack



Here suppose there is a DHCP service listening at the ip address 198.168.4.20/24 on port 67 which is mostly the case, 

And the PC which we are going to connect in the LAN is configured to get IP and all configuration from the DHCP server, so it has DHCP protocol built in the OS itself

So when the PC is connected to the LAN, the computer knows that it has the active wired connection lets say on en0 interface,


Here understand that the protocol is Application layer protocol, and it uses UDP as transport layer,

Here, The UDP layer consists of source port as 68 always and dest port as 67 always, yes always it is

Then the DHCP protocol contains lots of fields which you can see by visiting :  https://www.cloudshark.org/captures/0009d5398f37



Here understand that the DORA messages are all broadcast :
Because the frame gets created using only ARP table and the entry in the ARP table are only considered, so h+ere, as the device is newly joined, there is no ARP entry over there,
so all are broadcast.



here the discover message is consumed by the DHCP server, and then sends an offer message with a reserved ip address from the ip address pool available

Here, when the client or the requester gets the offer message where the offer message is again the broadcast one, it has options to accept given ip address or not, if it accepts, 

it then sends the the request message that it wants the given or offered ip address, where the request message is again the broadcast request, the DHCP server gets the request message
and then replies with a Ack message which contains the allocated ip address and some other useful information which is critical such as gateway ip address, subnet mask of the network,
ip lease time, renewal time etc.

The computer or pc then updates the information and then is able to communicate in the network.

The computer or pc however needs to update the lease time after specific interval

Here when the pc changes or switches its subnet, how does it come to know that it needs the DORA sequence again?












