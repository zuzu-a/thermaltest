cmake_minimum_required(VERSION 3.16)

project(flacsat)

add_executable(flacsat flacsat.cpp)

install(TARGETS flacsat)

enable_testing()
add_test(NAME flacsat COMMAND flacsat)
