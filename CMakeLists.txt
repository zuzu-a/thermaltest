cmake_minimum_required(VERSION 3.16)

project(thermaltest)

add_executable(thermaltest thermaltest.cpp)

install(TARGETS thermaltest)

enable_testing()
add_test(NAME thermaltest COMMAND thermaltest)
