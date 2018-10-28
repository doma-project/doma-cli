#include "cli/screen/ActionHelper.hpp"

namespace doma {
namespace cli {
namespace screen {

std::string ActionHelper::GetActionString(const Actions action) {
  switch (action) {
    case kQuit:
      return "Q. Quit";
    case kYes:
      return "Y. Yes";
    case kNo:
      return "N. No";
  }

  // TODO assert
  return "";
}

}  // namespace screen
}  // namespace cli
}  // namespace doma
