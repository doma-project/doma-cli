#include "app.hpp"

#include <iostream>

#include "screen/EmptyScreen.hpp"
#include "screen/Screen1_1.hpp"

namespace doma {
namespace cli {

int App::run() {
  screen::Screen1_1 screen1_1;
  screen::EmptyScreen emptyScreen;
  screen::IScreen *currentScreen = &screen1_1;

  auto needCloseApp = false;

  screen1_1.registerActionHandler('1', [&currentScreen, &emptyScreen]() {
    currentScreen = &emptyScreen;
  });
  screen1_1.registerActionHandler('q', [&needCloseApp]() {
    needCloseApp = true;
  });

  emptyScreen.registerActionHandler('q', [&currentScreen, &screen1_1]() {
    currentScreen = &screen1_1;
  });

  char action;
  do {
    currentScreen->printMenu();
    std::cin >> action;
    currentScreen->tryDoAction(action);
  } while (!needCloseApp);

  return 0;
}

} // namespace cli
} // namespace doma
