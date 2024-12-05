cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(note main.cpp)
target_compile_features(note PRIVATE cxx_std_20)