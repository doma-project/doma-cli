#pragma once

#include "cli/screen/IScreen.hpp"

#include <set>
#include <unordered_map>

namespace doma {
namespace cli {
namespace screen {

class ScreenBase : public IScreen {
 public:
  void registerActionHandler(const Action action,
                             const ActionHandlerType &actionHandler) override;
  void resetActionHandlers() override;
  bool tryDoAction(const Action action) override;

 protected:
  ScreenBase();

 protected:
  using ActionHandlers = std::unordered_map<Action, IScreen::ActionHandlerType>;

 protected:
  ActionHandlers actionHandlers_;

 protected:
  void resetActionHandlersExcept(const std::set<Action> &exceptActions);
};

} // namespace screen
} // namespace cli
} // namespace doma
