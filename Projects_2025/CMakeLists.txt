cmake_minimum_required(VERSION 3.10)

project(AutoToolchain)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(MergeSort)
add_subdirectory(Journey)

set(CMAKE_SUPPRESS_REGENERATION true)