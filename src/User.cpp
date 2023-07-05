#include "../include/User.hpp"
#include "../include/Task.hpp"
#include "../include/Admin.hpp"
#include "../include/Member.hpp"
#include "../include/Board.hpp"
#include "../include/Column.hpp"

User::User(const string id, const string name, const string password){
  this->id = id;
  this->name = name;
  this->password = password;
  setCreatedAt();
}

User::~User(){
  delete createdAt;
}

string User::getId() const{
  return this->id;
}

string User::getName() const{
  return this->name;
}

string User::getPassword() const{
  return this->password;
}

tm* User::getCreatedAt() const{
  return this->createdAt;
}

void User::setCreatedAt(){
  time_t currentTime = time(nullptr);
  tm* localTime = localtime(&currentTime);
  this->createdAt = localTime;
}

void User::displayCreatedAt(){
  char dateTime[100];
  std::strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", createdAt);
  std::cout << "Created at: " << dateTime << std::endl;
}