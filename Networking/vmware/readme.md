Following is the typical internal architecture of vmware virtual machines:

this is according to normal considerations and assuming that only two virtual interfaces are active as per standard vmware installation i.e vmnet1 and vmnet8,

where vmnet1 is host-only and vmnet8 is performing NAT, so as you are only able to have atmost 3 adapters per virtual machine where one being bridged to the physical host interface


![autodraw 29_07_2023 (1)](https://github.com/VaradBelwalkar/helpful-tutorials/assets/86964576/bf84b585-87a1-4edb-8279-6ebd069cb520)
