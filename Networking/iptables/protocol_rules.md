So far, we’ve seen examples of blocking IPs. However, you can do a lot more, by using modules and protocol based matching.

We’ll begin with a simple example. Say, you want to block all incoming TCP traffic. This isn’t too useful, 
but it’s an useful starting point. You simply need to specify the protocol with -p like so:

```
iptables -A INPUT -p tcp -j DROP
```


You can also specify other protocols such as udp or icmp. To work with ICMP traffic on ip6tables, you’ll need to use ipv6-icmp as the protocol.


Let us consider a more useful example this time. Say, you need to block SSH access for an IP range.
You have to first match all TCP traffic, like we did in the example above. Then, to check the destination port,
you should first load the tcp module with -m. Next, you can check if the traffic is intended to the SSH destination port by using `--dport`. 
Thus, the entire command would be:


```
iptables -A INPUT -p tcp -m tcp --dport 22 -s 59.45.175.0/24 -j DROP
```



Now, perhaps you want to block SSH and VNC access for the IP range. While you can’t specify multiple ports with the tcp module, 
you can do so with the multiport module. Then, you can specify the port numbers with --dports. The final command would be:


```
iptables -A INPUT -p tcp -m multiport --dports 22,5901 -s 59.45.175.0/24 -j DROP
```


Let us consider another example. Say, you want to block ICMP address mask requests (type 17). First, you should match ICMP traffic,
and then you should match the traffic type by using icmp-type in the icmp module:

```
iptables -A INPUT -p icmp -m icmp --icmp-type 17 -j DROP
```










