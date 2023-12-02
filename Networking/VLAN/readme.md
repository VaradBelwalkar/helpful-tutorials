VLAN are inevitable in today's world for the companies, why?

Before answering why, let me tell what does VLAN mean in the first place,

well, you know that in large corporate network, suppose you are network engineer and your company has bought some ranged ip network,
and suppose in particular section, you have performed NAT to avoid incoming connections hit the private network,

And in this private network, you have around 1k devices such as media computers, sales computers, and marketing teams' computers,
also you have servers which need a lot protection which are internal servers not intended for the outside world,

and as you can guess, the public ip range the company has bought is to provide services externally through some other partial network,
and this private network is intended to be used only for accessing internet and doing internal company's work,

as here are around 1k devices and suppose from them you have 10 servers which needed to be more secure, but you think that these are in
private network and are safe, but not they are not, unless all the other devices in the network are safe

here, you might think that VLAN is not actually solution but we can do subnetting for the private network and assign the network range
to internal computers which are then connected with the switch right,

well this approach has a problem, when you supppose assign first subnet to computers which don't have do anything with the servers, then
you can configure firewall on the router outgrowing into the servers' network to even block the private range which is for those computers,

but let me tell you, routers are not cheap, they are pretty expensive than switches, yes that is the problem,

and if you have to subnet a lot of times i.e subnet into more smaller and smaller group of computers and servers, that is not a viable option,
as you have to invest in both routers and switches as well,

And this is also not going to work if you want some computers but not all from a particular subnet to access the servers in another subnet,
how do you configure the router for that, you might say well by only allowing particular ip addresses right,

well those computers are getting ips from DHCP, so your method of allowing only some ips doesn't work here right,

well you might also say that the broadcast domain is also not violeted here, as the subnet, that is the broadcast network right,

but let me tell you, suppose again some computers from one subnet need to talk to some computers from another subnet but to not all,
and vice versa, are you going to again to firewalling over there for just these pcs, and again setting up firewall here, to not allow certain traffic
to certain computers?

here you just not only need to indentify the traffic's network, but also need to configure individual ips to allow or block traffic to certain
pcs in the network, this is rediculous and time consuming and not scalable and if you are allocating ips with DHCP, then it is going to be really
hard,

So what is the solution?

The solution is really simple, it is not only cost effective, only requires switches and not routers, and also minimizes broadcast domains
and also help us to talk certain pcs to only certain pcs and not all,

it is VLAN,

The VLAN feature is available in almost all layer 2 switches and of course in all layer 3 switches as well, but we only focus on layer 2 switches
as we don't require layer 3 switches in most cases.

To really connect the entire LAN of 1k devices, you suppose might need 80 switches, as in above scenario with subnetting you would require
not only 80 switches but also more routers along with that with so much tedious task

well you just require layer 2 switches and just connect them to each other with their interfaces,

so that all the computers and servers and all are in the same network, and as of now they can talk to each other,

now its your time to simply put the interfaces of the switch into appropriate VLANs and you have to do it in all the switches (normally)
so that the computer connected to an interface of switch which is in VLAN2 can only talk to computers or servers which are connected to interfaces
of switches which are in VLAN 2 only, and thus, the broadcast domain is minimised as you broadcast request/response will not go to all the devices
but to only devices which are part of the same VLAN.

Here, first understand that if you don't configure VLANs at all, all the devices are in VLAN 1 by default, so they can talk to each,

when you put interfaces in appropriate VLANs, you also need to put the interfaces which are connecting two switches together into Trunking,
which means that they now can follow 802.1q protocol which allows padding the frame with VLAN information so that other switch can know that
the frame coming is from which VLAN,

of course, the switch can absolutely know its interfaces are in which VLAN, the the frame coming from other switch, this switch will not know the
computer with this MAC address is in which VLAN as it obviously doesn't know on which interface it is connected as that is not its interface right,
of course i know that the switches doesn't consider the MAC to interface mapping to determine which VLAN the frame belongs to, as they simply identify the frames are in which VLAN by simply seeing from
which interface they are coming from and that interface belongs to which VLAN,

and for sending, now it checks the MAC to interface binding and checking to which VLAN that interface belongs to and to send it or not,

so how does the next switch will know the traffic generated from switch one, is from which VLAN, as it doesn't know the VLAN configuration of that
switch of course,

so this is the reason for using the trunking protocol on the both the interfaces, where the switches understand that 802.1q protocol which contains
VLAN information which is of 4 bytes, so a 1514 bytes frame would become 1518 bytes

But you need to make sure that the,
negotiation of trunking is off,

otherwise if you make your computer's interface as trunk port/interface using tools like yersinia,
the negotiation of trunking if on, the interface of the switch will recognise this trunk port and will become trunk port/interface itself,
and this is the problem,

now you are not in any VLAN, as the ports/interface which are trunks are not in any VLAN, as they are required to provide VLAN info to other switches,
but how does this switch know that i am not a switch but an infected or malicious computer which is trying to access other VLANs

as here i can simply substitute the frame going outwords with the VLAN i want to access, and the switch will not complain as it doesn't know me i.e
it doesn't have my MAC address mapped to any interface as the interface i am connected to is trunk port, and trunk ports though are mapped to
multiple MAC addresses, but they are not in any VLAN right, so the switch thinks that there is only one computer connected to the switch on the
other side of its trunk port/interface so simply maps my MAC to the trunk port but solely relies on the stuffed VLAN info in the frame
as of course it cannot assign VLAN to the trunk port as the traffic coming from the other switch can be for same or different VLAN of course!

so the negotiation of trunking must be off so that even if my computer pretends that its interface if trunked, the switch will NOT move to make
its interface to be trunked as well, so this will not happen,

so the only option to configure the interface as trunk is to manually go or access the switch remotely and configure the interface through
CLI, and thats it!

This solves the broadcast domain problem as the switch will only forward the broadcast frame to the interface belonging to the same VLAN else not.

So even if a computer got infected or attacked by an attacker, it cannot simply use tools like yersinia to do trunking and access any VLAN

This is called the VLAN hopping attack and the negotiation of trunking to be made off to prevent this attack.
