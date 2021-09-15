# compiler and linker flags
#[[if(DEFINED ENV{WSL_DISTRO_NAME})
    #SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
    set(GCC_COVERAGE_LINK_FLAGS "-pthread")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
else()
    # needed in MinGW
    set(gtest_disable_pthreads on)
endif()]]
set(GCC_COVERAGE_LINK_FLAGS "-pthread")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
set(gtest_disable_pthreads on)

# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${COMMON_INCLUDES})
# link_directories(D:/Public/Dev/Projects/C++/Bruch/Google_tests/lib ${CMAKE_SOURCE_DIR}/lib)

set(BINARY ${CMAKE_PROJECT_NAME}GoogleTest)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
