#!/bin/bash

while getopts h:u: option; 
do

	case "$option" in
        h)
            exit;;
        u)

            USERNAME=${OPTARG};;
    esac
done

if [ -z ${USERNAME+x} ];
then
  USERNAME=$USER;
fi

export PROJECT_DIR="/home/$USERNAME/geometry_utilities"
echo $PROJECT_DIR

if [ -d ./build ]; then
    echo "Deleting build directory."
    rm -rf ${PROJECT_DIR}/build
fi

if [ -d /usr/local/include/geometry_utilities   ]; then
    echo "Deleting shared library."
    rm -rf /usr/local/include/geometry_utilities
fi

if [ -d /usr/local/lib/geometry_utilities ]; then
    echo "Deleting shared library."
    rm -rf /usr/local/lib/geometry_utilities
fi

#if [ -d /usr/local/bin/geometry_utilities ]; then
#    echo "Deleting shared library."
#    rm -rf /usr/local/bin/geometry_utilities
#fi

mkdir ./build

cd build

cmake ..

cmake --build . --target install

if [ -d ${PROJECT_DIR}/test ]; then
  echo "Found test directory, creating test files"
  cd ${PROJECT_DIR}/test
  rm -rf ./build
  mkdir build
  cd build
  cmake ..
  cmake --build . --target install
fi