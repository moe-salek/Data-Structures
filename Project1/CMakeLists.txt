cmake_minimum_required(VERSION 3.10)
project(Project1 C)

set(CMAKE_C_STANDARD 99)

add_executable(linkedlist linkedlist.h linkedlist.c project.c project.h main.c )
