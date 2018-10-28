#include "cli/screen/EmptyScreen.hpp"

#include <iostream>

#include "cli/screen/ActionHelper.hpp"

namespace doma {
namespace cli {
namespace screen {

void EmptyScreen::printMenu() const {
  std::cout << ActionHelper::GetActionString(Actions::kQuit) << std::endl;
}

} // namespace screen
} // namespace cli
} // namespace doma
