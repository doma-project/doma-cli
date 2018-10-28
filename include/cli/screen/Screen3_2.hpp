#pragma once

#include "cli/screen/ScreenBase.hpp"
#include "model/Notebook.hpp"

namespace doma {
namespace cli {
namespace screen {

class Screen3_2 : public ScreenBase {
 public:
  explicit Screen3_2(model::Notebook &notebook);

  void printMenu() const override;

  model::Notebook &getNotebook() const;
  void setNotebook(model::Notebook &notebook);

 private:
  model::Notebook &notebook_;
};

} // namespace screen
} // namespace cli
} // namespace doma
