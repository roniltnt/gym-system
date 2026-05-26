#!/bin/bash

# 1. Enter the build directory
cd build

# 2. Re-configure with CMake (catches any new files added)
cmake ..

# 3. Build the project
cmake --build .

# 4. Check if the build was successful, then run
if [ $? -eq 0 ]; then
    echo "---------------------------"
    # Replace 'MyProject' with the name you gave in CMakeLists.txt
    ./GymSystem
else
    echo "Build Failed!"
fi
