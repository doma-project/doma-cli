#include "model/Notebook.hpp"

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

Notebook::Notebook(const NotebookId id, const std::string &name)
    : id_(id), name_(name), dateCreate_(ModelClock::now()) {}

NotebookId Notebook::getId() const {
  return id_;
}

std::string &Notebook::getName() {
  return name_;
}

std::map<NoteId, Note> &Notebook::getNotes() {
  return notes_;
}

std::map<TagId, Tag> &Notebook::getTags() {
  return tags_;
}

void Notebook::changeName(const std::string &name) {
  name_ = name;
  dateChange_ = ModelClock::now();
}

void Notebook::createNote(const NoteId noteId, const std::string &noteName,
                          const std::string &noteText) {
  notes_.emplace(noteId, Note(noteId, noteName, noteText));
  dateChange_ = ModelClock::now();
}

void Notebook::createTag(const TagId tagId, const std::string &tagName) {
  tags_.emplace(tagId, Tag(tagId, tagName));
  dateChange_ = ModelClock::now();
}

}  // namespace model
}  // namespace doma
