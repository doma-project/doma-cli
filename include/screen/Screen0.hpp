#pragma once

#include "screen/ScreenBase.hpp"

namespace doma {
namespace cli {
namespace screen {

class Screen0 : public ScreenBase {
 public:
  Screen0() = default;

  void printMenu() const override;
};

} // namespace screen
} // namespace cli
} // namespace doma
