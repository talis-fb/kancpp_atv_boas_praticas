#include <iostream>
#include "../include/BugTask.h"
#include "../include/formatters/Date.h"

BugTask::BugTask(int priority) : Task("BUG")
{
    this->priority = priority;
}

BugTask::BugTask(string title, int priority) : Task(title, "BUG")
{
    this->priority = priority;
}

BugTask::BugTask(string title, string description, int priority) : Task(title, description, "BUG")
{
    this->priority = priority;
}

BugTask::BugTask(string title, string description, tm *deadline, int priority) : Task(title, description, deadline, "BUG")
{
    this->priority = priority;
}

BugTask::~BugTask()
{
}

int BugTask::getPriority()
{
    return priority;
}

void BugTask::print()
{
    cout << "------------------------" << endl;
    cout << "ID: " << getId() << endl;
    cout << "Tipo: " << getType() << endl;
    // cout << "Titulo: " << getTitle() << endl;
    // // show description if it exists
    // if (getDescription() != "")
    //     cout << "Descricao: " << getDescription() << endl;
    // if (getDeadline() != nullptr)
    //     cout << "Deadline: " << formatDate(*getDeadline()) << endl;
    // cout << "Prioridade: " << getPriority() << endl;
    // cout << "Ordem: " << getOrder() << endl;
    // cout << "Criado em: " << formatDate(*getCreatedAt()) << endl;
    // cout << "------------------------" << endl;
}