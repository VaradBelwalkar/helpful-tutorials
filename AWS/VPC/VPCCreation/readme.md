To Understand the Concept of VPC in detail, visit my in detail visualisation [here]( https://www.canva.com/design/DAF0obvFcQU/jyONwrbwNRvLG_I5vIfKgQ/edit?utm_content=DAF0obvFcQU&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

Please understand that, above visualisation holds perfect for every aspect  of designing and creating solutions, but not necessarily the same
scenario exists in the real world as per AWS implementation, but the underlying concept remains same, so don'y worry about implementation details,
the visualisation holds true, which is better for understanding why we are creating so much things to get things done!




### First we will talk about the custom VPC here, so then explaining the default VPC becomes easier.



So, When you create a custom VPC, you create that VPC in a region right, lets say N. Virginia, which is us-east-1
You only create a VPC, and not any subnets.
So lets say you created VPC 10.10.10.0/24
Unless you create the subnets, you cannot create instances here.

So you first create subnet/s, and preference to zones is your choice.

Here, when you create a VPC, defaultely a routing table i.e the main route table gets created for that VPC, and as you go creating
the subnets, that table gets associated to the container in that subnet(as per in diagram)

So, here you don't need to associate this route table to any subnet, as it is associated by default


But when you create custom route table, you associate it to a subnet, and its gets replaced with the original present there in the container


Here, according to the workflow, when you create custom VPC and a main route table, the main route table only contains private route entry.

So when you create the subnet, you have option to say `yes` to auto-assign public ip addresses,
So this actually creates a static NAT in the container, which in turn when assigned ip address to an instance, creates entry to map private ip
to a public ip.

But when you create the VPC, create the subnet, say `yes` to auto-assign public ip, this all is not enough as you are not connected 
to gateway yet (as explained in diagram)

So first you need to create Internet Gateway, and associate it with the VPC, so that all subnets are associated with the Internet Gateway
in their respective availability zones.

Here, as per in diagram only then the link gets created between your container and the actual Gateway in the zone.

Is this enough to get Internet Connectivity?

Because you got the public ip address to the instance right?

No, because the main route table still doesn't contain the entry that we want.

the entry is 
```
Destination                 Gateway
 0.0.0.0/0        <Select Gateway You Created>
```

This now makes sure that your traffic will reach the internet and vice versa.

] ---


When you say `no` to the auto-assign public ip in the create subnet section,
you can still assign a particular instance a public ip by first creating `elastic ip ` in the elastic ip section
and then associating that ip to the instance.  But they need to be in the same availability zone.

Once you associate public ip to the instance, the container associated with that subnet makes entry in the static NAT for the private ip,
to get associated with the chosen public ip, so that you can then be able to reach on internet and again, vice versa


---


You can also do PAT (Port address Translation), but the thing is you create PAT service by going into NAT gateways section, and creating 
a NAT gateway!

I know this might sound weird but it is as it is!

When you create a NAT gateway, you have option to assign the public IP on the fly or choose the available IP from elastic IPs you reserved.

Well when you create the NAT gateway, you again, need to associate it with a subnet, so when you associate with a subnet, it actually goes
into the container, and as said above, it maps all the private ips from the subnet, to one public ip mentioned as above, via port workflow and
sends to the internet, and after response comes, checks the table, and then sends accordingly to the particular instance
So here only one public ip is enough to be able to reach internet but **not** vice versa!



Now comes the info about Security groups.

There is always a default security group, which lets all traffic to outbound from instance, but no inbound, so you cannot access 
the instance even if you got public ip, so when you create instance, you have option to choose the security group or create one,
by default create security group is selected and services mentioned there which you allow inbound traffic for.

But if you select the default one, you can no longer connect to the instance, as explained above.

So you can go to the security groups, and create a security group which tells what can inbound and outbound, and then you can choose this
while creating the instance, which makes sense.

You can also update the security group while the instance is using it, and the changes will be immediate.


---


Now in the case of defaultVPC, the thing is, it is created by default in all AWS regions, with subnets precreated in all availability zones
for you.

You also get a default Internet Gateway precreated, and also that Internet Gateway is associated with the defaultVPC, so that all your
subnets can reach to the internet,

and by default, all the subnets auto-assign public ip to the instances, i.e defaultely perform static NAT from private to public and vice versa

And also the main route table contains entry 
```
Destination           Gateway
0.0.0.0/0       <precreated Gateway>

```
This makes sure that the instances are able to reach the internet and vice versa.












