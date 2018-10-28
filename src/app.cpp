#include "app.hpp"

#include <iostream>

#include "cli/screen/Action.hpp"

namespace doma {
namespace cli {

App::App(model::Notebooks& notebooks)
    : needCloseApp_(false),
      notebooks_(notebooks),
      emptyScreen_(),
      screen0_(),
      screen1_1_(),
      // TODO temporarily, to replace emptyScreen_ with screen2_1_ when #5 will be fixed
      screen1_2_(notebooks_, emptyScreen_),
      currentScreen_(getScreen1()) {
  registerActionHandlersForScreens();
}

void App::setCurrentScreen(screen::IScreen &screen) {
  currentScreen_ = screen;
}

int App::run() {
  Action action;
  do {
    currentScreen_.resetActionHandlers();

    // TODO optimize: we need to re-register again only for current screen, not for all
    registerActionHandlersForScreens();

    currentScreen_.printMenu();
    std::cin >> action;
    currentScreen_.tryDoAction(action);
  } while (!needCloseApp_);

  return 0;
}

void App::registerActionHandlersForScreens() {
  registerActionHandlersForEmptyScreen_();
  registerActionHandlersForScreen0_();
  registerActionHandlersForScreen1_1_();
  registerActionHandlersForScreen1_2_();
}

void App::registerActionHandlersForEmptyScreen_() {
  emptyScreen_.registerActionHandler(Actions::kQuit, [this]() {
    setCurrentScreen(getScreen1());
  });
}

void App::registerActionHandlersForScreen0_() {
  screen0_.registerActionHandler(Actions::kYes, [this]() {
    save();
    needCloseApp_ = true;
  });
  screen0_.registerActionHandler(Actions::kNo, [this]() {
    needCloseApp_ = true;
  });
}

void App::registerActionHandlersForScreen1_1_() {
  screen1_1_.registerActionHandler('1', [this]() {
    setCurrentScreen(emptyScreen_);
  });
  screen1_1_.registerActionHandler(Actions::kQuit, [this]() {
    setCurrentScreen(screen0_);
  });
}

void App::registerActionHandlersForScreen1_2_() {
  const Action notebookStartIndex = '1';
  for (auto i = 0u; i < notebooks_.size(); ++i) {
    // TODO: if notebooks_.size() > 9 then we have a problem: after '9' follow ':', ';' chars
    const Action action = notebookStartIndex + i;

    screen1_2_.registerActionHandler(action, [this]() {
      setCurrentScreen(emptyScreen_);
    });
  }

  screen1_2_.registerActionHandler(Actions::kQuit, [this]() {
    setCurrentScreen(screen0_);
  });
}

screen::IScreen &App::getScreen1() {
  if (hasNotebooks()) {
    return screen1_2_;
  } else {
    return screen1_1_;
  }
}

bool App::hasNotebooks() const {
  return !notebooks_.empty();
}

void App::save() {
  /* TODO #4 */
  std::cout << "Saved successfully! (nope)" << std::endl;
}

} // namespace cli
} // namespace doma
