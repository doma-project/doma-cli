#pragma once

#include <iostream>

namespace doma {
namespace model {

using TagId = uint32_t;

class Tag {
 public:
  Tag(const TagId &id, const std::string &name);

  TagId getId() const;

  std::string &getName();

  void changeName(const std::string &name);

 private:
  TagId id_;
  std::string name_;
};

}  // namespace model
}  // namespace doma
