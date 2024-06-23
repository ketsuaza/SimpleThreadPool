#include <algorithm>

#include "hanoi_solver.hpp"
#include "move_command.hpp"

namespace solve_helper
{
  stick where_is_rest_stick(stick from, stick to);
}

std::vector<move_command>& hanoi_solver::get_command_list(int_fast8_t operand_disk, stick from, stick to)
{
  if(operand_disk == static_cast<int_fast8_t>(1))
  {
    // 1番目の円盤は上に乗りうる円盤がないため、そのまま行ける。
    this->_command_list.emplace_back(move_command(operand_disk, from, to));
    return this->_command_list;
  }
  else
  {
    // 自分の上に円盤があったら、まずはどかす。
    get_command_list(operand_disk - static_cast<int_fast8_t>(1), from, solve_helper::where_is_rest_stick(from, to));

    // どかした後に自分のいきたかった場所に行き、どかした円盤を自分の上に持ってくる。
    this->_command_list.emplace_back(move_command(operand_disk, from, to));
    get_command_list(operand_disk - static_cast<int_fast8_t>(1), solve_helper::where_is_rest_stick(from, to), to);

    return this->_command_list;
  }
}

stick solve_helper::where_is_rest_stick(stick from, stick to)
{
  // fromでもtoでも指定されていない棒が、LEFT MID RIGHTのうちどれかを探す。
  bool checker[3] {false, false, false};

  // 指定されたものに印をつける
  checker[static_cast<int_fast8_t>(from)] = true;
  checker[static_cast<int_fast8_t>(to)] = true;

  // 探したい棒は、印が付いていないもの。
  for(int_fast8_t counter {0}; counter<3; counter++)
  {
    if(!checker[counter])
    {
      return static_cast<stick>(counter);
    }
  }

  // エラー用stickを定義する必要がある。
  return stick::LEFT;
}