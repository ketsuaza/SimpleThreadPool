cmake_minimum_required(VERSION 3.5)
project(hanoi_solver_test)

add_subdirectory(lib/googletest)

include_directories(${HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/hanoi_solver_test.cpp)

add_executable(hanoi_solver_test ${SOURCE_FILES})
target_link_libraries(hanoi_solver_test hanoi-solver gtest)

install(TARGETS hanoi_solver_test DESTINATION bin)