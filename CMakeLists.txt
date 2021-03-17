cmake_minimum_required(VERSION 3.17)
project(algorithms_tutorial)

set(CMAKE_C_STANDARD 11)

add_executable(lab1_demo1
        code_introduction/array_handling/main.c)
add_executable(lab1_demo2
        code_introduction/fractions_class/fraction.c
        code_introduction/fractions_class/main.c)
add_executable(lab2_demo1
        code_stacks/expression_evaluation/stack.c
        code_stacks/expression_evaluation/main.c)
add_executable(lab3_demo1
        code_trees/basic_ops/bst.cpp
        code_trees/basic_ops/main.cpp)
add_executable(lab4_demo1
        code_trees/bst_augmentations/bst.c
        code_trees/bst_augmentations/main.c)
add_executable(lab4_demo2
        code_stacks/deque_etersun/etersun.cpp)
add_executable(lab4_demo3
        code_stacks/queue_trucktour/trucktour.cpp)
