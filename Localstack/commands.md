When you have installed the localstack binary, and copy it to global location such as /usr/bin,
then
This command will,
```
localstack start
```
Fetch the docker-image for the localstack, run it with the predefined parameters, and then serve it to you!

You simply need to run the awscli then to be able to work with this


Start LocalStack with specific services enabled:

```
localstack start --services s3,ec2,sqs
```

List the services that are currently enabled in your LocalStack instance:

```
localstack services list
```



