#pragma once

#include "cli/screen/ScreenBase.hpp"
#include "model/Notebook.hpp"

namespace doma {
namespace cli {
namespace screen {

class Screen1_2 : public ScreenBase {
 public:
  explicit Screen1_2(const model::Notebooks &notebooks);

  void printMenu() const override;

 private:
  const model::Notebooks &notebooks_;
};

} // namespace screen
} // namespace cli
} // namespace doma
