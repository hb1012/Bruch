# {---
# compiler and linker flags
#SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS "-pthread -static -L/usr/local/lib -lboost_unit_test_framework")

# add flags 1. way
# The easiest one (not clean, but easy and convenient, and works only for compile flags, C & C++ at once):
#add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

# add flags 2. way
# Appending to corresponding CMake variables:
#SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# add flags 3. way
# Using target properties, cf. doc CMake compile flag target property and need to know the target name.
#get_target_property(TEMP ${THE_TARGET} COMPILE_FLAGS)
#if(TEMP STREQUAL "TEMP-NOTFOUND")
#  SET(TEMP "") # Set to empty string
#else()
#  SET(TEMP "${TEMP} ") # A space to cleanly separate from existing content
#endif()
# Append our values
#SET(TEMP "${TEMP}${GCC_COVERAGE_COMPILE_FLAGS}" )
#set_target_properties(${THE_TARGET} PROPERTIES COMPILE_FLAGS ${TEMP} )
# ---}

# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${COMMON_INCLUDES})
# link_directories(D:/Public/Dev/Projects/C++/Bruch/Google_tests/lib ${CMAKE_SOURCE_DIR}/lib)

set(BINARY ${CMAKE_PROJECT_NAME}BoostTest)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib)
