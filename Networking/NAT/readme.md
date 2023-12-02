NAT is by far the most used technology to provide internet access to the public.

You might be knowing that Internet Service Providers such as Airtel, AT&T are providing their customers internet through their cellular network
infrastructure,

Yes, you heard it right, this was and is the major advantage for them as they can establish both cellular network and internetwork on the same
tower which they own, this makes them simplify the implementation of routers which can then provide internet to the public in that region

But how does this work?

You might be knowing that the private ip ranges are,

```shell
10.0.0.0/8

172.16.0.0/14       this means from 172.16.0.0   to   172.31.255.255

192.168.0.0/16
```

But what does this mean?

Well this means that NO RIR i.e Regional Internet Registry NOR the IANA i.e Internet Number Authority can assign or give any ip or network from
these ranges to any organisation or to anyone,
This means no organisation or anything in the world will own any ip or a network from these ranges as their public endpoint

But, understand that we as human beings have assigned these ranges as private ones, the core routers and the provider edge routers
don't understand that unless configured specifically, right,

Here, if any core router or provider edge router has an entry in the routing table for any ip or network from this range,
the interface on which the packet has to sent to, must either belong to that network itself, or must be performing subnetting on that network,
or you may say that it should be provider edge router outgrowing in that network through the interface which is listed in the routing table.

don't consider this as of now,

well you know that these are private ranges and most importantly used to just access internet and let me clear,
they are not used to provide any service to the outside world, remember i am not talking about any special cases like port forwarding or tunneling,
in standared scenario, they are just used to provide internet access to internal network.

So what does NAT do?

It simply makes request on behalf of you and gets the response back to you, yes that is simple!

Your ISP makes a private network (mostly, but just focus here) in one of these range, and runs DHCP service on its end,
and when you on you internet, you get connectivity right?

Yes, but where is you ethernet port ?

how are you even connecting with that router?

Well, in case of wireless networks, you have virtual interfaces through which you connect, and you smart phone will have one, yes only one,
that is why you can either turn network connectivity of airtel or jio, not both right?

So this one virtual interface gets the DHCP allocated ip address within a private range, and gets the other network info such as gateway ip,
lease time and so on.

Remember that the interface to which your mobile phone is connected is again the virtual interface of that router,
and here, as in physical we require switches, here no switches are required as everything is software based or in the control plane itself.

Here, switch you may say is nothing but a collection of mappings of which frequency we need to accept and send packets to a particular endpoint
and the endpoint itself

Here, you smartphone also has routing table, now understand, every computer has a routing table,

when you make a request to ip suppose `120.0.2.2/24`
Here, you phone doesn't have any routing information in routing table about this network right, i.e about `120.0.2.0/24`,
So if the phone doesn't know where to send, it sends to the default gateway,

with source ip lets say `192.168.2.2` and dest ip of that gateway `192.168.1.1`,
with source port `51k` and dest port `80`

now when this request comes to the router, the router knows that it has performed NAT (I WILL EXPLAIN HOW IT KNOWS LATER)
on this particular interface, so what router does, as it is a provider edge router, it will definitely will be running a BGP protocol
with which it can find the next hop for the networks,
so when this packet comes on it, it first finds the network to which it belongs and sees if there is any entry in that BGP table or routing table
you may say,
once it gets the next hop and the ip of next hop,
it simply gets a free port from his pool of ports lets say 40k and makes an entry in the NAT table like following (not exactly)

```
source IP      Dest IP     sourceport      destport       allo.port
192.168.2.2     120.0.2.2      51k            80               40k
```

this entry persists until it becomes inactive(will discuss later),

So what router does, it simply replaces the source ip with the ip address of the interface from which it needs to forward the packet to the
next hop, always remember the ip address of that interface only from which it is going to send it to next hop,
and the source port to 40k and finally sends it.

once it gets the response packet, what does that packet has?
it has source ip `120.0.2.2`, source port `80`,
dest ip `29.20.2.4`, dest port `40k`

Here the router gets this packet from that interface which is having ip `29.20.2.4`,
so first time, router might think that this packet is for itself, so there are configuration dependancies whether router will take time to check
whether any of its services is listening on the port 40k (which obviously not at all possible) or directly go to NAT table when it finds a packet
dedicated for it,

i think the second case would be true, so any way, when the router sees in the NAT table, if there is not entry according to the dest port of
the packet, it discards the packet, yes it discards, and you may say that the indexing of this table is done on the basis of allocated port
so if router finds and entry,

if checks whether the packet is following everything or not, i.e it is coming from the intended destination, the port is correct,
and so on, once it is checked, the router simply changes the destination ip to `192.168.2.2` here, and also the destination port to 51k as before,
and then it checks in the routing table where to send that packet to, so it finds the interface to which it needs to send,

here, if in the routing table, the entry is there for the network which here is indeed private and there is shown the interface to which the packet
needs to be sent from, if the next hop ip is MISSING or NULL, i am repeating again, if the NEXT HOP ip is MISSING or NULL, then router checks whether
the interface is in the same network or not, and here, the interface is indeed in the same network, so router now checks whether there is any
entry for the MAC address for that ip address in its ARP table, if not, it gets from ARP resolution,

once get it simply transmitts through that interface meaning it will directly reach to the host and may be throug switches.

but if there is subnetting performed, then there will be next hop located in the routing table, and it needs to simply pass on to them,

now the routers which are actually part of the complete usable subnet, there will be an empty entry in the next hop, meaning that it has to send
directly to the host.

and yes, in this way the request and response are successful

here, the default side effect of this is one cannot from outside can connect to the internal network or hosts directly, as it is obviously not
possible, because it seems non-logical that how can outsider can generate such a packet that can go inside, the only possible way is to have
session established already i.e in the NAT table there should be entry and only traffic from that server will get through.

Also some ISP don't care about these ranges even,
in fact, my mobile has got ip address 25.23.14.187 from jio ISP, which means that it really doesn't matter at the router end, why?

Well, suppose this network is `/24`,
and the interface to which i am connected to i.e gateway is `25.23.14.1/24`,
now when the router performs NAT and is going to send the packet to the outside, it is going to add the source IP of the interface from which
it is going to forward the packet to the next hop, according to NAT policy, and once the response comes it is for the same router i.e
with the ip address of that interface, then router first may check if any service wants that packet which is listening on its os,
if not, then it will check the NAT table, and there will be the entry then, and according to that entry, it has to send the packet to the interface
with ip 25.23.14.1, and if subnetting done, then next hop else NULL, you got the point,

but here, don't you think that this is a provider edge router and it also might have entry for the same network for some real world organisation?

Yes, of course, but you need to understand that this is typically done on the routers which are not performing any BGP and so,
meaning they do have4 publicly routable ip addresses for some of their interfaces, but not necessarily they participate in routing,
i.e they are specifying the default route for to the other routers to send the packets and those routers when got the response, can definitely send
it back towards this router, where, NAT is performed and that 25. something network has opening from that interface, so that router doesn't have
to go to the its gatway or default route again!

So, the concept of gateway or default route is not just used in the private network but also in such scenarios,
but yes, this is technique used by ISPs today by allocating single public ip address to their such routers and configuring default route to
their main routers which actually participate in BGP topology to exchange routing tables and so on.
