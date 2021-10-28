# cpplayground-Jenkins

Hello world for Jenkins CI pipelines. We want to set up Jenkins to build C++ projects from GitHub. 

## Prerequisites 
Docker installed and running on the host machine (tested on MacOS 11.6, arm64)
## Setup
Useful resources:
- https://hub.docker.com/r/jenkins/jenkins
- https://github.com/jenkinsci/docker/blob/master/README.md
- https://www.jenkins.io/doc/book/installing/docker/

We are going to install Jenkins in a container, and we need docker-in-docker container to execute our builds. The two containers need to communicate with each other. 

## Steps:
1. Create a network for the containers:
```
docker network create jenkins
```

2. Run the docker-in-docker container. Note that we map 'jenkins_home' folder that will contain our project files. This is essential for Jenkins to "transfer" files into the container that will execute the build. 
```
docker run --name jenkins-docker -d --privileged --network jenkins --network-alias docker --env DOCKER_TLS_CERTDIR=/certs -v jenkins-docker-certs:/certs/client -v jenkins_home:/var/jenkins_home -p 2376:2376 docker:dind --storage-driver overlay2
```

3. Build our Jenkins container. We need to add docker-ce-cli to the image so that Jenkins can execute 'docker' commands. This is done in 'Jenkins-setup/Jenkins.Dockerile'. 

```
docker build -t mr.jenkins -f Jenkins-setup/Jenkins.Dockerfile Jenkins-setup/
```

4. Run Jenkins server 
```
docker run --name jenkins1 -d --network jenkins --env DOCKER_HOST=tcp://docker:2376 --env DOCKER_CERT_PATH=/certs/client --env DOCKER_TLS_VERIFY=1 -p 8080:8080 -p 50000:50000 -v jenkins_home:/var/jenkins_home -v jenkins-docker-certs:/certs/client:ro mr.jenkins
```

5. Open Jenkins at http://localhost:8080 
	- Set up an account
	- install plugins: git, GitHub, Docker, Docker Pipeline

6. Create a new Pipeline
	- Select GitHub project and set the URL
	- In Pipeline: select "Pipeline script from SCM"
	- For SCM, select Git and set GitHub project URL
	- Save the project

7. Build the pipeline

