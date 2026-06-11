cmake_minimum_required(VERSION 4.1)
project(test1)

set(CMAKE_CXX_STANDARD 20)


# UTF-8 编码支持
add_compile_options(-fexec-charset=UTF-8 -finput-charset=UTF-8)
add_executable(test1 main.cpp)
