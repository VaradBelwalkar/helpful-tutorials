You might have heard about creating virtual intefaces in the computer right,

like when you install docker, the docker creates a default docker0 interface in you machine,
and also configures the netfilter firewall to include some entries in the NAT table, 

but what is thiis docker0, what does it mean by virtual interface?


Our normal computers typically have two intefaces right, one is eth0 and other is wlan0,
lets not talk about wlan0 as of know only consider that your computer has eth0 interface


now the docker0 is similar to this, but virtual, meaning you can say that your computer has another interface named docker0 but it is not 
physical but virtual!

so it acts as a virtual interface to your computer, meaning that as your eth0 gets the ip address by manual or by DHCP, your virtual interface
can also get an ip address, 

I am going to only talk in the case of docker as of now,

you can consider that there is a virtual switch between the docker0 interface and the containers getting created, with their mac addresses
and the virtual switch is nothing but a data structure which can let you talk to the virtual networking of a particular container.

So, here, the workflow of iptables matter a lot, i.e where does NAT table reside in all of the tables concerned, when it is looked and what chains,
so on.

so the containers have default gateway as this virtual interface, which is the part of the docker's default network creation,
i.e 172.16.0.1 for this interface and other containers will get ips in this range, so your computer will virtually act as a node or router, in the 
virtual network where there is virtual switch and to which containers  are connected and defaulting traffic to this interface i.e docker0

so when this traffic comes to your computer, the computer first checks where the packet has to send to, in the routing table, and according 
to the dest ip, most probably it selects the default gatway of the computer which is the eth0 interface to send through it, as your computer is
not probably a part provider routers!

so when checking the routing table, the os doesn't care about the source ip, as here the source ip is from 172 range, and if we don't configure 
the NAT from the netfilter, the packet would go as it is from the eth0 interface and would the response would never come back for it,

so when the packet is getting outbound from the eth0 inteface towards default gatway, it goes through te POSTROUTING chain of the NAT table,
 and accorinding that, the computer performs NATTING, i.e changes the source ip to the ip of the eth0 interface, i.e ip of the outbound interface,
i.e from where the packet is going outside, while technically it is possible to assign a different ip address of other interface, and receive 
the response over there, instead on the same interface, but just use the interface for sending the packet to the gateway, but you need to have 
connectivity with the gateway on both the interfaces right, so that gateway can reroute it towards you,

so after changing the source ip to the interface ip i.e eth0's ip, the source port is then changed with the available port and then the required
entries are made a table which is maintained by the netfilter's module called conntracker, which tracks connection so you don't have to worry
about managing the sessions and port allocations and freeing them up upon session termination.

so when the response arrives, it goes from the PREROUTING chain of the NAT table, and guess what, we have used here the conntracker module,
and thus it is able to retrieve the seession, and with that it thus modifies the response packet and then finally sends to the routing engine,
where the os checks where to send the packet to, and as there would be entry for that network i.e for 172.16.0.0/14, 
and the dest ip of modified packet belongs to this network, the os then proceeds finding out the next hop for it and on which interface it is 
available, 
so it is available on interface docker0 with ip address 172.16.1.1, and the next hop is NULL, meaning that the containers or hosts are directly 
accessible so, here virtual ARP is performed and mac address of the interface of the container having that ip for that interface is taken and 
frame is generated and forwarded to the docker0 interface, and thus docker0 sends it virtually to virtual switch and that towards the container.
and thus the request response is happened.







Something like this we have for VMWare and for others as well.






