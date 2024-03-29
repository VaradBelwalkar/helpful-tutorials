To configure AWS CLI
```
aws configure
```


```
aws configure set aws_access_key_id test
aws configure set aws_secret_access_key test
aws configure set region us-east-1
aws configure set endpoint_url http://localhost:<port> --profile <service>
```





Create an S3 bucket:

```
aws s3api create-bucket --bucket mybucket --endpoint-url http://localhost:4572
```


List S3 buckets:

```
aws s3 ls --endpoint-url http://localhost:4572
```


Describe EC2 instances:

```
aws ec2 describe-instances --endpoint-url http://localhost:4597
```


Start an EC2 instance:

```
aws ec2 start-instances --instance-ids i-1234567890abcdef0 --endpoint-url http://localhost:4597
```


List DynamoDB tables:

```
aws dynamodb list-tables --endpoint-url http://localhost:4569
```



Create a DynamoDB table:  


```
aws dynamodb create-table --table-name MyTable --attribute-definitions AttributeName=MyKey,AttributeType=S --key-schema AttributeName=MyKey,KeyType=HASH --provisioned-throughput ReadCapacityUnits=5,WriteCapacityUnits=5 --endpoint-url http://localhost:4569
```




List Lambda functions:

```
aws lambda list-functions --endpoint-url http://localhost:4574
```


Create a Lambda function:

```
aws lambda create-function --function-name MyFunction --runtime nodejs14.x --role arn:aws:iam::123456789012:role/MyRole --handler index.handler --code S3Bucket=mybucket,S3Key=mycode.zip --endpoint-url http://localhost:4574
```



Create an SNS topic:

```
aws sns create-topic --name MyTopic --endpoint-url http://localhost:4575
```


List SNS topics:

```
aws sns list-topics --endpoint-url http://localhost:4575
```


Create an SQS queue:
```
aws sqs create-queue --queue-name MyQueue --endpoint-url http://localhost:4576
```


List SQS queues:

```
aws sqs list-queues --endpoint-url http://localhost:4576
```


Create an IAM user:

```
aws iam create-user --user-name MyUser --endpoint-url http://localhost:4593
```



List IAM users:

```
aws iam list-users --endpoint-url http://localhost:4593
```



Create a Kinesis stream:

```
aws kinesis create-stream --stream-name MyStream --shard-count 1 --endpoint-url http://localhost:4568
```


List Kinesis streams:

```
aws kinesis list-streams --endpoint-url http://localhost:4568
```



List RDS DB instances:

```
aws rds describe-db-instances --endpoint-url http://localhost:4599
```



Create an RDS DB instance (requires more detailed configuration):

```
aws rds create-db-instance ... --endpoint-url http://localhost:4599
```



List Elasticsearch domains:

```
aws es list-domain-names --endpoint-url http://localhost:4578
```


Create an Elasticsearch domain (requires more detailed configuration):

```
aws es create-elasticsearch-domain ... --endpoint-url http://localhost:4578
```


Upload a file to an S3 bucket:

```
aws s3 cp /path/to/localfile s3://mybucket/myfile --endpoint-url http://localhost:4572
```



List objects in an S3 bucket:

```
aws s3 ls s3://mybucket --endpoint-url http://localhost:4572
```


List CloudWatch alarms:

```
aws cloudwatch describe-alarms --endpoint-url http://localhost:4582
```


Put metric data (simulating metrics):

```
aws cloudwatch put-metric-data --namespace MyNamespace --metric-name MyMetric --value 1 --endpoint-url http://localhost:4582
```


List ECS clusters:

```
aws ecs list-clusters --endpoint-url http://localhost:4574
```



Create an ECS cluster:

```
aws ecs create-cluster --cluster-name MyCluster --endpoint-url http://localhost:4574
```



List EKS clusters:

```
aws eks list-clusters --endpoint-url http://localhost:4579
```



Create an EKS cluster (requires more detailed configuration):

```
aws eks create-cluster ... --endpoint-url http://localhost:4579
```



Create an SNS subscription for a topic:

```
aws sns subscribe --topic-arn arn:aws:sns:us-east-1:123456789012:MyTopic --protocol email --notification-endpoint your@email.com --endpoint-url http://localhost:4575
```


Publish a message to an SNS topic:

```
aws sns publish --topic-arn arn:aws:sns:us-east-1:123456789012:MyTopic --message "Hello, world!" --endpoint-url http://localhost:4575
```


Send a message to an SQS queue:

```
aws sqs send-message --queue-url http://localhost:4576/queue/MyQueue --message-body "Hello, SQS!" --endpoint-url http://localhost:4576
```


Receive a message from an SQS queue:

```
aws sqs receive-message --queue-url http://localhost:4576/queue/MyQueue --endpoint-url http://localhost:4576
```


List ElastiCache clusters:

```
aws elasticache describe-cache-clusters --endpoint-url http://localhost:4594
```


Create an ElastiCache cluster (requires more detailed configuration):

```
aws elasticache create-cache-cluster ... --endpoint-url http://localhost:4594
```


List KMS keys:

```
aws kms list-keys --endpoint-url http://localhost:4599
```


Create a KMS key (requires more detailed configuration):

```
aws kms create-key ... --endpoint-url http://localhost:4599
```



Create a CloudFormation stack (requires a CloudFormation template):

```
aws cloudformation create-stack --stack-name MyStack --template-body file://my-template.json --endpoint-url http://localhost:4581
```


List CloudFormation stacks:

```
aws cloudformation list-stacks --endpoint-url http://localhost:4581
```


List hosted zones:

```
aws route53 list-hosted-zones --endpoint-url http://localhost:4580
```


Create a hosted zone:

```
aws route53 create-hosted-zone --name example.com --caller-reference example-001 --endpoint-url http://localhost:4580
```


Describe ElastiCache clusters:

```
aws elasticache describe-cache-clusters --endpoint-url http://localhost:4594
```



Create an ElastiCache replication group (requires more detailed configuration):

```
aws elasticache create-replication-group ... --endpoint-url http://localhost:4594
```


List state machines:

```
aws stepfunctions list-state-machines --endpoint-url http://localhost:4585
```


Create a state machine (requires a Step Functions definition):

```
aws stepfunctions create-state-machine --name MyStateMachine --definition file://state-machine-definition.json --role-arn arn:aws:iam::123456789012:role/MyRole --endpoint-url http://localhost:4585
```

List ElastiCache Redis clusters:

```
aws elasticache describe-replication-groups --endpoint-url http://localhost:4594
```


Create an ElastiCache Redis cluster (cluster mode enabled):

```
aws elasticache create-replication-group ... --replication-group-description "My Redis Cluster" --endpoint-url http://localhost:4594
```


List App Runner services:

```
aws apprunner list-services --endpoint-url http://localhost:4566
```

Create an App Runner service (requires more detailed configuration):

```
aws apprunner create-service ... --source-code file://apprunner-source-code.json --endpoint-url http://localhost:4566
```


List Pinpoint projects:

```
aws pinpoint list-projects --endpoint-url http://localhost:4568
```



Create a Pinpoint project (requires more detailed configuration):

```
aws pinpoint create-app ... --endpoint-url http://localhost:4568
```


Update an App Runner service:

```
aws apprunner update-service --service-id MyServiceID --source-code file://updated-source-code.json --endpoint-url http://localhost:4566
```


Delete an App Runner service:

```
aws apprunner delete-service --service-id MyServiceID --endpoint-url http://localhost:4566
```


List MediaConvert jobs:

```
aws mediaconvert list-jobs --endpoint-url http://localhost:4580
```


Create a MediaConvert job (requires a job JSON configuration):

```
aws mediaconvert create-job --cli-parameters file://mediaconvert-job.json --endpoint-url http://localhost:4580
```


List Fargate clusters:

```
aws ecs list-clusters --endpoint-url http://localhost:4574
```


Create a Fargate cluster:

```
aws ecs create-cluster --cluster-name MyFargateCluster --capacity-providers FARGATE --endpoint-url http://localhost:4574
```


Describe a state machine:

```
aws stepfunctions describe-state-machine --state-machine-arn arn:aws:states:us-east-1:123456789012:stateMachine:MyStateMachine --endpoint-url http://localhost:4585
```



Delete a state machine:

```
aws stepfunctions delete-state-machine --state-machine-arn arn:aws:states:us-east-1:123456789012:stateMachine:MyStateMachine --endpoint-url http://localhost:4585
```


List Cognito user pools:

```
aws cognito-idp list-user-pools --endpoint-url http://localhost:4569
```


Create a Cognito user pool:

```
aws cognito-idp create-user-pool --pool-name MyUserPool --endpoint-url http://localhost:4569
```


Describe Elasticsearch domains:

```
aws es describe-elasticsearch-domain --domain-name MyElasticsearchDomain --endpoint-url http://localhost:4578
```


Delete an Elasticsearch domain:

```
aws es delete-elasticsearch-domain --domain-name MyElasticsearchDomain --endpoint-url http://localhost:4578
```



List DataSync tasks:

```
aws datasync list-tasks --endpoint-url http://localhost:4599
```


Create a DataSync task (requires more detailed configuration):

```
aws datasync create-task ... --endpoint-url http://localhost:4599
```























