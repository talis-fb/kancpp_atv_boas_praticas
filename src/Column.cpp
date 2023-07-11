#include "../include/Column.h"

Column::Column(void){
    this->id = " ";
    this->name = " ";
    this->description = " ";
    this->order = -1;

    time_t currentTime = time(nullptr);
    this->createdAt = localtime(&currentTime);
}

Column::Column(const string id, const string name, const string description, const int order)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->order = order;

    time_t currentTime = time(nullptr);
    this->createdAt = localtime(&currentTime);
}

Column::Column(const string &id, const string &name, const string &description)
{
    this->id = id;
    this->name = name;
    this->description = description;
    this->order = 0;

    time_t currentTime = time(nullptr);
    this->createdAt = localtime(&currentTime);
}

Column::Column(const string &id, const string &name)
{
    this->id = id;
    this->name = name;
    this->description = "";
    this->order = 0;

    time_t currentTime = time(nullptr);
    this->createdAt = localtime(&currentTime);
}

Column::~Column()
{
    for (auto task : this->tasks)
    {
        delete &task;
    }
}

string Column::getId()
{
    return this->id;
}

string Column::getName()
{
    return this->name;
}

void Column::setName(string name)
{
    this->name = name;
}

int Column::getTaskCount()
{
    return this->tasks.size();
}

tm Column::getCreatedAt()
{
    return *this->createdAt;
}

string Column::getDescription()
{
    return this->description;
}

void Column::setDescription(string description)
{
    this->description = description;
}

int Column::getOrder()
{
    return this->order;
}

void Column::setOrder(int order)
{
    this->order = order;
}

vector<Task *> Column::getTasks()
{
    return this->tasks;
}

bool Column::addTask(Task *task)
{
    this->tasks.push_back(task);

    return true;
}

bool Column::removeTask(Task *task)
{

    for (auto i = this->tasks.begin(); i != this->tasks.end(); i++)
    {
        if (*i == task)
        {
            this->tasks.erase(i);
            return true;
        }
    }

    return false;
}

bool Column::operator==(const Column &column) const
{
    return this->id == column.id;
}