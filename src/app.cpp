#include "app.hpp"

#include <iostream>

namespace doma {
namespace cli {

App::App() : needCloseApp_(false), screen0_(), screen1_1_(), emptyScreen_(), currentScreen_(&screen1_1_) {
  registerActionHandlersForScreens();
}

int App::run() {
  char action;
  do {
    currentScreen_->printMenu();
    std::cin >> action;
    currentScreen_->tryDoAction(action);
  } while (!needCloseApp_);

  return 0;
}

void App::registerActionHandlersForScreens() {
  screen0_.registerActionHandler('y', [this]() {
    save();
    needCloseApp_ = true;
  });
  screen0_.registerActionHandler('n', [this]() {
    needCloseApp_ = true;
  });

  screen1_1_.registerActionHandler('1', [this]() {
    currentScreen_ = &emptyScreen_;
  });
  screen1_1_.registerActionHandler('q', [this]() {
    currentScreen_ = &screen0_;
  });

  emptyScreen_.registerActionHandler('q', [this]() {
    currentScreen_ = &screen1_1_;
  });
}

void App::save() {
  /* TODO #4 */
  std::cout << "Saved successfully! (nope)" << std::endl;
}

} // namespace cli
} // namespace doma
