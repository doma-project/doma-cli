#include "model/Note.hpp"

namespace doma {
namespace model {

Note::Note(const NoteId &id, const std::string &name, const std::string &text)
    : isDone_(false), id_(id), name_(name), text_(text), dateCreate_(ModelClock::now()) {}

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

std::vector<TagId> &Note::getTagIds() {
  return tagIds_;
}

bool Note::isDone() const {
  return isDone_;
}

void Note::changeName(const std::string &name) {
  name_ = name;
  dateChange_ = ModelClock::now();
}

void Note::changeText(const std::string &text) {
  text_ = text;
  dateChange_ = ModelClock::now();
}

void Note::addTag(const TagId &tagId) {
  tagIds_.push_back(tagId);
  dateChange_ = ModelClock::now();
}

bool Note::removeTag(const TagId &tagId) {
  for (auto i = 0u; i < tagIds_.size(); i++) {
    if (tagId == tagIds_[i]) {
      tagIds_.erase(tagIds_.begin() + i);
      dateChange_ = ModelClock::now();
      return true;
    }
  }
  return false;
}

void Note::done() {
  isDone_ = true;
  dateDone_ = ModelClock::now();
}

}  // namespace model
}  // namespace doma
