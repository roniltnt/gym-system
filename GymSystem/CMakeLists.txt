cmake_minimum_required(VERSION 3.10)
project(GymSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/Exercise.cpp
    src/Payment.cpp
    src/WorkoutPlan.cpp
    src/Subscription.cpp
    src/AnnualSubscription.cpp
    src/MonthlySubscription.cpp
    src/Person.cpp
    src/Member.cpp
    src/Trainer.cpp
    src/Equipment.cpp
    src/Machines.cpp
    src/Weights.cpp
    src/WeightMachine.cpp
    src/ClassSession.cpp
    src/PrivateSession.cpp
    src/GroupSession.cpp
    src/GymSystem.cpp
)

# Create executable
add_executable(GymSystem ${SOURCES})

# Compiler warnings
target_compile_options(GymSystem PRIVATE -Wall -Wextra)
