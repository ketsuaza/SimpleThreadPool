#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

#include "move_command.hpp"
#include "hanoi_solver.hpp"

namespace main_helper
{
  int_fast8_t error_occured();
  int_fast8_t try_normal_sequence(int_fast8_t num_of_disks, const std::unique_ptr<hanoi_solver> solver);
  void view_result(const std::vector<move_command>& command_list);
}

// in: <num of disks>
int main(int argc, const char *argv[]) 
{
  int_fast8_t ret_val {static_cast<int_fast8_t>(0)};

  if (argc != 2) 
  {
    // ハノイの塔を解くという最終目的の上では、num of disksのみで一意に盤面を定義できるため、num of disksしかとらない。
    ret_val = main_helper::error_occured();
  }
  else if(static_cast<int_fast8_t>(atoi(argv[1])) < 1)
  {
    // 円盤の数は、1以上である必要がある。
    ret_val = main_helper::error_occured();
  }
  else
  {
    // num_of_disksをnとした時、ハノイの塔を解くのに2^n-1 step必要。n=255の時に約1.15e+77 step必要となるため、1byteで十分。
    int_fast8_t num_of_disks {static_cast<int_fast8_t>(atoi(argv[1]))};
    auto solver = std::make_unique<hanoi_solver>();
    ret_val = main_helper::try_normal_sequence(num_of_disks, std::move(solver));
  }

  return static_cast<int>(ret_val);
}

int_fast8_t main_helper::error_occured()
{
  std::cout << "invalid input.\nin: <num of disks>" << std::endl;
  return static_cast<int_fast8_t>(1);
}

int_fast8_t main_helper::try_normal_sequence(int_fast8_t num_of_disks, const std::unique_ptr<hanoi_solver> solver)
{
  try
  {
    auto command_list {solver->get_command_list(num_of_disks, stick::LEFT, stick::RIGHT)};
    main_helper::view_result(command_list);
    return static_cast<int_fast8_t>(0);
  }
  catch(...)
  {
    std::cout << "reduce num of disks." << std::endl;
    return static_cast<int_fast8_t>(1);
  }
}

void main_helper::view_result(const std::vector<move_command>& command_list)
{
  for(auto command : command_list)
  {
    command.view();
  }
}