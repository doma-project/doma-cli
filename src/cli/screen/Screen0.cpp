#include "cli/screen/Screen0.hpp"

#include <iostream>

namespace doma {
namespace cli {
namespace screen {

void Screen0::printMenu() const {
  std::cout << "Would you like to save your work?" << std::endl;
  std::cout << "Y. Yes" << std::endl;
  std::cout << "N. No" << std::endl;
}

} // namespace screen
} // namespace cli
} // namespace doma
