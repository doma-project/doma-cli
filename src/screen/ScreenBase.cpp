#include "screen/ScreenBase.hpp"

#include <iostream>

namespace doma {
namespace cli {
namespace screen {

void ScreenBase::registerAction(const char action,
                                const RegistredActionCallback &registredActionCallback) {
  actions_[action] = registredActionCallback;
}

bool ScreenBase::handleAction(const char action) {
  const auto hasAction = actions_.count(action) > 0;
  if (!hasAction) {
    return false;
  }

  actions_[action]();

  return true;
}

} // namespace screen
} // namespace cli
} // namespace doma
