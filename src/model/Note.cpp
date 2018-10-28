#include "model/Note.hpp"

#include <set>
#include <string>

#include "model/ModelClock.hpp"
#include "model/NoteId.hpp"
#include "model/TagId.hpp"
#include "model/Timestamp.hpp"

namespace doma {
namespace model {

Note::Note(const NoteId id, const std::string &name, const std::string &text)
    : isDone_(false),
      id_(id),
      name_(name),
      text_(text),
      tagIds_(),
      dateCreate_(ModelClock::now()),
      dateChange_(),
      dateDone_() {}

bool Note::isDone() const {
  return isDone_;
}

NoteId Note::getId() const {
  return id_;
}

const Timestamp Note::getDateCreate() const {
  return dateCreate_;
}

const Timestamp Note::getDateChange() const {
  return dateChange_;
}

const Timestamp Note::getDateDone() const {
  return dateDone_;
}

const std::string &Note::getName() const {
  return name_;
}

const std::string &Note::getText() const {
  return text_;
}

const std::set<TagId> &Note::getTagIds() const {
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

bool Note::tryAddTag(const TagId tagId) {
  if (tagIds_.count(tagId)) {
    return false;
  }
  tagIds_.emplace(tagId);
  dateChange_ = ModelClock::now();
  return true;
}

bool Note::tryRemoveTag(const TagId tagId) {
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
