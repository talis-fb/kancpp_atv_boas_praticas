#include "../include/Board.h"

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
  delete this->createdAt;
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
  return *this->createdAt;
}

int Board::getColumnCount()
{
  return this->columns->getSize();
}

void Board::setCreatedAt()
{
  time_t currentTime = time(nullptr);
  tm *localTime = localtime(&currentTime);
  this->createdAt = localTime;
}

void Board::displayCreatedAt()
{
  char dateTime[100];
  std::strftime(dateTime, sizeof(dateTime), "%d/%m/%Y as %Hh%Mmin", createdAt);
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

  // system("clear||cls");
  cout << "Quadro Kanban (" << this->getName() << ")" << endl;

  for (int i = 0; i < sizeColumns; i++)
  {

    this->columns->get(i)->print();
    // cout << this->columns->get(i).getName() << " (Id: " << this->columns->get(i).getId() << ")" << endl;

    // std::cout << "Tarefas: " << std::endl;

    // vector<Task *> tasks = this->columns->get(i).getTasks();
    // vector<Task *>::iterator it;
    // for (std::size_t k = 0; k < tasks.size(); k++)
    // {
    //   cout << tasks.at(k)->getTitle() << endl;
    // }

    // cout << endl;
  }

  cout << endl;
}

Column Board::getColumnById(string id)
{
  int sizeColumns = this->columns->getSize();

  for (int i = 0; i < sizeColumns; i++)
  {
    if (this->columns->get(i)->getId() == id)
    {
      return *this->columns->get(i);
    }
  }

  return Column();
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