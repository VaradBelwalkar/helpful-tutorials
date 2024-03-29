
Show ip addresses allocated to interfaces (physical and virtual) on your machine:

```
ip a
or ip address              //even add, just the initial chars are enough
```

show available interfaces with their info

```
ip link
```


show routing table info
```
ip route
```


show neighbor devices (same as showing the arp table)

```
ip neighbor

same as 

arp
```




Enable or Disable interface

```
ip link set dev eth0 down/up
```


give ip address to an interface manually

```
ip addr add 192.168.1.1/24 dev eth0
```


Delete the assigned ip 

```
sudo ip addr del <ip_address>/<subnet_mask> dev <interface_name>
```



Set default route

```
sudo ip route add default via <gateway_ip_address>
```


Delete default route

```
sudo ip route del default
```






Set the interface in the promisc mode or not

```
ip link set wlan0 promisc on/off
```



Set the Maximum Transmission Unit (MTU) of eth0 to 1500

```
ip link set dev eth0 mtu 1500
```



Add a route to the 10.0.0.0/24 network via 192.168.1.1 as next hop

```
ip route add 10.0.0.0/24 via 192.168.1.1
```



Delet the routing information for a particular network

```
ip route del 10.0.0.0/24
```




Create a GRE (Generic Routing Encapsulation) tunnel
Create a GRE tunnel from local endpoint to remote endpoint

```
ip tunnel add gre1 mode gre remote <remote_ip_address> local <local_ip_address>
```



Set a new MAC address for eth0

```
ip link set dev eth0 address 00:11:22:33:44:55
```



 Add a VLAN interface with ID 10 on eth0

```
ip link add link eth0 name eth0.10 type vlan id 10
```


Delete the VLAN interface eth0.10

```
ip link delete eth0.10
```











