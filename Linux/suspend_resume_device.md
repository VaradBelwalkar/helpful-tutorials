common solution to this is to run

```    
rm /etc/initramfs-tools/conf.d/resume 
update-initramfs -u.
```



If you have a dedicated swap partition, use the blkid command to find its UUID.

Then copy this (select, press Ctrl+Shift+C in the terminal window), edit the 

```
/etc/initramfs-tools/conf.d/resume
```

make sure it has the correct UUID (select the old one, delete it, press Ctrl+Shift+V to paste).

Save it.
Rerun

```
update-initramfs -u
```
Reboot.


To skip the attempt to resume from a configured suspend/resume disk/partition (usually a swap partition):

Interrupt GRUB by pressing any key, then press E to edit the currently-selected boot entry, 
find the line starting with the word linux and add noresume as a separate word to the end of that line.

To make it persistent, add that to the 

```
/etc/default/grub
```

and update the grub to get those changes,

```
update-grub
```










