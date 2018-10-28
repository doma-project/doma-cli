#include "cli/screen/Screen1_1.hpp"

#include <iostream>

#include "cli/screen/ActionHelper.hpp"

namespace doma {
namespace cli {
namespace screen {

void Screen1_1::printMenu() const {
  std::cout << "1. Create a list" << std::endl;
  std::cout << ActionHelper::GetActionString(Actions::kQuit) << std::endl;
}

} // namespace screen
} // namespace cli
} // namespace doma
