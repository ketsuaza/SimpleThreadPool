cmake_minimum_required(VERSION 3.5)
project(hanoi-main)

add_subdirectory(hanoi-solver)
set(SOURCE_FILES main.cpp)

add_executable(hanoi-main ${SOURCE_FILES})
target_link_libraries(hanoi-main hanoi-solver)

install(TARGETS hanoi-main DESTINATION ${BIN_DIR})
