#include "screen/Screen1_1.hpp"
#include "screen/EmptyScreen.hpp"

namespace doma {
namespace cli {

class App final {
 public:
  App();

  int run();

 private:
  bool needCloseApp_;

  screen::Screen1_1 screen1_1_;
  screen::EmptyScreen emptyScreen_;

  screen::IScreen *currentScreen_;
};

} // namespace cli
} // namespace doma
