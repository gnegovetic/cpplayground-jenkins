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
