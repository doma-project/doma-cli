#include "app.hpp"

#include <iostream>

#include "screen/EmptyScreen.hpp"
#include "screen/Screen1_1.hpp"

namespace doma {
namespace cli {

App::App() : needCloseApp_(false), screen1_1_(), emptyScreen_(), currentScreen_(&screen1_1_) {
  screen1_1_.registerActionHandler('1', [this]() {
    currentScreen_ = &emptyScreen_;
  });
  screen1_1_.registerActionHandler('q', [this]() {
    needCloseApp_ = true;
  });

  emptyScreen_.registerActionHandler('q', [this]() {
    currentScreen_ = &screen1_1_;
  });
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

} // namespace cli
} // namespace doma
