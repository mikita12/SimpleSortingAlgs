cmake_minimum_required(VERSION 3.10)

project(ListProject)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror)

include_directories(include)

add_executable(main
    src/main.cpp
)