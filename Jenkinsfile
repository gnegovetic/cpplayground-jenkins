pipeline {
  agent any
  stages {
    stage('Create make files') {
      steps {
        echo 'Build with cmake'
        sh 'rm -rf build && mkdir build'
        dir('build') {
          cmake ..
        } // dir
      }
    } // stage
  }
}
