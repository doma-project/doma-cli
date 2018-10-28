#pragma once

#include "cli/screen/ScreenBase.hpp"
#include "model/Notebook.hpp"

namespace doma {
namespace cli {
namespace screen {

class Screen2_1 : public ScreenBase {
 public:
  Screen2_1();

  void printMenu() const override;

  const std::string &getName() const;
  void setName(std::string &&name);
  void resetName();

 private:
  std::string name_;

 private:
  std::string getFirstLine() const;
};

} // namespace screen
} // namespace cli
} // namespace doma
