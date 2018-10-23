#include "model/Notebook.hpp"

namespace doma {
namespace model {

Notebook::Notebook(const NotebookId &id, const std::string &name)
    : id_(id), name_(name), dateCreate_(ModelClock::now()) {}

NotebookId Notebook::getId() const {
  return id_;
}

std::string &Notebook::getName() {
  return name_;
}

std::vector<Note> &Notebook::getNotes() {
  return notes_;
}

std::vector<Tag> &Notebook::getTags() {
  return tags_;
}

void Notebook::changeName(const std::string &name) {
  name_ = name;
  dateChange_ = ModelClock::now();
}

void Notebook::createNote(const std::string &note_name,
                          const std::string &note_text) {
  notes_.emplace_back(note_name, note_text);
  dateChange_ = ModelClock::now();
}

void Notebook::createTag(const std::string &tag_name) {
  tags_.emplace_back(tag_name);
  dateChange_ = ModelClock::now();
}

void Notebook::addTagToNote(const NoteId &note_id, const TagId &tag_id) {
  notes_[note_id].addTag(tag_id);
  dateChange_ = ModelClock::now();
}

bool Notebook::removeTagFromNote(const NoteId &note_id, const TagId &tag_id) {
  dateChange_ = ModelClock::now();
  return notes_[note_id].removeTag(tag_id);
}

}  // namespace model
}  // namespace doma
