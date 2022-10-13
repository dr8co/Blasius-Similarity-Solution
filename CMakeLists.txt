cmake_minimum_required(VERSION 3.20)
project(blasius)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/headers)

add_executable(blasius
        main.cpp
        blasius.cpp)