cmake_minimum_required(VERSION 3.31)
project(hex_parser C)

set(CMAKE_C_STANDARD 23)

add_executable(hex_parser main.c
        string.h
        hexadecimal.h
)
