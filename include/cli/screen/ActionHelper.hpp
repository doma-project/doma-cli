#pragma once

#include <string>

#include "cli/screen/Action.hpp"

namespace doma {
namespace cli {
namespace screen {

class ActionHelper final {
 public:
  ActionHelper() = delete;

  static std::string GetActionString(const Actions action);
};

}  // namespace screen
}  // namespace cli
}  // namespace doma
