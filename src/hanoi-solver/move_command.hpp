#ifndef INCLUDED_MOVE_COMMAND_HPP
#define INCLUDED_MOVE_COMMAND_HPP

#include <cstdint>

enum class stick
{
  LEFT,
  MID,
  RIGHT
};

class move_command
{
  public:
  move_command(int_fast8_t operand_disk, stick from, stick to) noexcept : 
              _operand_disk(operand_disk), _from(from), _to(to) {}
  void view();
  
  private:
  int_fast8_t _operand_disk{static_cast<int_fast8_t>(0)};
  stick _from {stick::LEFT};
  stick _to {stick::LEFT};
};

#endif // INCLUDED_MOVE_COMMAND_HPP