cmake_minimum_required(VERSION 3.10)
project(semana06 C)

set(CMAKE_C_STANDARD 11)

include_directories(1)
include_directories(2)
include_directories(3)
include_directories(4)

add_executable(semana06
        1/main.c
        1/match.c
        1/match.h
        1/stack.c
        1/stack.h
        2/main.c
        2/match.c
        2/match.h
        2/stack.c
        2/stack.h
        3/array_helpers.c
        3/array_helpers.h
        3/main.c
        3/queue.c
        3/queue.h
        3/sort.c
        3/sort.h
        4/array_helpers.c
        4/array_helpers.h
        4/main.c
        4/queue.c
        4/queue.h
        4/sort.c
        4/sort.h)
