#pragma once

#include "cli/screen/ScreenBase.hpp"

namespace doma {
namespace cli {
namespace screen {

class Screen0 : public ScreenBase {
 public:
  Screen0() = default;

  void resetActionHandlers() override;
  void printMenu() const override;
};

} // namespace screen
} // namespace cli
} // namespace doma
