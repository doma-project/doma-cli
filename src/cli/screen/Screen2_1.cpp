#include "cli/screen/Screen2_1.hpp"

#include <iostream>
#include <sstream>

#include "cli/screen/ActionHelper.hpp"

namespace doma {
namespace cli {
namespace screen {

Screen2_1::Screen2_1() : name_() {}

void Screen2_1::printMenu() const {
  std::cout << getFirstLine() << std::endl;
  if (!name_.empty()) {
    std::cout << ActionHelper::GetActionString(Actions::kOk) << std::endl;
  }
  std::cout << ActionHelper::GetActionString(Actions::kCancel) << std::endl;
}

std::string Screen2_1::getFirstLine() const {
  if (name_.empty()) {
    return "1. Type a name";
  }

  std::ostringstream ss;
  ss << "1. Change the stored name: '" << name_ << "'";
  return ss.str();
}

const std::string &Screen2_1::getName() const {
  return name_;
}

void Screen2_1::setName(std::string &&name) {
  name_ = std::move(name);
}

void Screen2_1::resetName() {
  name_.clear();
}

} // namespace screen
} // namespace cli
} // namespace doma
