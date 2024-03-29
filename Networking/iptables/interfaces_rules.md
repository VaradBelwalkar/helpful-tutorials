Since iptables matches packets to every rule in a chain, things can get really slow when there are a lot of rules.
In such cases, it’s useful to exempt certain kinds of traffic.

By default if you don't specify any interface for any rule that you have written in any of the chain of any of the table,
Understand that it is also considering traffic from loopback interface!

This means that suppose i am connecting to http://127.0.0.1 through this interface and, 
i am running a express-js server here, the packet when just sent to this interface i.e loopback interface,
before going there, it will go through the chain of OUTPUT from the filter table,
and there will be checking done, after that when packet comes from the loopback interface, the packet will again go from
the INPUT chain of the same filter table,
here we really don't need to do this as obviously we can definitely trust the connections from our own machine to itself!

So it if highly adviced to add interface names to the rules whenever creating the rules,

but wait,

when i said apply interface names to the rules when creating them is valid,
but i want the traffic coming to / going from loopback interface to not get checked with all those hefty rules right,
as even if i add rules with interfaces, still it has to check the rules to see whether it is intended for that interface or not,


The best way is add a rule at the top which directly accepts all traffic on the loopback interface as you know the netfilter goes 
rule by rule from the chain to evaluate criterias,

which certainly accepts the traffic on loopback interface in the first place and doesn't need to go or check further for other rules 
as ACCEPT is the terminating rule right?
yes!



For example, on a typical Nginx/PHP-FPM stack, Nginx communicates with PHP over localhost, which uses the loopback interface.
Similarly, PHP may connect to a database server like Redis using the loopback interface.
It’s useless to filter these kinds of traffic, so you can allow it. 
The loopback interface is typically named lo and you can add a rule like this at the top of the INPUT chain:


```
iptables -A INPUT -i lo -j ACCEPT
```

The -i flag specifies the input interface. Here, we’ve assumed that the INPUT chain is empty and you’re adding the first rule. 
If that isn’t the case, you need to use the -I switch to add it at the top.



For the OUTPUT chain, you’ll need to use the -o flag, which stands for “output interface”. 
As an example, say you want to block the IP range 121.18.238.0/29, only when you’re on WiFi.
If the WiFi interface is named wlan0, you can add a rule like the one below:


```
iptables -A OUTPUT -o wlan0 -d 121.18.238.0/29 -j DROP
```












