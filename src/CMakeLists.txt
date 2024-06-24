cmake_minimum_required(VERSION 3.5)
project(simple_thread_pool)

set(SOURCE_FILES src/simple_thread_pool.cpp)

include_directories(${HEADERS_DIR})

add_library(simple_thread_pool SHARED STATIC ${SOURCE_FILES})

install(TARGETS simple_thread_pool DESTINATION ${LIB_DIR})
install(FILES simple_thread_pool.hpp DESTINATION ${INCLUDE_DIR})