Here, when we install docker on our machine, docker creates a virtual interface, which is then assigned with an ip address from a predefined pirvate n/w range,

and there exists a virtual switch between the virtual interface and the interfaces of containers, so that all those interfaces are in the same network.

However this virtual switch is not visible.

Scenario is,

![image](https://github.com/VaradBelwalkar/helpful-tutorials/assets/86964576/96cd6891-03db-4baf-8a87-5b331052caec)





But When you create a bridge using the command,
```
ip link add my-bridge type bridge
```

You are actually creating a virtual switch, and not virtual interface, 
and when you run this command,

```
ip link set eth0 master my-bridge
```

You are actually assigning the eth0 interface as the interface of the virtual switch itself.

Before this, your normal eth0 interface would drop the frames which are not intended for it (normally),

but when you master it over the switch, as per the policy of switch, its work is simple, forward to it right interface according to the dest. MAC,

and when a frame comes from the eth0 interface, its work is simple, forward it to appropriate interface, in this case, the interfaces of the switch are of-course
virtual.

Here, main thing is that, this switch(bridge), is visible and thus, its intefaces as well, meaning that as shown below, the interfaces of this switch, you can

see in the output of the ``` ip link ``` command.

So meaning that each interface of this switch will be listed with its output, and meaning that each interface is connected to one docker container.

So if you run 100 containers, hundred virtual interfaces will be created which will be part of this switch.


![image](https://github.com/VaradBelwalkar/helpful-tutorials/assets/86964576/3e6f86d5-5943-48cf-a24a-1bcf1ed0afac)
