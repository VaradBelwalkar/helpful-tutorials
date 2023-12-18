**Git** by default uses `~/.ssh/id_rsa` to authenticate against remote repository,
but doesn't give specific command line option to use **another key**.

If you have multiple remote repositories setup, this can be frustrating, to work around this,
you just need to export an `env variable` like this,
```shell
export GIT_SSH_COMMAND="ssh -i /path/to/your/ssh_key"
```
and after this you can happily authenticate against the repository you are intending to, and work with it.

But for working with another remote repo, you might need to run above command with other appropriate **private key**.
