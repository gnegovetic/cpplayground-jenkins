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
      sh 'mkdir build/output'
      sh 'cp build/helloWorld build/output/'
      zip zipFile: 'build.zip', dir: 'build/output'
      archiveArtifacts artifacts: 'build.zip', fingerprint: true
    }
  }
}
