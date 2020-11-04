cmake_minimum_required(VERSION 3.17)
project(SequentialStack)

set(CMAKE_CXX_STANDARD 14)

add_executable(SequentialStack main.cpp Stack.h SeqStack.h Calculator.cpp Calculator.h)