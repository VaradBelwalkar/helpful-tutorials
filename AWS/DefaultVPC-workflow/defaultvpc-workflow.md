# Understanding AWS Default VPC and Public Subnets

You might be wondering why the default VPC is called a public subnet if it is a private network, right? Let's start from the beginning!

When you are in an AWS region, you are given a default VPC. This default VPC is unique to your AWS account, and other accounts get their own default VPCs. The private networks, represented by IP range 172.31.0.0/16, are only accessible to you.

Each AWS account gets this private network (172.31.0.0/16) in each region, with subnetting performed. Each availability zone (AZ) becomes a subnet, and while the specifics might vary by region, the concept remains the same.

## Public Subnet Naming

Now, the question arises: If these are private networks or subnets within an AZ, why does AWS refer to them as public subnets?

The answer lies in how you access the internet. In the common scenario, internet access is achieved through Network Address Translation (NAT), typically done by your Internet Service Provider (ISP). You can find a detailed explanation in this repository.

Alternatively, you can obtain a public IP, eliminating the need for NAT, allowing the internet to reach your instance without any problem.

## Public IP in Default VPC

When you create an instance in the default VPC (i.e., 172.31.0.0/16), you get two IP addresses. One is, of course, from the private network, and the other is a public IP address. For example, you might get 172.31.0.1/16 and 3.4.5.6/something (the public IP depends on AWS).

Here, AWS owns and maintains a public subnet infrastructure to provide IP addresses to instances and possibly containers created in the default VPC. Remember, this behavior is specific to the default VPC.

## Default VPC Instances Accessibility

So, even if your instance has a private IP, it also comes with a public IP by default. This means your instance is publicly accessible without any NAT configuration.

As you create more instances, all of them will get public IPs by default, effectively contributing to a public subnet for your default VPC.

## Contrast with Custom VPCs

When you create another VPC, you don't get public IPs by default. Typically, it is considered a private subnet, meaning the internet can't reach your instances without performing NAT. AWS handles this NAT process.

In the default VPC, AWS configures your VPC with a default gateway for your instances. This gateway has rules to forward all traffic (0.0.0.0/0) to its gateway if the private network doesn't match.

You can configure this gateway and change the default forwarding behavior. AWS also configures DHCP in your default VPC, automatically assigning private IP addresses — remember, only private ones, as public IPs are managed by AWS.
