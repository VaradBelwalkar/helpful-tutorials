First in case you messed up with the lxd by creating cluster,and now you are unable to access the lxd daemon,  
because your IP has changed,  
If you don't have any critical information stored in any of the lxd instances, you can simply remove all the files, under,    
```
/var/snap/lxd/common/lxd/database/
```
by running,  
```
sudo rm -rf /var/snap/lxd/common/lxd/database/*
```
And thereafter running `lxd init` again to configure new workflow.

---

## Commands

List remote repositories that make images available:  
```
lxc remote list
```
And to see which images are available on a particular remote repository:
```
lxc image list <remote_name>:
e.g
lxc image list images:
```

Copy the image from the remote repository to local  
The only way to pull images to local repo is to copy from remote end.
```
lxc image copy images:ubuntu/22.04/amd64 local: --alias ubuntu
```
Launch a container from image, pull image if not exists:  
```
lxc launch ubuntu container-name
```

Creating a New Container:
```
lxc init ubuntu my-container
```

Starting a Container:
```
lxc start my-container
```

Stopping a Container:
```
lxc stop my-container
```

Delete a container:  
```
lxc delete container-name
```

List storage pools(You can't run anything if there is no storage pool, as it doesn't create automatically like docker does)
```
lxc storage list
```


Create a storage pool to be used by containers/vms:  
Here, the preferred storage driver in my case is dir, others are btrfs etc.
```
lxc storage create storage-name dir source=/var/snap/lxd/common/lxc/storage-pools/storage-name
```

To launch or init a container in a particular storage pool:  
```
lxc launch ubuntu container-name -s mystoragepool

lxc init ubuntu container-name -s mystoragepool
```

To make a storage pool default:   
```

```
Make sure that you have freshly created pool, otherwise this won't work, or the pool which is empty.
Before you make any storage pool default for a profile(default is default), the profile looks like: 
```
config: {}
description: Default LXD profile
devices:
  root:
    path: /
    pool: local
    type: disk
name: default
used_by: []


```
See there is a default entry for the devices section, where root means the default device, which will be used for storage if not specified.    
So to configure the default storage for this profile, i.e to change the pool, you can either do it manually,
```
lxc profile edit default
```
and then change the pool name to the name that you want as default pool, 
while the path mentioned there is nothing but, relative path against the pool configured,
so if storage pool you are using here is `/var/snap/lxd/common/lxd/storage-pools/local`
then the path is considered as root i.e /, meaning that if you configure path to be /containers, 
then the containers that you create using this profile, in term, using this default storage pool,
the actual container directory will be created at `/var/snap/lxd/common/lxd/storage-pools/local/containers/<container-name>` location.

The recommended way to change this config is,

```
lxc profile device set default root pool=<pool_name>
```
Here, we are editing profile, so the `lxc profile` command,  
next, we want to edit the devices section, so the  `device set`,  
next, the profile `default` one,  
pool 
next, `root` means the relative path against the choosen pool(explained above)  
and poo=<pool_name> means we are changing/adding that property.


Accessing a Container's Console:
```
lxc console my-container
```
This is similar to getting a shell in the container with the `exec` command, but requires password for the 
user already set up.


Executing a Command Inside a Container:
```
lxc exec my-container ls -l
```


Adding a repository to the remote list: 
```
lxc remote add --protocol simplestreams ubuntu https://cloud-images.ubuntu.com/releases/
```

configure a vm/container: 
```
lxc config edit vm/container
```

Creating Snapshots:
```
lxc snapshot my-container snapshot-1
```

Restoring from a Snapshot:
```
lxc restore my-container snapshot-1
```
Copying and Moving Containers:
```
lxc copy my-container my-container-copy
lxc move my-container my-container-renamed
```


Listing Containers:
```
lxc list
```

Displaying Container Information:
```
lxc info my-container
```


Configuring Container Properties:
```
lxc config set my-container limits.cpu 2
```


Creating a Bridge Network:
```
lxc network create my-network
```

Adding a Container to a Network:
```
lxc network attach my-network my-container
```

Listing LXD Networks:
```
lxc network list
```

Deleting a Network:
```
lxc network delete my-network
```


Cloning a Container:
```
lxc copy my-container my-container-clone
```

Exporting a Container:
```
lxc publish my-container --alias my-container-image
```

Importing an Exported Container:
```
lxc image import my-container-image.tar.gz --alias my-container-image
```


Uploading Files to a Container:
```
lxc file push /path/to/local/file my-container/root/path/in/container/
```

Downloading Files from a Container:
```
lxc file pull my-container/root/path/in/container/file /path/to/local/destination/
```


Listing Snapshots:
```
lxc info my-container
```

Deleting Snapshots:
```
lxc delete my-container/snapshot-name
```



Renaming a Container:
```
lxc rename my-container new-container-name
```


Connecting to a Remote LXD Host:
```
lxc remote add remote-name remote-host
```

Managing Containers on a Remote Host:
```
lxc remote list
lxc remote show remote-name
lxc remote remove remote-name
```

Monitoring Container Resource Usage:
```
lxc monitor --type=container my-container
```

Creating a Container from an Image:
```
lxc init my-custom-image my-new-container
```

Exporting a Custom Image:
```
lxc image export my-custom-image my-custom-image.tar.gz
```

Moving Containers to Different Storage Pools:
```
lxc move my-container my-new-container --target new-storage-pool
```

Container Configuration Overrides:
```
lxc config set my-container limits.memory 2GB
lxc config unset my-container limits.memory
```

Creating a Custom Bridge Network:
```
lxc network create my-custom-bridge ipv4.address=192.168.1.1/24 ipv4.nat=true
```

Assign a specific IP address to a container.
```
lxc config device add my-container eth0 nic nictype=bridged parent=my-custom-bridge name=eth0 ipv4.address=192.168.1.2
```


Running a Container in Privileged Mode:

```
lxc config set my-container security.privileged true
lxc start my-container
```

Creating a Container Backup:
```
lxc export my-container /path/to/backup-directory
```

Restoring a Container from Backup:
```
lxc image import /path/to/backup-file --alias my-restored-container
lxc init my-restored-container my-restored-container-name
```

Listing Available Images on a Remote Server:
```
lxc remote list my-remote-server
lxc image list my-remote-server:
```

