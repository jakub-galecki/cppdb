cmake_minimum_required(VERSION 3.19)
project(nextdb)

set(CMAKE_CXX_STANDARD 14)

include_directories(nextdb/db/api/include nextdb/db/client/include)

add_executable(nextdb nextdb/db/main.cpp nextdb/client/main.cpp nextdb/db/src/BTree.cpp nextdb/db/include/BTree.h nextdb/db/include/BTreeNode.h nextdb/db/src/BTreeNode.cpp nextdb/db/include/Content.h nextdb/db/src/Content.cpp nextdb/db/include/BTHandler.h nextdb/db/src/BTHandler.cpp nextdb/db/include/DbHandler.h nextdb/db/src/DbHandler.cpp nextdb/db/include/types.h nextdb/db/include/DBInterface.h)
