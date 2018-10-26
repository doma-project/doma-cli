#pragma once

#include "cli/screen/ScreenBase.hpp"
#include "model/Notebook.hpp"

namespace doma {
namespace cli {
namespace screen {

class Screen1_2 : public ScreenBase {
 public:
  Screen1_2(const model::Notebooks &notebooks, const IScreen& showNotebookScreen);

  void printMenu() const override;

 private:
  const model::Notebooks &notebooks_;

  const IScreen& showNotebookScreen_;
};

} // namespace screen
} // namespace cli
} // namespace doma
