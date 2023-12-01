S3 buckets are somewhat like google drive storages.

Here, S3 is an object storage, meaning simply you store files and folders under a bucket, and that is all, hence it is also called as flat storage, as it doesn't involve any file system.

Here is an overview of S3 storage given by network kings:


![image](https://github.com/VaradBelwalkar/helpful-tutorials/assets/86964576/bdecdc6c-c89f-4ae9-852f-5f38cd465271)



So when you are going to create an S3 bucket, 

the S3 bucket name you create need to be globally unique, yes you heard it right, else you cannot create it. Also it needs to be in lowercase.

Next, you choose the region in which to create the bucket, an defaultely, the bucket as shown in above diagram, get backed up as per AWS rules, into 3 or more availability zones.
You don't manage this replication, as amazon does this internally.

Next, By default `Block all Public Access` is selected, meaning that no one can access the objects stored inside this bucket unless you configure manually.

Here, there are two things as per the S3 bucket object, the bucket URI and URL, URI simply identifies it, while teh URL actually locates it so that you can view or download it.

But, as mentioned above, if the bucket ACL is to block all public access, no one can view it using hte URL right, then how does it look like when we try to view it?

First this is a typical object overview:

![image](https://github.com/VaradBelwalkar/helpful-tutorials/assets/86964576/37dfc887-3698-4c8c-aca5-14c1dd6c795c)

And this is shown when we try to access this particular object, i.e access denied.

![image](https://github.com/VaradBelwalkar/helpful-tutorials/assets/86964576/94b51d41-771f-4710-a303-75b04dbccf67)


Again before deleting the bucket, you need to empty it first, and then delete it, delete the versions as well if you have enabled versioning














