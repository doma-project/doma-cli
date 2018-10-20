#pragma once

#include "screen/IScreen.hpp"

#include <unordered_map>

namespace doma {
namespace cli {
namespace screen {

class ScreenBase : public IScreen {
 public:
  void registerAction(const char action,
                      const RegistredActionCallback &registredActionCallback) override;

  bool handleAction(const char action) const override;

 protected:
  ScreenBase() = default;

 protected:
  mutable std::unordered_map<char, IScreen::RegistredActionCallback> actions_;
};

} // namespace screen
} // namespace cli
} // namespace doma
