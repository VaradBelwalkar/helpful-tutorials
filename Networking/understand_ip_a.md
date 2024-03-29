
When you run `ip a` in your terminal, you get something like this,

```shell
wlo1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default qlen 1000
    link/ether 3c:55:76:1b:e3:03 brd ff:ff:ff:ff:ff:ff
    altname wlp3s0
    inet 192.168.219.8/24 brd 192.168.219.255 scope global dynamic noprefixroute wlo1
       valid_lft 2466sec preferred_lft 2466sec
    inet6 2409:4042:2c85:9bce:4425:fcde:9b5a:cbfd/64 scope global temporary dynamic 
       valid_lft 1866sec preferred_lft 1866sec
    inet6 2409:4042:2c85:9bce:c6ef:6241:395a:a53b/64 scope global dynamic mngtmpaddr noprefixroute 
       valid_lft 1866sec preferred_lft 1866sec
    inet6 fe80::fe03:1ae9:17a9:163e/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
```       
       
       
This output is showing the network interface named "wlo1" and its current configuration. Here's what each thing represents:

|conf| Description|
|----|----|
|wlo1:| This is the name of the network interface.|
|<BROADCAST,MULTICAST,UP,LOWER_UP>:| These are the flags indicating the current state of the interface. In this case, it's up and running, and able to send and receive broadcast messages.|
|mtu 1500:| This is the maximum transmission unit (MTU) for this interface, which is the largest packet size it can handle.|
|qdisc noqueue:| This indicates that there is no queuing discipline set up for this interface.|
|state UP:| This indicates that the interface is currently active and able to send and receive packets.|
|group default: |This indicates the group that this interface belongs to.|
|qlen 1000: |This is the maximum length of the transmit queue for this interface.|
|link/ether 3c:55:76:1b:e3:03 brd ff:ff:ff:ff:ff:ff: |This is the MAC address of the interface and the broadcast MAC address.|
|altname wlp3s0:| This is an alternate name for the interface.|
|inet 192.168.219.8/24:| This is the IPv4 address assigned to the interface. In this case, it's a dynamic address assigned through DHCP, and the subnet mask is /24.|
|brd 192.168.219.255: |This is the broadcast address for the network that the interface is on.|
|scope global: |This indicates that this IP address is a global IP address that can be reached from anywhere on the network.|
|dynamic noprefixroute: |This indicates that this is a dynamic IP address assigned through DHCP, and that there is no specific route set up for it.|
|valid_lft 2466sec preferred_lft 2466sec: |These are the valid and preferred lifetimes for the IPv4 address. In this case, the address will expire in 2466 seconds, and it's the preferred address until it expires.|
|inet6:|These are the IPv6 addresses assigned to the interface.|
|fe80::fe03:1ae9:17a9:163e/64: |This is the link-local IPv6 address for the interface.|
|scope link noprefixroute:| This indicates that this is a link-local address, and that there is no specific route set up for it.|
