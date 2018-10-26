#include <functional>

#include "cli/screen/Action.hpp"

namespace doma {
namespace cli {
namespace screen {

class IScreen {
 public:
  using ActionHandlerType = std::function<void()>;

 public:
  virtual void registerActionHandler(const Action action,
                                     const ActionHandlerType &actionHandler) = 0;
  virtual void resetActionHandlers() = 0;

  virtual bool tryDoAction(const Action action) = 0;

  virtual void printMenu() const = 0;

 protected:
  IScreen() = default;
};

} // namespace screen
} // namespace cli
} // namespace doma
