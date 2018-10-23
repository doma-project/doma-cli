#pragma once

#include <chrono>
#include <iostream>
#include <vector>

namespace doma {
namespace model {

using ModelClock = std::chrono::system_clock;
using Timestamp = ModelClock::time_point;
using NoteId = uint32_t;
using TagId = uint32_t;

class Note {
 public:
  Note(const NoteId &id, const std::string &name, const std::string &text);

  bool isDone() const;

  NoteId getId() const;

  Timestamp getDateCreate() const;

  Timestamp getDateChange() const;

  Timestamp getDateDone() const;

  std::string &getName();

  std::string &getText();

  std::vector<TagId> &getTagIds();

  void changeName(const std::string &name);

  void changeText(const std::string &name);

  void addTag(const TagId &tagId);

  bool removeTag(const TagId &tagId);

  void done();

 private:
  bool isDone_;
  NoteId id_;
  std::string name_;
  std::string text_;
  std::vector<TagId> tagIds_;
  Timestamp dateCreate_;
  Timestamp dateChange_;
  Timestamp dateDone_;
};

}  // namespace model
}  // namespace doma
