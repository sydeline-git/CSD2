cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(oscillator main.cpp oscillator.cpp)
target_compile_features(oscillator PRIVATE cxx_std_20)