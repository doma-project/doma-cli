#include "cli/screen/Screen3_2.hpp"

#include <iostream>
#include <sstream>

#include "cli/screen/ActionHelper.hpp"

namespace doma {
namespace cli {
namespace screen {

Screen3_2::Screen3_2(model::Notebook &notebook) : notebook_(notebook) {}

void Screen3_2::printMenu() const {
  // TODO: add assert for notebooks should not be empty (size == 0)
  // TODO: if notebooks_.size() > 9 then we have a problem: after '9' follow ':', ';' chars

  Action noteIndex = '1';
  for (const auto& item : notebook_.getNotes()) {
    const auto& note = item.second;

    std::cout << noteIndex << ". " << note.getName() << std::endl;

    ++noteIndex;
  }

  std::cout << ActionHelper::GetActionString(Actions::kQuit) << std::endl;
}

model::Notebook &Screen3_2::getNotebook() const {
  return notebook_;
}

void Screen3_2::setNotebook(model::Notebook &notebook) {
  notebook_ = notebook;
}

} // namespace screen
} // namespace cli
} // namespace doma
