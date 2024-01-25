#!/bin/bash

# Remove all build files, Create build files, compile and create executables
cd ..
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .

# prevent WSL terminal automatically closing if run in vscode
$SHELL