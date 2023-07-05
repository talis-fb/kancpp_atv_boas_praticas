// #include "../include/TADS/DoublyLinkedList/DoublyLinkedList.hpp"
#include "../include/Board.hpp"
#include "../include/User.hpp"
#include "../include/Task.hpp"
#include "../include/Admin.hpp"
#include "../include/Member.hpp"
#include "../include/Column.hpp"

class DouDoublyLinkedList;

Board::Board(string name, string description){
  this->name = name;
  this->description = description;

  this->columns = new DoublyLinkedList();
  this->backlog = new vector<Task>;
  
  setCreatedAt();
}

Board::Board(string name){
  this->name = name;
  this->description = "uninformed description";

  this->columns = new DoublyLinkedList();
  this->backlog = new vector<Task>;
  
  setCreatedAt();
}

void Board::setCreatedAt(){
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  this->createdAt = localTime;
}

void Board::displayCreatedAt(){
  char dateTime[100];
  std::strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", createdAt);
  std::cout << "Created at: " << dateTime << std::endl;
}