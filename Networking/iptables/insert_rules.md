It turns out that you can also insert rules at a given position! This is useful in a number of cases.
We’ll use the previous example in the Listing rules section. While you’re seeing attacks from 59.45.175.0/24, 
assume that you need to whitelist 59.45.175.10.

Since iptables evaluates rules in the chains one-by-one, you simply need to add a rule to “accept” traffic from this IP above the rule 
blocking 59.45.175.0/24. So, if you run the command:

```
iptables -I INPUT 1 -s 59.45.175.10 -j ACCEPT
```


You can also replace rules with the -R switch. As an example, perhaps you whitelisted the wrong IP, 
and typed in 59.45.175.12 instead of 59.45.175.10. Since the new rule is on the first line, you can replace it with the correct rule like so:

```
iptables -R INPUT 1 -s 59.45.175.10 -j ACCEPT
```





