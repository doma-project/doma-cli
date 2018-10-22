#pragma once

#include "cli/screen/ScreenBase.hpp"

namespace doma {
namespace cli {
namespace screen {

class EmptyScreen : public ScreenBase {
 public:
  EmptyScreen() = default;

  void printMenu() const override;
};

} // namespace screen
} // namespace cli
} // namespace doma
