pipeline {
  agent any
  stages {
    stage('Create make files') {
      steps {
        echo 'Build with cmake'
        sh 'rm -rf build && mkdir build'
        dir('build') {
          sh 'cmake ..'
        } // dir
      }
    }
    stage('Build') {
      steps {
        dir('build') {
          sh 'make'
        }
      }
    }
    stage('Run') {
      steps {
        echo "Running ${env.JOB_NAME}"
        dir('build') {
          sh './helloWorld ${env.JOB_NAME}'
        }
      }
    }
  } // stages
  post {
    success {
      dir('build') {
        sh 'zip out.zip helloWorld'
      }
      archiveArtifacts artifacts: 'build/out.zip', fingerprint: true
    }
  }
}
