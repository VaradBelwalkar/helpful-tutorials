| Option | Description |
| ------ | ----------- |
| Linux Command | Windows Alternative      |                    
| ls            | dir/ls   |                                    
| ls -a         | N/A      |                                    
| ip address    | ipconfig  also ipconfig /all |                
| lsblk         | diskpart     |                                
| blkid         | wmic logicaldisk      |                       
| netstat       | netstat (deprecated) or Get-NetTCPConnection |
| netstat -n    | netstat -n   |                                
| nano          | Notepad    |                                  
| nmcli         | N/A      |                                    
| cat           | type/cat  |                                   
| head/tail     | N/A      |                                    
| mount         | mount     |                                   
| sudo <command>| runas /user:Administrator <command>     |     
| arp -a        | arp -a       |                                
| dns           | ipconfig /displaydns  |                       
| iptables      | netsh       |                                 
| apt           | winget   |                                    
| chown         | takeown   |                                  
| tar           | tar   |                                       
| htop          | tasklist   |                                  
| which <cmd>   | Get-Command <cmd>   |                         
|  cat file | grep "example"        |  findstr "example" file.txt|
|  cat /etc/os-release              |  systeminfo    |
|  netstat -a -b | grep 9000          |  netstat -a -b | findstr "9000"  (Deprecated) |
|                                     |  Get-NetTCPConnection | Where-Object { $_.LocalPort -eq 9000 }|


get process with process id:
```
Get-Process -Id <PID>
```


Start powershell as administrator 
```
  Start-Process powershell -Verb RunAs
```





