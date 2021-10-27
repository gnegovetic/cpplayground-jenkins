# cpplayground-Jenkins

Hello world for Jenkins CI pipelines

## Prerequisites 
Docker installed and running on the host machine
## Setup
1. Install Jenkins: docker pull jenkins/jenkins:lts-jdk11 (see https://hub.docker.com/r/jenkins/jenkins)
2. Run Jenkins server: see https://github.com/jenkinsci/docker/blob/master/README.md
3. Open Jenkins at http://localhost:8080 and install plugins (git, GitHub)
4. Create a new Pipeline
	- Select GitHub project and set the URL
	- In Pipeline: select "Pipeline script from SCM"
	- For SCM, select Git and set GitHub project URL
	- Save the project
5. Build the pipeline

