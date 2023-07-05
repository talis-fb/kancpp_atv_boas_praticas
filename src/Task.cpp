#include "../include/Task.hpp"
#include "../include/Column.hpp"
#include "../include/Admin.hpp"
#include "../include/Member.hpp"
#include "../include/Board.hpp"

long int Task::count = 0;

Task::Task(const string title, const string description, tm* deadline){
  this->id = this->count++;
  this->title = title;
  this->description = description;
  // this->order = order;
  this->deadline = deadline;
}

Task::Task(const string title, const string description){
  this->id = this->count++;
  this->title = title;
  this->description = description;
  setCreatedAt();
}

Task::Task(const string title){
  this->id = this->count++;
  this->title = title;
  this->description = "";
  setCreatedAt();
}

Task::~Task(){
 //   
}

void Task::setCreatedAt(){
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  this->createdAt = localTime;
}

void Task::displayCreatedAt(){
  char dateTime[100];
  std::strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", createdAt);
  std::cout << "Created at: " << dateTime << std::endl;
}

int Task::getId(){
  return this->id;
}

string Task::getTitle(){
  return this->title;
}

Column* Task::getColumn(){
  return this->column;
}

void Task::setTitle(string title){
  this->title = title;
}