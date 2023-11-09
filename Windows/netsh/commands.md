## netsh is primarily used for configuring network and network interfaces

Show available interface

```
netsh interface show interface
```

Disable Network interfaces

```
netsh interface set interface "Ethernet" admin=disable
```

Enable Network interfaces

```
netsh interface set interface "Ethernet" admin=enable
```


Manually assign ip address to interface

```
netsh interface ipv4 set address "Ethernet" static 192.168.1.100 255.255.255.0
```


Default Gatway configuration

```
netsh interface ipv4 set address "InterfaceName" static IPAddress SubnetMask DefaultGateway
```


To set DNS servers for the interface, use the following command. Replace "DNSserver1" and "DNSserver2" with the actual IP addresses of the DNS servers:

```
netsh interface ipv4 set dns "InterfaceName" static DNSserver1 primary
netsh interface ipv4 add dns "InterfaceName" DNSserver2 index=2
```

To show available WIFI Access Points

```
netsh wlan show networks
```










