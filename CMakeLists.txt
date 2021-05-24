cmake_minimum_required(VERSION 3.19)
project(nextdb)

set(CMAKE_CXX_STANDARD 14)

include_directories(nextdb/db/api/include nextdb/db/client/include)

add_executable(nextdb nextdb/db/main.cpp nextdb/client/main.cpp)
