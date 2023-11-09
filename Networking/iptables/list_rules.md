
List rules:

```
iptables -t filter -L --line-numbers

iptables -t nat -L --line-numbers

iptables -t nat -L -n --line-numbers

-n to avoid reverse DNS lookup done by iptables trying to be helpful by providing domain names for ip addresses in the tables

```



  



  
