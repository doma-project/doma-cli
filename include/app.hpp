#pragma once

#include "cli/screen/Screen0.hpp"
#include "cli/screen/Screen1_1.hpp"
#include "cli/screen/Screen1_2.hpp"
#include "cli/screen/Screen2_1.hpp"
#include "cli/screen/Screen3_2.hpp"
#include "cli/screen/EmptyScreen.hpp"
#include "model/Notebook.hpp"

namespace doma {
namespace cli {

class App final {
 public:
  using Action = cli::screen::Action;
  using Actions = cli::screen::Actions;

 public:
  explicit App(model::Notebooks& notebooks);

  App(const App&) = delete;
  App& operator=(const App&) = delete;

  void setCurrentScreen(screen::IScreen& screen);

  int run();

 private:
  bool needCloseApp_;

  model::Notebooks notebooks_;
  model::Notebook emptyNotebook_;

  screen::EmptyScreen emptyScreen_;
  screen::Screen0 screen0_;
  screen::Screen1_1 screen1_1_;
  screen::Screen1_2 screen1_2_;
  screen::Screen2_1 screen2_1_;
  screen::Screen3_2 screen3_2_;

  screen::IScreen *currentScreen_;

 private:
  void registerActionHandlersForScreens();

  void registerActionHandlersForEmptyScreen_();
  void registerActionHandlersForScreen0_();
  void registerActionHandlersForScreen1_1_();
  void registerActionHandlersForScreen1_2_();
  void registerActionHandlersForScreen2_1_();
  void registerActionHandlersForScreen3_2_();

  // TODO: what about more clear names?
  screen::IScreen &getScreen1();

  bool hasNotebooks() const;
  model::NotebookId getNextNotebookId() const;

  void save();
};

} // namespace cli
} // namespace doma
