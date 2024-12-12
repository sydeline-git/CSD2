cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(B main.cpp)
target_compile_features(B PRIVATE cxx_std_20)