#include <functional>

namespace doma {
namespace cli {
namespace screen {

class IScreen {
 public:
  using RegistredActionCallback = std::function<void()>;

 public:
  virtual void registerAction(const char action,
                              const RegistredActionCallback &registredActionCallback) = 0;
  virtual bool handleAction(const char action) = 0;

  virtual void printMenu() const = 0;

 protected:
  IScreen() = default;
};

} // namespace screen
} // namespace cli
} // namespace doma
