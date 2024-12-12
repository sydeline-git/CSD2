cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(basic_pointers basic_pointers.cpp)
target_compile_features(basic_pointers PRIVATE cxx_std_20)