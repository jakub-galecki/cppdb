cmake_minimum_required(VERSION 3.19)
project(nextdb)

set(CMAKE_CXX_STANDARD 14)

include_directories(nextdb/server/include nextdb/client/include)

add_executable(nextdb
        nextdb/client/main.cpp nextdb/server/main.cpp)
