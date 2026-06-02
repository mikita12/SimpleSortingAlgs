cmake_minimum_required(VERSION 3.10)
project(AizoP1)

set(CMAKE_CXX_STANDARD 17)

add_executable(aizoP1 src/main.cpp)

target_include_directories(aizoP1 PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(aizoP1 
    ${CMAKE_SOURCE_DIR}/libparameters.so
)

target_compile_options(aizoP1 PRIVATE -Wall -Wextra -Werror)

set_target_properties(aizoP1 PROPERTIES
    BUILD_RPATH "${CMAKE_SOURCE_DIR}"
    INSTALL_RPATH "${CMAKE_SOURCE_DIR}"
)