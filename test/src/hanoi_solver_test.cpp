//
// Created by Konstantin Gredeskoul on 5/16/17.
//
#include <cstdint>
#include <cmath>
#include <stdexcept>
#include <memory>

#include "gtest/gtest.h"

#include "hanoi_solver.hpp"
#include "move_command.hpp"

class HanoiSolverTest : public ::testing::Test {

protected:
  virtual void SetUp() {
  };

  virtual void TearDown() {
  };

  virtual void check(int N) {
    auto solver = std::make_unique<hanoi_solver>();
    auto command_list {solver->get_command_list(N, stick::LEFT, stick::RIGHT)};
    EXPECT_EQ(command_list.size(), std::pow(2, N) - 1);
  }
};

// test case 1: N = 3 なので、8手
TEST_F(HanoiSolverTest, case1_N_3) {
  check(3);
}

// test case 2: N = 3 なので、32手
TEST_F(HanoiSolverTest, case2_N_5) {
  check(5);
}

// test case 3: N = 10 なので、1024手
TEST_F(HanoiSolverTest, case3_N_10) {
  check(10);
}

// test case 4: N = -3
TEST_F(HanoiSolverTest, case4_N_m3) {
  // 未定義……
}