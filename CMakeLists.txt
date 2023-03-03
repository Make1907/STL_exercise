cmake_minimum_required(VERSION 3.10)

# set the project name
project(STL_exercise)

# add the executable
add_executable(STL_exercise
        header/ptr.h
        header/stlLearning.h
        header/test.h
        header/tools.h
        src/ptr.cpp
        src/stlLearning.cpp
        src/tools.cpp
        src/test.cpp
        src/main.cpp)