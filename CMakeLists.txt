cmake_minimum_required(VERSION 3.25)
project(My_first_project C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

cmake_policy(SET CMP0074 NEW)

add_executable(main Helloworld/main.c)
