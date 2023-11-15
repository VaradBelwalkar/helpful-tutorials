LXD has very poor management for snapshots, yes you heard it right!

Whenever you create a snapshot, it is exactly the size of the instance, if instance size is 10GB, the snapshot will be 10GB,

I got to know that when i created two snapshots, in the hope that its workflow will be the same as openstack's snapshot storage, i.e overlay based.
But this turned out to be wrong in my scenario, maybe using a different storage driver might solve this, but i don't think so :/

