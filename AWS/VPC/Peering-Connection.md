###Peering Connection is free to use.

This is actually one of the best service AWS has included in its services.

This allows us to connect two VPCs from the,
    same account, same region,
    same account, different regions,
    different account, same region,
    different account, different region.

So basically you can connect any two VPCs irrespective of their in the world provided you have grants to do the same on both the VPCs.

Here, there is requester and accepter, the VPC who makes request is requester and the one who accepts, is accepter.

Here, of course both VPCs should have different Networks.

When creating Peering Connection, 

Here first you choose the requester VPC id, which can be selected using AWS default dropdown or you can paste it there.

Secondly, You get prompt that whether the accepter is in the same account or not,
if not, it will ask for account ID.

After that, it will ask for the region, whether it is in the same region or different, if different, it will ask that region.

After that it will ask for VPC id of the accepter, whether it is your VPC or some another account's VPC, you simply paste that id here.

And then it gets created.


After this if your requester and accepter are under same account, you simply need to go to the dashboard of the peering connection,
and the peering connection you created, simply go under actions, and accept it, yes it is that simple!
Because you are the only one who can accept it, because both VPCs are under your account.


But if your accepter is under another account, you need to login to that, go to peering Connection, and there you will see that Peering 
Connection listed in pending state, then its your choice to accept it or not.

And most important, this doesn't mean that it is done.

You still need to update the route tables in both the VPCs in order for traffic to flow.

Here, again while editing the route table for any subnet, you simply need to add the destination network,
and then the gateway here would be Peering Connection,

Yes, you get the drop down list there under gateway, where you can choose the Peering Connection, and after that 
all Peering Connection devices will get listed, and then you can choose one of them.

Same thing is done on the other end of the Connection, i.e on the second VPC.

And the connection goes on.










