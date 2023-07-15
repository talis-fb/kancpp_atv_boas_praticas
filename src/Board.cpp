#include "../include/Board.h"

Board::Board()
{
  this->columns = new DoublyLinkedList<Column>();
  this->backlog = std::vector<Task *>();
  setCreatedAt();
}

Board::Board(string name, string description)
{
  this->name = name;
  this->description = description;
  this->columns = new DoublyLinkedList<Column>();
  this->backlog = std::vector<Task *>();
  setCreatedAt();
}

Board::Board(string name)
{
  this->name = name;
  setCreatedAt();
}

Board::~Board()
{
  delete this->columns;
}

string Board::getName()
{
  return this->name;
}

string Board::getDescription()
{
  return this->description;
}

tm Board::getCreatedAt()
{
  return this->createdAt;
}

int Board::getColumnCount()
{
  return this->columns->getSize();
}

void Board::setCreatedAt()
{
  time_t currentTime = time(nullptr);
  tm *localTime = localtime(&currentTime);
  this->createdAt = *localTime;
}

void Board::displayCreatedAt()
{
  char dateTime[100];
  std::strftime(dateTime, sizeof(dateTime), "%d/%m/%Y as %Hh%Mmin", &createdAt);
  std::cout << "Criado em: " << dateTime << std::endl;
}

void Board::addColumn(Column *column)
{
  this->columns->insertAtTail(column);
}

void Board::removeColumn(Column *column)
{
  this->columns->remove(*column);
}

void Board::moveTask(Task *task, Column &column)
{
  for (int i = 0; i < this->columns->getSize(); i++)
  {
    vector<Task *> tasks = this->columns->get(i)->getTasks();
    for (std::size_t k = 0; k < tasks.size(); k++)
    {
      if (tasks.at(k)->getId() == task->getId())
      {
        this->columns->get(i)->removeTask(task);
        column.addTask(task);
      }
    }
  }
}

void Board::addTaskToBacklog(Task *task)
{
  this->backlog.push_back(task);
}

void Board::removeTaskFromBacklog(Task *task)
{
  for (std::size_t i = 0; i < this->backlog.size(); i++)
  {
    if (this->backlog[i]->getId() == task->getId())
    {
      this->backlog.erase(this->backlog.begin() + i);
    }
  }
}

void Board::print()
{
  int sizeColumns = this->columns->getSize();

  cout << this->getName() << endl;

  for (int i = 0; i < sizeColumns; i++)
  {

    this->columns->get(i)->print();
  }

  cout << endl;
}

Column *Board::getColumnById(string id)
{
  for (int i = 0; i < this->columns->getSize(); i++)
  {
    if (this->columns->get(i)->getId() == id)
    {
      return this->columns->get(i);
    }
  }

  return nullptr;
}

Column *Board::getColumnByTask(Task *task)
{
  for (int i = 0; i < this->columns->getSize(); i++)
  {
    vector<Task *> tasks = this->columns->get(i)->getTasks();
    for (std::size_t k = 0; k < tasks.size(); k++)
    {
      if (tasks.at(k)->getId() == task->getId())
      {
        return this->columns->get(i);
      }
    }
  }

  return nullptr;
}

Task *Board::searchTaskById(string id)
{
  for (int i = 0; i < this->columns->getSize(); i++)
  {
    vector<Task *> tasks = this->columns->get(i)->getTasks();
    for (std::size_t k = 0; k < tasks.size(); k++)
    {
      if (tasks.at(k)->getId() == id)
      {
        return tasks.at(k);
      }
    }
  }

  for (std::size_t i = 0; i < this->backlog.size(); i++)
  {
    if (this->backlog.at(i)->getId() == id)
    {
      return this->backlog.at(i);
    }
  }

  return nullptr;
}

void Board::serialize(std::ostream &stream)
{
  size_t nameLength = name.length();
  size_t descriptionLength = description.length();
  int columnCount = columns->getSize();

  stream.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength));
  stream.write(name.c_str(), nameLength);
  stream.write(reinterpret_cast<const char *>(&descriptionLength), sizeof(descriptionLength));
  stream.write(description.c_str(), descriptionLength);
  stream.write(reinterpret_cast<const char *>(&columnCount), sizeof(columnCount));

  for (int i = 0; i < columnCount; i++)
  {
    columns->get(i)->serialize(stream);
  }

  int backlogSize = backlog.size();

  stream.write(reinterpret_cast<const char *>(&backlogSize), sizeof(backlogSize));

  for (Task *task : backlog)
  {
    task->serialize(stream);
  }
}

void Board::deserialize(std::istream &stream)
{
  size_t nameLength;
  size_t descriptionLength;
  int columnCount;

  stream.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
  name.resize(nameLength);
  stream.read(&name[0], nameLength);

  stream.read(reinterpret_cast<char *>(&descriptionLength), sizeof(descriptionLength));
  description.resize(descriptionLength);
  stream.read(&description[0], descriptionLength);

  stream.read(reinterpret_cast<char *>(&columnCount), sizeof(columnCount));

  for (int i = 0; i < columnCount; i++)
  {
    Column *column = new Column();
    column->deserialize(stream);
    columns->insertAtTail(column);
  }
}

void Board::sortTask(string property)
{
  for (int i = 0; i < this->columns->getSize(); i++)
  {
    this->columns->get(i)->sortTasksBy(property);
  }
}