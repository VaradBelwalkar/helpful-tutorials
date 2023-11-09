Viewing interface information:
```
ip link show
```

Enabling or disabling an interface:
```
ip link set <interface> up
ip link set <interface> down
```

Assigning an IP address to an interface:
```
ip address add <ip_address>/<net_mask> dev <interface>
```

Removing an IP address from an interface:
```
ip address del <ip_address>/<net_mask> dev <interface>
```

Setting the MAC address of an interface:
```
ip link set dev <interface> address <mac_address>
```

Displaying routing table information:
```
ip route show
```

Adding a static route:
```
ip route add <network>/<subnet_mask> via <gateway> dev <interface>
```

Deleting a static route:
```
ip route del <network>/<subnet_mask> via <gateway> dev <interface>
```

Configuring VLANs:
```
ip link add link <parent_interface> name <vlan_interface> type vlan id <vlan_id>
```

Delete a VLAN:
```          
ip link del link <parent_interface> name <vlan_interface> type vlan id <vlan_id>
```