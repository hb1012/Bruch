cmake_minimum_required(VERSION 3.16)
project(Bruch)

#set(GCC_COVERAGE_COMPILE_FLAGS "-fmodules -fmodule-file=src/Bruch.cppm")
#set (CMAKE_CXX_FLAGS "-fexceptions")

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

include_directories(src)

add_subdirectory(src)
add_subdirectory(gtest)
add_subdirectory(doctest)
add_subdirectory(boost_test)
#add_subdirectory(lib)
