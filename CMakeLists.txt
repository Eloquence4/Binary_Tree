cmake_minimum_required(VERSION 3.9)
project(Triggers)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/BinaryTree.h
        HPP/BinaryTree.hpp
        HPP/BinaryTreeIterator.hpp

        main.cpp
)

include_directories(
        .
        include
)

add_executable(Triggers ${SOURCE_FILES})
