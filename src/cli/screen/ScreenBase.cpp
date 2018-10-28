#include "cli/screen/ScreenBase.hpp"

#include <iostream>
#include <cli/screen/ScreenBase.hpp>

namespace doma {
namespace cli {
namespace screen {

ScreenBase::ScreenBase() : actionHandlers_() {}

void ScreenBase::registerActionHandler(const Action action,
                                       const ActionHandlerType &actionHandler) {
  actionHandlers_[action] = actionHandler;
}

void ScreenBase::resetActionHandlers() {
  // Delete all action handlers except quit handler
  resetActionHandlersExcept({Actions::kQuit});
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

void ScreenBase::resetActionHandlersExcept(const std::set<char> &exceptActions) {
  auto actionHandlersIt = actionHandlers_.begin();
  while (actionHandlersIt != actionHandlers_.end()) {
    const auto& action = actionHandlersIt->first;
    const auto skipActionHandlerRemoval = exceptActions.count(action) > 0;

    if (skipActionHandlerRemoval) {
      ++actionHandlersIt;
    } else {
      actionHandlers_.erase(actionHandlersIt++);
    }
  }
}

} // namespace screen
} // namespace cli
} // namespace doma
