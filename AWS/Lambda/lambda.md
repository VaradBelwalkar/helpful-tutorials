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
  
  here when you change the code, you need to deploy in order to save the changes, then you can test it there itself.
  
  But wait how does this even work?
  
  
  When you select the runtime, be it `from scratch` or `blueprint` or `Container image`,
  Amazon creates a directory inside it i.e inside the container of your lambda function name, if your function name is `limo`,
  then it will create a directory called limo, and will fill up with one file, for nodejs, it is index.mjs, and fill it with the prepopulated
  or template or the bootstrap code to start with.
  
  Here, a container is spin up from the image that you selected, and then that container's environment is given to you.
  where there is a directory created of you function name, and then, populated with the predefined code, here you can add your other 
  supporting files and possibly node_modules for 3rd party dependancies, and then click deploy, often automatically done when you upload something, which means that it gets written into the image, as a layer or hidden layer, which doesn't get listed above, 
  
  Here the previous all layers are merged to have storage efficiency, and that is why you don't see the layers in the layers section.
  
  After you design your working directory with your code, files, folders, then you deploy it, so that the image gets updated.
  It is somewhat like commiting a container with the changes to a new image.
  
  After this is done, you can simply see how it works.
  
  But before this, you can add your own layers there, the benifit is that, you can reuse this layer in other lambda functions,
  meaning that you can add your files, folders and custom things to this layer, in predefined way, and create this layer, which 
  is then overlayed with the existing main layer of the container image, so that you don't need to upload files and folders again and again.
  
  Here, you have tiny little text written as `create new layer` there when you try adding a layer.

This actually lets you to the create layer section, where you can create your own layer.

There you have options to add the .zip file, rather than bunch of things, or a file from s3 buckets.
its your choice.

Once you create it, 
you have options to use AWS layers, provided by AWS,
or custom layers, that you created,
or you can specify the ARN.


So we should select the 2nd option here, and then use that layer which we created.


Here, what it does is,

Simply gets the layer, overlays it over the working directory of our container, when the container is run, 
and unzips it on the root of our directory, so directory structure is important to consider in order for your code to be run.

So this is the layer!

You can simply use this layer in other AWS Lambda function and go with it, so you don't need to manually upload the files and folders each
time. 


