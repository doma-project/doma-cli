#include "screen/Screen1_1.hpp"

#include <iostream>

namespace doma {
namespace cli {
namespace screen {

void Screen1_1::printMenu() const {
  std::cout << "1. Create a list" << std::endl;
  std::cout << "Q. Quit" << std::endl;
}

} // namespace screen
} // namespace cli
} // namespace doma
