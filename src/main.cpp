#include "app.hpp"
#include "model/Notebook.hpp"

int main() {
  // TODO temporarily, to remove when #5 will be fixed -->
  doma::model::Notebook firstNotebook(1, "The First Notebook");
  doma::model::Notebook secondNotebook(2, "The Second Notebook");
  doma::model::Notebook thirdNotebook(3, "The Third Notebook");

  doma::model::Notebooks notebooks {
      {firstNotebook.getId(), firstNotebook},
      {secondNotebook.getId(), secondNotebook},
      {thirdNotebook.getId(), thirdNotebook}
  };
  // <--

  doma::cli::App app(notebooks);
  return app.run();
}
