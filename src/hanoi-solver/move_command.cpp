#include <iostream>
#include <string>

#include "move_command.hpp"

namespace view_helper
{
  std::string stick_to_string(stick operand_stick);
}

void move_command::view()
{
  std::cout << "move " << std::to_string(this->_operand_disk) << " from " << view_helper::stick_to_string(this->_from) << " to " << view_helper::stick_to_string(this->_to) << std::endl;
}

std::string view_helper::stick_to_string(stick operand_stick)
{
  switch (operand_stick)
  {
  case stick::LEFT:
    return "LEFT";
    break;
  case stick::MID:
    return "MID";
    break;
  case stick::RIGHT:
    return "RIGHT";
    break;
  default:
    return "";
    break;
  }
}