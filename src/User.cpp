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
}

User::~User(){
  //
}