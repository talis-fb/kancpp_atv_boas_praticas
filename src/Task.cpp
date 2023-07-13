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
  this->deadline = nullptr;
  this->createdAt = nullptr;
}

Task::Task(string title, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->type = type;
  this->description = "";
  this->order = 0;
  this->deadline = nullptr;
  this->createdAt = nullptr;
}

Task::Task(string title, string description, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->type = type;
  this->description = description;
  this->order = 0;
  this->deadline = nullptr;
  this->createdAt = nullptr;
}

Task::Task(string title, string description, tm *deadline, string type)
{
  this->id = Task::getNextId();
  this->title = title;
  this->type = type;
  this->description = description;
  this->order = 0;
  this->deadline = deadline;
  this->createdAt = nullptr;
}

Task::~Task()
{
  delete this->deadline;
  delete this->createdAt;
}

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

tm *Task::getCreatedAt()
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