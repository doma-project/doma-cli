#include "app.hpp"
#include "model/Notebook.hpp"

int main() {
  doma::model::Notebooks notebooks;
  doma::cli::App app(notebooks);
  return app.run();
}
