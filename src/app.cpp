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
      screen1_2_(notebooks_),
      screen2_1_(),
      currentScreen_(&getScreen1()) {
  registerActionHandlersForScreens();
}

void App::setCurrentScreen(screen::IScreen &screen) {
  currentScreen_ = &screen;
}

int App::run() {
  Action action;
  do {
    currentScreen_->resetActionHandlers();

    // TODO optimize: we need to re-register again only for current screen, not for all
    registerActionHandlersForScreens();

    currentScreen_->printMenu();
    std::cin >> action;
    currentScreen_->tryDoAction(action);
  } while (!needCloseApp_);

  return 0;
}

void App::registerActionHandlersForScreens() {
  registerActionHandlersForEmptyScreen_();
  registerActionHandlersForScreen0_();
  registerActionHandlersForScreen1_1_();
  registerActionHandlersForScreen1_2_();
  registerActionHandlersForScreen2_1_();
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
    setCurrentScreen(screen2_1_);
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

void App::registerActionHandlersForScreen2_1_() {
  screen2_1_.registerActionHandler('1', [this]() {
    std::cout << "Name:" << std::endl;
    std::string name;
    std::cin >> name;

    screen2_1_.setName(std::move(name));
  });

  screen2_1_.registerActionHandler(Actions::kOk, [this]() {
    if (screen2_1_.getName().empty()) {
      return;
    }

    model::Notebook newNotebook(getNextNotebookId(), screen2_1_.getName());
    notebooks_.emplace(std::make_pair(newNotebook.getId(), newNotebook));

    screen2_1_.resetName();
    // TODO temporarily, to replace emptyScreen_ with screen3_1_ when #10 will be fixed
    setCurrentScreen(getScreen1());
  });

  screen2_1_.registerActionHandler(Actions::kCancel, [this]() {
    screen2_1_.resetName();
    setCurrentScreen(getScreen1());
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

model::NotebookId App::getNextNotebookId() const {
  if (notebooks_.empty()) {
    return 1;
  }

  const auto lastNotebookId = notebooks_.rbegin()->first;
  return lastNotebookId + 1;
}

void App::save() {
  /* TODO #4 */
  std::cout << "Saved successfully! (nope)" << std::endl;
}

} // namespace cli
} // namespace doma
