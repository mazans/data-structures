cmake_minimum_required(VERSION 3.9)
project(SDIZO)

set(CMAKE_CXX_STANDARD 11)

add_executable(SDIZO main.cpp Heap.cpp Heap.h List.cpp List.h Table.cpp Table.h BST.cpp BST.h)