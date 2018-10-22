#pragma once

#include "cli/screen/ScreenBase.hpp"

namespace doma {
namespace cli {
namespace screen {

class Screen1_1 : public ScreenBase {
 public:
  Screen1_1() = default;

  void printMenu() const override;
};

} // namespace screen
} // namespace cli
} // namespace doma
