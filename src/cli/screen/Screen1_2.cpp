#include "cli/screen/Screen1_2.hpp"

#include <iostream>

#include "cli/screen/ActionHelper.hpp"

namespace doma {
namespace cli {
namespace screen {

Screen1_2::Screen1_2(const model::Notebooks &notebooks, const IScreen &showNotebookScreen)
    : ScreenBase(), notebooks_(notebooks), showNotebookScreen_(showNotebookScreen) {
}

void Screen1_2::printMenu() const {
  // TODO: add assert for notebooks should not be empty (size == 0)
  // TODO: if notebooks_.size() > 9 then we have a problem: after '9' follow ':', ';' chars

  Action notebookIndex = '1';
  for (const auto& item : notebooks_) {
    const auto& notebook = item.second;

    std::cout << notebookIndex << ". " << notebook.getName() << std::endl;

    ++notebookIndex;
  }

  std::cout << ActionHelper::GetActionString(Actions::kQuit) << std::endl;
}

} // namespace screen
} // namespace cli
} // namespace doma
