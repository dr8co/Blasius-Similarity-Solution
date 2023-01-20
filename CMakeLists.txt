cmake_minimum_required(VERSION 3.20)
project(blasius CXX)

set(CMAKE_CXX_STANDARD 23)

include_directories(${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-Wall -pedantic -Ofast")

add_executable(blasius
        main.cpp
        blasius.cpp)
