cmake_minimum_required(VERSION 3.31)
project(hexed C)

set(CMAKE_C_STANDARD 23)

add_executable(hexed main.c
        util.h
        hexadecimal.h
        input.h
        arg_parser.h
)
