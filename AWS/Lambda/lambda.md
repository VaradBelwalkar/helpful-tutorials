This is somewhat good service, because what i think is this service is bad abstraction of simple workflow that Amazon uses,

Yes, I think it is really bad abstraction, for a devops Engineer, but a good one for a developer point of view.

Because ultimately, your function runs inside a container, of course, because why would Amazon run an EC2 instance for this?
and most imporantly, in most of the cases your functions  are lightweight performing some API related tasks, and not that much compute related,
so using an EC2 instance is overkill and will be time consuming as well, even if Amazon has reserves of running EC2 instances as you 
might have heard somewhere, tell me how much reserves they can have, to satisfy the needs of millions of accounts for the lambda service?

That is the reason, you are actually running the function in a container!


So how does this service work?

Well when you go to the lambda dashboard, you see list of created lambda functions, and option to create a lambda function

When you start creating a lambda function, you get three options,
```
Author from scratch
Use a blueprint
Container Image
```

---

Let's go one by one,
```
Author from scratch
```

Here first you give the function name,
then you actually select the runtime, this is, nothing but the base container image you select,
lambda currently supports, nodejs, go, python, java, ruby.
here you can provide your custom runtime, but wait, this doesn't mean you can select an image here, no, you are actually selecting a base
image which doesn't contain anything, where you bootstrap everything on your own.

Then you select the architecture to run on.

Then there are some options available, which actually tells a role for the lambda function,
there are again three options available here,
```
Create a new role with basic Lambda permissions
Use an existing role
Create a new role from AWS policy templates
```
Here, the first one creates a simple new role for the current lambda function, and associates it with the current function

The second one lets you choose the role that you have created under IAM.

The third one is to use roles from templates. 

Mostly the first one will do the job.

There are some advanced settings after that which are `code signing`, `enable VPC` to connect to a VPC to use resources that you have, 
Here the container then will be a part of the subnet, where it can use services exposed by your instances to compute or can interact with
them.


We don't require this as of now.
that is all.

---


The other option 
```
Use a blueprint
```
Here you select a blueprint, but let me tell you, it is nothing but a container images that AWS manages, which contains some default code
and the runtime is also specified there.
Meaning that AWS adds layers on top of the base image, with some functionality and then makes it as a blueprint for you.

Here, unlike the above, you already have option to add the lambda function there, which is prepopulated with some code AWS has given,
kinda a template.

There also comes triggers here, which are preselected as per blueprint.

Then the name, roles, options and so on.


---


Then the final option is,
```
Container Image
```

This lets you choose your own container image, by first giving the function name, and then the container image URI
Yes, this means that you cannot give the docker images here, because you get only URL there to fetch images, so you might have guessed it,
**it Requires a valid Amazon ECR image URI**.
means a valid Amazon Elastic Container Registry URI.

So first you need to have a valid Amazon ECR image, then you can use it.

So that is all

---

Here all three options are completed.


Now, when you go to the function, you have a function overview,
one is diagram, one is template, 
diagram one is user friendly, to add `trigger` and `destination`.

While the template one is more programmatic, and more structured well suited for advanced configuration.

Now you have bunch of predefined triggers, which will trigger the function when that thing is happened, and will pass the event 
parameter to the function.

here when you change the code, you need to deploy in order to save the changes, then you can test it there itself,
















































































