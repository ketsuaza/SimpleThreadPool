cmake_minimum_required(VERSION 3.5)
project(hanoi-solver)

set(SOURCE_FILES hanoi_solver.cpp move_command.cpp)

add_library(hanoi-solver SHARED STATIC ${SOURCE_FILES})

install(TARGETS hanoi-solver DESTINATION ${BIN_DIR})
install(FILES hanoi_solver.hpp move_command.hpp DESTINATION ${INCLUDE_DIR})
