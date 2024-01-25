#!/bin/bash

# Create/update build files, compile and create/update executables
cd ..
cd build
cmake ..
cmake --build .