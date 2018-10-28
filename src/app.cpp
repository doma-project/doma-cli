#include "app.hpp"

#include <iostream>

#include "cli/screen/Action.hpp"

namespace doma {
namespace cli {

App::App(model::Notebooks& notebooks)
    : needCloseApp_(false),
      notebooks_(notebooks),
      emptyNotebook_(0, "Empty notebook"),
      emptyScreen_(),
      screen0_(),
      screen1_1_(),
      screen1_2_(notebooks_),
      screen2_1_(),
      screen3_2_(emptyNotebook_),
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
  registerActionHandlersForScreen3_2_();
}

void App::registerActionHandlersForEmptyScreen_() {
  emptyScreen_.registerActionHandler(Actions::kQuit, [this]() {
    setCurrentScreen(screen3_2_);
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
  Action notebookIndex = '1';
  for (auto &item : notebooks_) {
    auto &notebook = item.second;

    screen1_2_.registerActionHandler(notebookIndex, [this, &notebook]() {
      screen3_2_.setNotebook(notebook);
      setCurrentScreen(screen3_2_);
    });

    // TODO: if notebooks_.size() > 9 then we have a problem: after '9' follow ':', ';' chars
    ++notebookIndex;
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
    // TODO temporarily, to remove when #11 will be fixed -->
    newNotebook.createNote(1, screen2_1_.getName() + "'s 1st note", "1st note text");
    newNotebook.createNote(2, screen2_1_.getName() + "'s 2nd note", "2nd note text");
    newNotebook.createNote(3, screen2_1_.getName() + "'s 3rd note", "3rd note text");
    // <--

    notebooks_.emplace(std::make_pair(newNotebook.getId(), newNotebook));

    screen2_1_.resetName();
    setCurrentScreen(getScreen1());
  });

  screen2_1_.registerActionHandler(Actions::kCancel, [this]() {
    screen2_1_.resetName();
    setCurrentScreen(getScreen1());
  });
}

void App::registerActionHandlersForScreen3_2_() {
  const Action noteStartIndex = '1';
  for (auto i = 0u; i < screen3_2_.getNotebook().getNotes().size(); ++i) {
    // TODO: if notebooks_.size() > 9 then we have a problem: after '9' follow ':', ';' chars
    const Action action = noteStartIndex + i;

    screen3_2_.registerActionHandler(action, [this]() {
      setCurrentScreen(emptyScreen_);
    });
  }

  screen3_2_.registerActionHandler(Actions::kQuit, [this]() {
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
