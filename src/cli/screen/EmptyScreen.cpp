#include "cli/screen/EmptyScreen.hpp"

#include <iostream>

namespace doma {
namespace cli {
namespace screen {

void EmptyScreen::printMenu() const {
  std::cout << "Q. Quit" << std::endl;
}

} // namespace screen
} // namespace cli
} // namespace doma
