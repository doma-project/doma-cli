#include "cli/screen/Screen0.hpp"
#include "cli/screen/Screen1_1.hpp"
#include "cli/screen/EmptyScreen.hpp"

namespace doma {
namespace cli {

class App final {
 public:
  App();

  int run();

 private:
  bool needCloseApp_;

  screen::Screen0 screen0_;
  screen::Screen1_1 screen1_1_;
  screen::EmptyScreen emptyScreen_;

  screen::IScreen *currentScreen_;
  
  void save();
};

} // namespace cli
} // namespace doma
