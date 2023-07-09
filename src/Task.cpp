#include "../include/Task.h"

Task::Task(Column column)
{
  this->column = &column;
  this->title = "";
  this->description = "";
  this->order = 0;
  this->deadline = nullptr;
  this->createdAt = nullptr;
}

Task::Task(Column column, std::string title)
{
  this->column = &column;
  this->title = title;
  this->description = "";
  this->order = 0;
  this->deadline = nullptr;
  this->createdAt = nullptr;
}

Task::Task(Column column, std::string title, std::string description)
{
  this->column = &column;
  this->title = title;
  this->description = description;
  this->order = 0;
  this->deadline = nullptr;
  this->createdAt = nullptr;
}

Task::Task(Column column, std::string title, std::string description, tm deadline)
{
  this->column = &column;
  this->title = title;
  this->description = description;
  this->order = 0;
  this->deadline = &deadline;
  this->createdAt = nullptr;
}

Task::Task() {}

std::string Task::getId()
{
  return this->id;
}

Column *Task::getColumn()
{
  return this->column;
}

std::string Task::getTitle()
{
  return this->title;
}

void Task::setTitle(std::string title)
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
  return *this->deadline;
}

void Task::setDeadline(tm date)
{
  this->deadline = &date;
}

std::string Task::getDescription()
{
  return this->description;
}

void Task::setDescription(std::string description)
{
  this->description = description;
}

tm Task::getCreatedAt()
{
  return *this->createdAt;
}

bool Task::operator==(const Task &task) const
{
  return this->id == task.id;
}