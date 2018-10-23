#pragma once

#include "Note.hpp"
#include "Tag.hpp"

#include <chrono>
#include <iostream>
#include <vector>

namespace doma {
namespace model {

using NotebookId = uint32_t;

class Notebook {
 public:
  Notebook(const NotebookId &id, const std::string &name);

  NotebookId getId() const;

  std::string &getName();

  std::vector<Note> &getNotes();

  std::vector<Tag> &getTags();

  void changeName(const std::string &name);

  void createNote(const std::string &note_name, const std::string &note_text);

  void createTag(const std::string &tag_name);

  void addTagToNote(const NoteId &note_id, const TagId &tag_id);

  bool removeTagFromNote(const NoteId &note_id, const TagId &tag_id);

 private:
  NotebookId id_;
  std::string name_;
  std::vector<Note> notes_;
  std::vector<Tag> tags_;
  Timestamp dateCreate_;
  Timestamp dateChange_;
};

}  // namespace model
}  // namespace doma
