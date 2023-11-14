newgrp is a hack to let you reflect your just added groups without requiring to logout and log in again!

Simply run,
```
newgrp <new_grp_name>
```
after you add the user to that particular group.

Then that becomes your primary group, then switch to your primary group,

```
newgrp $(whoami)
```
