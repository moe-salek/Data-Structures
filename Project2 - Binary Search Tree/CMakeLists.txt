cmake_minimum_required(VERSION 3.10)
project(miniproject2 C)

set(CMAKE_C_STANDARD 99)

add_executable(miniproject2 main.c stack.c stack.h queue.c queue.h tree.c tree.h bst.c bst.h )
