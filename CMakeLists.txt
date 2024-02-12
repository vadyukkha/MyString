cmake_minimum_required(VERSION 3.26)
project(MyString)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)

add_executable(MyString
        include/MyString.h
        src/main.cpp
        src/MyString.cpp)
