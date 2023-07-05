#include "../include/Task.hpp"
#include "../include/Column.hpp"
#include "../include/Admin.hpp"
#include "../include/Member.hpp"
#include "../include/Board.hpp"

Task::Task(const string title, const string description, tm deadline){
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
}

Task::Task(const string title){
  this->id = this->count++;
  this->title = title;
  this->description = "";
}

Task::~Task(){
 //   
}