cmake_minimum_required(VERSION 3.5)

project(simple_thread_pool_suite)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -O2")
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/include)

include_directories(${HEADERS_DIR})

add_subdirectory(src)
add_subdirectory(test)