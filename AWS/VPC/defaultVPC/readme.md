You might be wondering why the defaultVPC is called a public subnet if it is private network right? 
First understand from start!


When you are in a region, you got a defaultVPC, and it is only limited to you, other people get defaultVPC same as yours, but these private networks i.e 172.31.0.0/16, are only accessible to 
you (of course)

So you can say that each AWS account gets this private network i.e 172.31.0.0/16 in each region, and that too subnetting performed, meaning each availability zone is a subnet, that might vary
region to region but thing remains same.


Ok, so important thing is if you say this is private network or subnet if AZ, why AWS calls is public subnet?


The answer lies in how you access the internet, in most common scenario, you access internet through NAT, done by your ISP, you can in detail explaination in this repo. (Find out!)

The other way is you get public ip, so that their is not NAT performed anyway and the internet can reach you without any problem.



So, when you create an instance in this defaultVPC, i.e 172.31.0.0/16, you get two ip addresses, one is of course from this network, and one public ip address,
suppose you got 172.31.0.1/16 and 3.4.5.6/something (this depends on AWS)
So, you see you got public ip for your instance by default.

So Here, the thing is that, AWS they own maintain a public subnet infrastructure to provide ip addresses to the instances and possibly containers created in the defaultVPC.
Remember, only for defaultVPC, so i think there might exist some configuration which tells AWS to assign public ip to the instance, if it is in defaultVPC of client.


So, your instance is publically accessible! WITHOUT ANY NAT!


So even if you got private ip, you also got public ip, as per defaultVPC's behaviour


So, isn't it a public subnet, so the more you create instances, those all will get public ips by default, and effectively that will contribute to a public subnet for your defaultVPC!


So, whenever you create another VPC, you defaultly don't get public ips by default, so typically it is private subnet, this means internet can't reach you by this time, you can only 
reach the internet by performing NAT, and AWS does this.



For defaultVPC, aws configures you VPC for default gateway for your instances, which has rule to forward all the traffic 0.0.0.0/0 to its gateway, if private network doesn't match.

However you can change this, you can configure this gateway, configure the default forwarding behaviour and so on.
AWS also configures the DHCP in your defaultVPC, meaning that you automatically get private ip addresses, remember only private ones, the public ones are in the hand of AWS.
























































