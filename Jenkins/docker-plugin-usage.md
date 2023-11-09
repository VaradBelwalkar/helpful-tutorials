Please follow this if you are runnig jenkins as a container else you can directly give unix socket address of docker to the cloud setup

First, pull the image alpine/socat:latest  
Then run that image using following command :  
 
 ```
docker run -d --restart=always \
            -p 127.0.0.1:2376:2375 \
            -v /var/run/docker.sock:/var/run/docker.sock \
            alpine/socat \
            tcp-listen:2375,fork,reuseaddr unix-connect:/var/run/docker.sock
```    
    
Once the container is up and running find the ip address of the container  
and paste that ip in the configuration like this:  
```  
tcp://<ip_address>:2375
```
Now test the connection and you should see the docker version and successful checking
  
