#include "../include/Member.hpp"

Member::Member(const string &id, const string &name, const string &password, const string &role) : User(id, name, password)
{
    this->role = role;
}

Member::~Member()
{
    //
}

string Member::getRole() const
{
    return this->role;
}

bool Member::updateTask(Task task)
{
    //
}
