cmake_minimum_required(VERSION 3.23)
project(STL_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(STL_exercise test/main.cpp header/tools.h src/stlLearning.cpp header/stlLearning.h src/tools.cpp header/test.h src/test.cpp)
