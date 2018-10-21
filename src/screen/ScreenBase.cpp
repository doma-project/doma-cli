#include "screen/ScreenBase.hpp"

#include <iostream>

namespace doma {
namespace cli {
namespace screen {

void ScreenBase::registerActionHandler(const char action,
                                       const ActionHandlerType &actionHandler) {
  actionHandlers_[action] = actionHandler;
}

bool ScreenBase::tryDoAction(const char action) {
  const auto hasActionHandler = actionHandlers_.count(action) > 0;
  if (!hasActionHandler) {
    return false;
  }

  const auto &actionHandler = actionHandlers_[action];
  actionHandler();

  return true;
}

} // namespace screen
} // namespace cli
} // namespace doma
