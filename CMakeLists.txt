cmake_minimum_required(VERSION 3.10.2)
project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(lab1 lab1.cpp Vector.cpp KV.cpp)

