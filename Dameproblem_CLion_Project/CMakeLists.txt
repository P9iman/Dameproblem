cmake_minimum_required(VERSION 3.26)
project(Dameproblem_CLion_Project C)

set(CMAKE_C_STANDARD 11)

add_executable(Dameproblem_CLion_Project main.c
        board.c
        checkers.c)
