#pragma once

namespace doma {
namespace cli {
namespace screen {

using Action = char;

enum Actions : Action {
  kQuit = 'q',
  kYes = 'y',
  kNo = 'n',
  kOk = 'o',
  kCancel = 'c'
};

}  // namespace screen
}  // namespace cli
}  // namespace doma
