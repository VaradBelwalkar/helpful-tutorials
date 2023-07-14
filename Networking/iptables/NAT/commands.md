*****List everything from the NAT table 

######################################
sudo iptables --table nat --list

<or -L instead of --list>
######################################


*****Flush the entire NAT table 

######################################
sudo iptables --table nat --flush
######################################


*****To route the traffic comming on port 80 to 8080 on the host:

Here the actual port in the packet on that transport layer gets changed to the intended port,
that means, here, port 80 gets changed to the port 8080 here


####################################################
sudo iptables --table nat \
              --append PREROUTING \
              --protocol tcp \
              --dport 80 \
              --jump REDIRECT \
              --to 8080
#####################################################

*****Change Dest IP from incoming packet i.e add rule into the PREROUTING chain of the NAT table
here the reason behind adding it into PREROUTING is, PREROUTING means before routing the packet, do some changes,
which here in case mostly has to do with the dest port or dest ip right, because we might want to change the destination where the packet 
goes,
while in case of POSTROUTING, while sending the packet somewhere, we obviously sending it to some destination so dest ip and dest port are already
determined and are correct, something we want to change might be the source ip and source port right, so we can add the rule over here.

#######################################################################
sudo iptables --table nat \
              --append PREROUTING \
              --protocol tcp \
              --destination 192.168.254.47 \
              --dport 80 --jump DNAT \
              --to-destination 192.168.254.10:8080
########################################################################


*****Change Source IP of the outgoing packet i.e add rule to the POSTROUTING chain of the NAT table

########################################################################
sudo iptables --table nat \
              --append POSTROUTING \
              --protocol tcp \
              --destination 192.168.254.10
              --dport 8080
              --jump SNAT \
              --to-source 192.168.254.47              
########################################################################








