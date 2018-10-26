#pragma once

#include <map>
#include <set>
#include <string>

#include "model/Note.hpp"
#include "model/NoteId.hpp"
#include "model/NotebookId.hpp"
#include "model/Tag.hpp"
#include "model/TagId.hpp"

namespace doma {
namespace model {

class Notebook {
 public:
  Notebook(const NotebookId id, const std::string &name);

  NotebookId getId() const;
  std::string &getName();
  std::map<NoteId, Note> &getNotes();
  std::map<TagId, Tag> &getTags();

  void changeName(const std::string &name);
  void createNote(const NoteId noteId, const std::string &noteName,
                  const std::string &noteText);
  void createTag(const TagId tagId, const std::string &tagName);

 private:
  NotebookId id_;
  std::string name_;
  std::map<NoteId, Note> notes_;
  std::map<TagId, Tag> tags_;
  Timestamp dateCreate_;
  Timestamp dateChange_;
};

}  // namespace model
}  // namespace doma
