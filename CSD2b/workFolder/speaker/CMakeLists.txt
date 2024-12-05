cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(speaker main.cpp speaker.cpp tweeter.cpp woofer.cpp tweeter.h woofer.h speaker.h)
target_compile_features(speaker PRIVATE cxx_std_20)