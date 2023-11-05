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

![EKzLE](https://github.com/VaradBelwalkar/helpful-tutorials/assets/86964576/27d5b8e8-f410-45a8-83b5-1c0f74b08242)



Here, after seeing this diagram, it might be clear for you that why host is unable to connect to network and internet.

The problem is, 

When you add the interface to the bridge, it becomes interface of the virtual switch, and hence virtual switch is the one who controls it now.

Meaning that, the host needs to move its entire TCP/IP stack from the eth0 interface to some other one which actually has connectivity.

To do so, as shown above, we create another port on virtual switch named host port, 

and most importantly, create a virtual interface called my-bridge, which is then connected to this host port,

and then when we run the 

```dhcpcd my-bridge``` 

command, we are actually assigning ip address to this virtual interface and thus getting connection from there, as shown in above diagram.

So, this means that, when you run the command,

```
ip link add my-bridge type bridge
```

You are actually creating this my-bridge interface, and connecting this interface to the this virual switch!
And this is what docker exactly does!

When docker creates the docker0 interface, it simply does this, so that this interface is now connected to the virtual switch, and then the 

containers are getting connected, so complete private network, where host is able to connect to the containers from this docker0 interface, and so the containers, and via host routing, able to reach to the internet.


The thing comes when we want to have what i previously mentioned, networking on host network, 

So as mentioned in the diagram above, only thing comes in mind is somehow make the eth0 port as port of switch, so that all the traffic can be

intercepted on this port, and thus allowing to extend the actual host network, making it look like the containers are on the host network itself.

Follow this link to know more about the context: 

https://superuser.com/q/1815441/1723212

































