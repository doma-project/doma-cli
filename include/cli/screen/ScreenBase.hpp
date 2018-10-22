#pragma once

#include "cli/screen/IScreen.hpp"

#include <unordered_map>

namespace doma {
namespace cli {
namespace screen {

class ScreenBase : public IScreen {
 public:
  void registerActionHandler(const char action,
                             const ActionHandlerType &actionHandler) override;

  bool tryDoAction(const char action) override;

 protected:
  ScreenBase() = default;

 protected:
  std::unordered_map<char, IScreen::ActionHandlerType> actionHandlers_;
};

} // namespace screen
} // namespace cli
} // namespace doma
