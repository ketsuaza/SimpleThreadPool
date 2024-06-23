#ifndef INCLUDED_HANOI_SOLVER_HPP
#define INCLUDED_HANOI_SOLVER_HPP

#include <cstdint>
#include <vector>

#include "move_command.hpp"

class hanoi_solver
{
  public:
  hanoi_solver() = default;
  // <operand_disk>番目の円盤を、<from>から<to>に持っていく際必要なコマンドのリストの取得
  std::vector<move_command>& get_command_list(int_fast8_t operand_disk, stick from, stick to);

  private:
  std::vector<move_command> _command_list;
};

#endif // INCLUDED_HANOI_SOLVER_HPP