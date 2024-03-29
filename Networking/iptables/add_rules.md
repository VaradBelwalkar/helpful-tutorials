
you’ve noticed the IP 59.45.175.62 continuously trying to attack your server, and you’d like to block it.
We need to simply block all incoming packets from this IP. So, we need to add this rule to the INPUT chain of the filter table.
You can do so with:


```
iptables -t filter -A INPUT -s 59.45.175.62 -j REJECT
```
  
The -t switch specifies the table in which our rule would go into — in our case, it’s the filter table. 
The -A switch tells iptables to “append” it to the list of existing rules in the INPUT chain. However,
if this is the first time you’re working with iptables, there won’t be any other rules, and this will be the first one.

As you might have guessed, the -s switch simply sets the source IP that should be blocked.
Finally, the -j switch tells iptables to “reject” traffic by using the REJECT target. 
If you want iptables to not respond at all, you can use the DROP target instead.

the filter table is used by default. So you can leave it out, which saves you some typing:

```
iptables -A INPUT -s 59.45.175.62 -j REJECT
```


You can also block IP ranges by using the CIDR notation. If you want to block all IPs ranging from 59.145.175.0 to 59.145.175.255,
  you can do so with:

```
iptables -t filter -A INPUT -s 59.45.175.0/24 -j REJECT
```

If you want to block output traffic to an IP, you should use the OUTPUT chain and the -d flag to specify the destination IP:

```
iptables -t filter -A OUTPUT -d 31.13.78.35 -j DROP
```



  



  
