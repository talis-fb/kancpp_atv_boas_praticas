#include "../include/Task.hpp"

long int Task::count = 0;

Task::Task(const string title, const string description, tm *deadline)
{
  this->id = this->count++;
  this->title = title;
  this->description = description;
  this->deadline = deadline;
  setCreatedAt();
}

Task::Task(const string title, const string description)
{
  this->id = this->count++;
  this->title = title;
  this->description = description;
  setCreatedAt();
}

Task::Task(const string title)
{
  this->id = this->count++;
  this->title = title;
  this->description = "";
  setCreatedAt();
}

Task::~Task()
{
  //
}

int Task::getId()
{
  return this->id;
}

Column *Task::getColumn()
{
  return this->column;
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

tm *Task::getDeadline()
{
  return this->deadline;
}

void Task::setDeadline(tm date)
{
  this->deadline = &date;
}

string Task::getDescription()
{
  return this->description;
}

void Task::setDescription(string description)
{
  this->description = description;
}

Set<User> Task::getAssignees()
{
  return this->assignees;
}

// bool Task::addAssignee(User &user)
// {

// }

// bool Task::removeAssignee(User *user)
// {

// }

Set<string> Task::getLabels()
{
  return this->labels;
}

bool Task::addLabel(string label)
{
  return this->labels.insert(label);
}

bool Task::removeLabel(string label)
{
  return this->labels.remove(label);
}

void Task::setCreatedAt()
{
  time_t currentTime = time(nullptr);
  tm *localTime = localtime(&currentTime);
  this->createdAt = localTime;
}

tm Task::getCreatedAt()
{
  return *this->createdAt;
}
