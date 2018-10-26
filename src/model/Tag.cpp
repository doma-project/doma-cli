#include "model/Tag.hpp"

#include <string>

#include "model/TagId.hpp"

namespace doma {
namespace model {

Tag::Tag(const TagId id, const std::string &name) : id_(id), name_(name) {}

TagId Tag::getId() const {
  return id_;
}

std::string &Tag::getName() {
  return name_;
}

void Tag::changeName(const std::string &name) {
  name_ = name;
}

}  // namespace model
}  // namespace doma
