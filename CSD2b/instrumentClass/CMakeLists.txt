cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(instrument main.cpp instrument.cpp)
target_compile_features(instrument PRIVATE cxx_std_20)