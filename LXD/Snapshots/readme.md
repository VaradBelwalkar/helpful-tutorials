LXD has very poor management for snapshots, yes you heard it right!

Whenever you create a snapshot, it is exactly the size of the instance, if instance size is 10GB, the snapshot will be 10GB,

I got to know that when i created two snapshots, in the hope that its workflow will be the same as openstack's snapshot storage, i.e overlay based.
But this turned out to be wrong in my scenario, maybe using a different storage driver might solve this, but i don't think so :/



Here, if you already checked out my explaination regarding snapshot workflow in openstack, you might understand this better, if not checkout that first!

There, when you create snapshot, it becomes an individual image which is then not dependent on the instance from which it is created.

So you can instantiate it as if it is just an image.


But here in LXD, when you create a snapshot, it simply copies the entire VHD image, in .img format and copies it to the snapshot section in the
storage pool, where if you create another snapshot, same thing happens. 
It drastically increases disk usage, which is often terrible.
Openstack's Overlay workflow is 1000x times better than this, as creating snapshots are not meant permanent storage, but to test and experiment with
features and configurations which might break system, so having an entire copy of the thing is definitely not the solution, but lXD ignores it :|


Here, when you delete the instance, snapshots are deleted as well!  















