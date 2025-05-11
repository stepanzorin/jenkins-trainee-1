pipeline {
    agent {
      docker {
        image 'gcc:14.2.0'
        args  '-u root'
      }
    }

    options {
        skipDefaultCheckout()
    }

    environment {
      CC = 'gcc'
      CXX = 'g++'

      // Project
      PROJECT_DIR_PATH = "${WORKSPACE}/project"
      // Tools
      TOOLS_DIR_PATH = "${WORKSPACE}/tools/"
      // Python 3
      PYTHON_DIR_PATH = "${TOOLS_DIR_PATH}/python3"
      PYTHON_VENV_DIR_PATH = "${PYTHON_DIR_PATH}/.venv"
      PYTHON_VENV_ACTIVATE_PATH = "${PYTHON_VENV_DIR_PATH}/bin/activate"
      // Conan 2
      CONAN_VERSION = '2.16.1'
      CONAN_HOME = "${WORKSPACE}/.conan2"
    }

    stages {
        stage('Preparing') {
            steps {
                sh '''
                  cat /etc/os-release
                  whoami

                  $CC --version
                  $CXX --version
                '''

                sh'''
                  apt-get update -qq

                  DEBIAN_FRONTEND=noninteractive apt-get install -y \
                    git                 \
                    cmake               \
                    ninja-build         \
                    python3-pip         \
                    python3-full        \
                    python3-venv        \
                    libssl-dev          \
                    pkg-config

                  apt-get clean
                '''
                sh '''
                  git --version
                  cmake --version
                  python3 --version
                  pip --version
                '''

                sh 'checkout scm'
            }
        }

        stage('Dependencies') {
            steps {
                sh '''
                  python3 -m venv $PYTHON_VENV_DIR_PATH --upgrade-deps
                  . $PYTHON_VENV_ACTIVATE_PATH

                  pip install --upgrade pip

                  pip install "conan==$CONAN_VERSION"
                  conan --version

                  conan install . --build=missing
                '''
            }
        }
    }
}