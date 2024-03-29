Localstack is an amazing tool to be able to work with amazon services all locally, without having to do anything on actual infrastructure.

There are two ways to setup localstack instance running on your computer, both are container based, but have minor differences,

---

1.) use Localstack CLI, 
This way you simply need to install the localstack cli on your computer, and then, simply need to write command
        localstack start 

To get the localstack instance running, remember that, this command will simply fetch the localstack/localstack image from registry and then
simply run it with certain parameters and configurations. 
We don't have to care about those things.


---

2.) To get the docker-compose file,
This way you simply get the docker-compose file, run it using 
              docker-compose up

and then the localstack instance will spin up, it will do the same, will fetch the localstack/localstack image, from the registry, and then run it 
with the parameters and configurations, here is that you can see those configurations in the docker-compose file.


This is the example docker-compose file: 

```
version: "3.8"

services:
  localstack:
    container_name: "${LOCALSTACK_DOCKER_NAME-localstack_main}"
    image: localstack/localstack
    ports:
      - "127.0.0.1:4566:4566"            # LocalStack Gateway
      - "127.0.0.1:4510-4559:4510-4559"  # external services port range
    environment:
      - DEBUG=${DEBUG-}
      - DOCKER_HOST=unix:///var/run/docker.sock
    volumes:
      - "${LOCALSTACK_VOLUME_DIR:-./volume}:/var/lib/localstack"
      - "/var/run/docker.sock:/var/run/docker.sock"
```


