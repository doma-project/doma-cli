#pragma once

#include "cli/screen/Screen0.hpp"
#include "cli/screen/Screen1_1.hpp"
#include "cli/screen/Screen1_2.hpp"
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

  void setCurrentScreen(screen::IScreen& screen);

  int run();

 private:
  bool needCloseApp_;

  model::Notebooks notebooks_;

  screen::EmptyScreen emptyScreen_;
  screen::Screen0 screen0_;
  screen::Screen1_1 screen1_1_;
  screen::Screen1_2 screen1_2_;

  screen::IScreen *currentScreen_;

 private:
  void registerActionHandlersForScreens();

  void registerActionHandlersForEmptyScreen_();
  void registerActionHandlersForScreen0_();
  void registerActionHandlersForScreen1_1_();
  void registerActionHandlersForScreen1_2_();

  bool hasNotebooks() const;

  void save();
};

} // namespace cli
} // namespace doma
