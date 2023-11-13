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


Creating a New Container:
```
lxc init ubuntu:22.04 my-container
```

Starting a Container:
```
lxc start my-container
```

Stopping a Container:
```
lxc stop my-container
```

Accessing a Container's Console:
```
lxc console my-container
```
Executing a Command Inside a Container:
```
lxc exec my-container -- ls -l
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

