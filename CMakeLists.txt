cmake_minimum_required(VERSION 3.25)
project(containers_iterators_algorithms)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(inc)
include_directories(src)

add_executable(containers_iterators_algorithms
        src/Cia.cpp
        inc/Cia.h
        src/test-driver.cpp)
