#include "../include/BugTask.h"

BugTask::BugTask(Column column, int priority) : Task(column)
{
    this->priority = priority;
}

BugTask::BugTask(Column column, std::string title, int priority) : Task(column, title)
{
    this->priority = priority;
}

BugTask::BugTask(Column column, std::string title, std::string description, int priority) : Task(column, title, description)
{
    this->priority = priority;
}

BugTask::BugTask(Column column, std::string title, std::string description, tm deadline, int priority) : Task(column, title, description, deadline)
{
    this->priority = priority;
}

int BugTask::getPriority()
{
    return priority;
}
