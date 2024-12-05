cmake_minimum_required(VERSION 3.20)
project(CMakeTestProject LANGUAGES CXX)

add_executable(speakerwithwoofer speaker.cpp)
target_compile_features(speakerwithwoofer PRIVATE cxx_std_20)