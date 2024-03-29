Now, say you’ve blocked the IP range 221.194.47.0/24 by mistake. Removing it is easy: simply replace -A with -D, which deletes a rule:

```
iptables -D INPUT -s 221.194.47.0/24 -j REJECT
```


You can also delete rules through their line numbers. If you want to delete the second rule from the INPUT chain, the command would be:

```
iptables -D INPUT 2
```


When you delete a rule that isn’t the last rule, the line numbers change, so you might end up deleting the wrong rules! So, 
if you’re deleting a bunch of rules, you should first delete the ones with the highest line numbers. 
If you were deleting the 9th and 12th rules from the INPUT chain, you would run:

```
iptables -D INPUT 12
iptables -D INPUT 9
```


Sometimes, you may need to remove all rules in a particular chain. Deleting them one by one isn’t practical, 
so there’s the -F switch which “flushes” a chain. For example, if you want to flush the filter table’s INPUT chain, you would run:

```
iptables -F INPUT
```





