cmake_minimum_required(VERSION 3.17)
project(algorithms_tutorial)

set(CMAKE_C_STANDARD 11)

add_executable(lab1_demo1
        code_introduction/array_handling/main.c)
add_executable(lab1_demo2
        code_introduction/fractions_class/fraction.c
        code_introduction/fractions_class/main.c)
