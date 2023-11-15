here is how i think snapshot management in openstack works:
When an snapshot of instance is created, at that moment in the directory where the snapshots are going to get saved, there two empty qcow2 images are going to get created, one of them actually is nothing but hardlink to the qcow2 image of the instance itself, and other the qcow2 stores difference in such a way that it would restore the original snapshot instance state.  
so when instance qcow2 changes, it reflects in the hardlinked qcow2 of the snapshot, and thus the another qcow2 staying there maintaines the changes in such way that the state at which the snapshot created can be derived,   
here, even when we delete the instance, it goes from the instance list, but data is there, as there is hardlink there which is from the one of the qcow2 of snapshot, so if i need to create an instance from the snapshot, it simply makes an overlay between the two qcow2 images of the snapshot, giving me the ultimate qcow2 image having the state which was at the snapshot creation, and then this qcow2 is copied at the working directory of the instances, and thus, instance is created.  





