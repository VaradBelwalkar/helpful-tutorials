This is my NAT table from the iptables command i.e in the netfilter.

##############################################################################################################
Chain PREROUTING (policy ACCEPT)
num  target     prot opt source               destination         
1    DOCKER     all  --  anywhere             anywhere             ADDRTYPE match dst-type LOCAL

Chain INPUT (policy ACCEPT)
num  target     prot opt source               destination         

Chain OUTPUT (policy ACCEPT)
num  target     prot opt source               destination         
1    DOCKER     all  --  anywhere            !127.0.0.0/8          ADDRTYPE match dst-type LOCAL

Chain POSTROUTING (policy ACCEPT)
num  target     prot opt source               destination         
1    MASQUERADE  all  --  172.17.0.0/16        anywhere            

Chain DOCKER (2 references)
num  target     prot opt source               destination         
1    RETURN     all  --  anywhere             anywhere
##############################################################################################################


Chain PREROUTING:
This chain is responsible for packets as they arrive on the network interface before any routing decisions are made. 
In this specific case, there is one rule:

Rule 1: It matches all packets with the destination address being the local machine (ADDRTYPE match dst-type LOCAL) 
and forwards them to the DOCKER chain. This rule is often used by Docker to handle incoming packets to its containers.

Chain INPUT:
The INPUT chain is responsible for packets destined for the local system (the Linux machine itself).
In your case, there are no specific rules, so all incoming packets will be allowed (policy ACCEPT). 
If there were specific rules, they would be listed here.

Chain OUTPUT:
The OUTPUT chain handles locally generated packets on the Linux system. There is one rule:

Rule 1: It matches all packets with the destination address not in the 127.0.0.0/8 range 
(meaning packets not destined for localhost) and forwards them to the DOCKER chain. Again, 
this is often used by Docker for its networking setup.

Chain POSTROUTING:
The POSTROUTING chain handles packets after routing decisions have been made 
and just before they are sent out on the network interface. There is one rule:

Rule 1: It performs source NAT (SNAT) using MASQUERADE for packets coming from the 172.17.0.0/16 subnet. 
MASQUERADE means that the source IP address of outgoing packets will be replaced with the IP address of the outgoing interface (dynamic NAT).
This is commonly used in Docker networking to allow containers to communicate with the external network using the host's IP address.

Chain DOCKER:
The DOCKER chain is used by Docker to apply its own network rules. It is being referenced by rules in both the PREROUTING and OUTPUT chains.

Rule 1: The RETURN target means that if a packet reaches this rule, it will continue processing in the original chain 
(either PREROUTING or OUTPUT) without further actions from this chain. In other words, this rule effectively allows packets
to continue through the chain without any modifications.
Please note that the order of the rules matters in the chains. When a packet arrives or leaves the system, 
it is processed sequentially through the rules in each applicable chain until it matches a rule that either 
accepts, rejects, or modifies the packet. The first matching rule determines the fate of the packet.
If no rule matches, the policy defined for the chain is applied (ACCEPT in this case).









