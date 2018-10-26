#include "cli/screen/Screen1_2.hpp"

#include <iostream>

namespace doma {
namespace cli {
namespace screen {

Screen1_2::Screen1_2(const model::Notebooks &notebooks, const IScreen &showNotebookScreen)
    : ScreenBase(), notebooks_(notebooks), showNotebookScreen_(showNotebookScreen) {
}

void Screen1_2::printMenu() const {
  // TODO: add assert for notebooks should not be empty (size == 0)

  Action notebookIndex = '1';
  for (const auto& item : notebooks_) {
    const auto& notebook = item.second;

    std::cout << notebookIndex << ". " << notebook.getName() << std::endl;

    ++notebookIndex;
  }

  std::cout << "Q. Quit" << std::endl;
}

} // namespace screen
} // namespace cli
} // namespace doma
