cmake_minimum_required(VERSION 3.5)

project(simple_thread_pool_test)

add_subdirectory(lib/googletest)

include_directories(${HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/simple_thread_pool_test.cpp)

add_executable(simple_thread_pool_test ${SOURCE_FILES})
target_link_libraries(simple_thread_pool_test simple_thread_pool gtest)

install(TARGETS simple_thread_pool_test DESTINATION bin)