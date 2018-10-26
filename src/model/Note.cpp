#include <set>
#include <string>

#include "model/Note.hpp"
#include "model/ModelClock.hpp"
#include "model/NoteId.hpp"
#include "model/TagId.hpp"
#include "model/Timestamp.hpp"

namespace doma {
namespace model {

Note::Note(const NoteId id, const std::string &name, const std::string &text)
    : id_(id), isDone_(false), name_(name), text_(text), dateCreate_(ModelClock::now()) {}

bool Note::isDone() const {
  return isDone_;
}

NoteId Note::getId() const {
  return id_;
}

Timestamp Note::getDateCreate() const {
  return dateCreate_;
}

Timestamp Note::getDateChange() const {
  return dateChange_;
}

Timestamp Note::getDateDone() const {
  return dateDone_;
}

std::string &Note::getName() {
  return name_;
}

std::string &Note::getText() {
  return text_;
}

std::set<TagId> &Note::getTagIds() {
  return tagIds_;
}

void Note::changeName(const std::string &name) {
  name_ = name;
  dateChange_ = ModelClock::now();
}

void Note::changeText(const std::string &text) {
  text_ = text;
  dateChange_ = ModelClock::now();
}

bool Note::addTag(const TagId tagId) {
  if (tagIds_.count(tagId)) {
    return false;
  }
  tagIds_.emplace(tagId);
  dateChange_ = ModelClock::now();
  return true;
}

bool Note::removeTag(const TagId tagId) {
  if (!tagIds_.count(tagId)) {
    return false;
  }
  tagIds_.erase(tagId);
  dateChange_ = ModelClock::now();
  return true;
}

void Note::done() {
  isDone_ = true;
  dateDone_ = ModelClock::now();
}

}  // namespace model
}  // namespace doma
