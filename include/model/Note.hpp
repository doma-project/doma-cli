#pragma once

#include <set>
#include <string>

#include "model/ModelClock.hpp"
#include "model/NoteId.hpp"
#include "model/TagId.hpp"
#include "model/Timestamp.hpp"

namespace doma {
namespace model {

class Note {
 public:
  Note(const NoteId id, const std::string &name, const std::string &text);

  bool isDone() const;
  NoteId getId() const;
  Timestamp getDateCreate() const;
  Timestamp getDateChange() const;
  Timestamp getDateDone() const;
  std::string &getName();
  std::string &getText();
  std::set<TagId> &getTagIds();

  void changeName(const std::string &name);
  void changeText(const std::string &name);
  bool tryAddTag(const TagId tagId);
  bool tryRemoveTag(const TagId tagId);
  void done();

 private:
  bool isDone_;
  NoteId id_;
  std::string name_;
  std::string text_;
  std::set<TagId> tagIds_;
  Timestamp dateCreate_;
  Timestamp dateChange_;
  Timestamp dateDone_;
};

}  // namespace model
}  // namespace doma
