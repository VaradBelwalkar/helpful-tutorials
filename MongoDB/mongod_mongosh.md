Here once you download the mongodb package, it comes with two binaries, one is 
            mongod (mongo daemon)
            and another is 
            mongosh (short for mongo shell)

Here the normal way to work the mongod service: ( Do sudo systemctl daemon-reload if following doesn't work as this will reload the init system to take the recent configurations in effect)
```
sudo systemctl start mongod
sudo systemctl enable mongod (to start normally at startup)
sudo systemctl disblae mongod
sudo systemctl stop mongod
sudo systemctl status mongod
```
Here the daemon defautly listens on the localhost port 27017
Here the daemon is set to defaulty only accept connection from localhost and remote connections will be accepted here.
