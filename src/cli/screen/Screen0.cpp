#include "cli/screen/Screen0.hpp"

#include <iostream>

#include "cli/screen/ActionHelper.hpp"

namespace doma {
namespace cli {
namespace screen {

void Screen0::resetActionHandlers() {
  ScreenBase::resetActionHandlersExcept({Actions::kYes, Actions::kNo});
}

void Screen0::printMenu() const {
  std::cout << "Would you like to save your work?" << std::endl;
  std::cout << ActionHelper::GetActionString(Actions::kYes) << std::endl;
  std::cout << ActionHelper::GetActionString(Actions::kNo) << std::endl;
}

} // namespace screen
} // namespace cli
} // namespace doma
