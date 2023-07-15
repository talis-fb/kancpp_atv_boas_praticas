#include "../include/Task.h"

int Task::nextId = 1;

Task::Task() {}

Task::Task(string type)
{
  this->id = Task::getNextId();
  this->type = type;
  this->title = "";
  this->description = "";
  this->order = 0;

  time_t now = time(0);
  this->createdAt = *localtime(&now);
}

Task::Task(string title, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->type = type;
  this->description = "";
  this->order = 0;

  std::time_t currentTime = std::time(nullptr);
  std::tm *timeInfo = std::localtime(&currentTime);

  deadline = *timeInfo;
  deadline.tm_year = 0;
  deadline.tm_mon = 0;
  deadline.tm_mday = 0;

  time_t now = time(0);
  this->createdAt = *localtime(&now);
}

Task::Task(string title, string description, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->description = description;
  this->type = type;
  this->order = 0;

  std::time_t currentTime = std::time(nullptr);
  std::tm *timeInfo = std::localtime(&currentTime);

  deadline = *timeInfo;
  deadline.tm_year = 0;
  deadline.tm_mon = 0;
  deadline.tm_mday = 0;

  time_t now = time(0);
  this->createdAt = *localtime(&now);
}

Task::Task(string title, string description, tm deadline, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->type = type;
  this->description = description;
  this->order = 0;
  this->deadline = deadline;

  time_t now = time(0);
  this->createdAt = *localtime(&now);
}

Task::~Task() {}

string Task::getId()
{
  return this->id;
}

string Task::getType()
{
  return this->type;
}

string Task::getTitle()
{
  return this->title;
}

void Task::setTitle(string title)
{
  this->title = title;
}

void Task::setOrder(int order)
{
  this->order = order;
}

int Task::getOrder()
{
  return this->order;
}

tm Task::getDeadline()
{
  return this->deadline;
}

void Task::setDeadline(tm date)
{
  this->deadline = date;
}

string Task::getDescription()
{
  return this->description;
}

void Task::setDescription(string description)
{
  this->description = description;
}

tm Task::getCreatedAt()
{
  return this->createdAt;
}

bool Task::operator==(const Task &task) const
{
  return this->id == task.id;
}

string Task::getNextId()
{
  return "T" + to_string(nextId++);
}

void Task::serialize(std::ostream &stream)
{
  size_t idLength = id.length();
  stream.write(reinterpret_cast<const char *>(&idLength), sizeof(idLength));
  stream.write(id.c_str(), idLength);

  size_t titleLength = title.length();
  stream.write(reinterpret_cast<const char *>(&titleLength), sizeof(titleLength));
  stream.write(title.c_str(), titleLength);

  size_t descriptionLength = description.length();
  stream.write(reinterpret_cast<const char *>(&descriptionLength), sizeof(descriptionLength));
  stream.write(description.c_str(), descriptionLength);

  stream.write(reinterpret_cast<const char *>(&order), sizeof(order));
  stream.write(reinterpret_cast<const char *>(&deadline), sizeof(deadline));
  stream.write(reinterpret_cast<const char *>(&createdAt), sizeof(createdAt));

  size_t typeLength = type.length();
  stream.write(reinterpret_cast<const char *>(&typeLength), sizeof(typeLength));
  stream.write(type.c_str(), typeLength);
}

void Task::deserialize(std::istream &stream)
{
  size_t idLength;
  stream.read(reinterpret_cast<char *>(&idLength), sizeof(idLength));
  id.resize(idLength);
  stream.read(&id[0], idLength);

  size_t titleLength;
  stream.read(reinterpret_cast<char *>(&titleLength), sizeof(titleLength));
  title.resize(titleLength);
  stream.read(&title[0], titleLength);

  stream.read(reinterpret_cast<char *>(&order), sizeof(order));
  stream.read(reinterpret_cast<char *>(&deadline), sizeof(deadline));
  stream.read(reinterpret_cast<char *>(&createdAt), sizeof(createdAt));

  size_t typeLength;
  stream.read(reinterpret_cast<char *>(&typeLength), sizeof(typeLength));
  type.resize(typeLength);
  stream.read(&type[0], typeLength);
}

void Task::printResume()
{
  cout << this->getTitle() << "(Id: " << this->getId() << ")\n";
}