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

BugTask::BugTask(string title, string description, tm deadline, int priority) : Task(title, description, deadline, "BUG")
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
    tm date = getDeadline();
    string formattedDeadline = date.tm_year == 0 && date.tm_mon == 0 && date.tm_mday == 0 ? "Sem prazo" : formatDate(date);

    cout << "------------------------" << endl;
    cout << "ID: " << getId() << endl;
    cout << "Tipo: " << getType() << endl;
    cout << "Titulo: " << getTitle() << endl;
    cout << "Descricao: " << getDescription() << endl;
    cout << "Prazo: " << formattedDeadline << endl;
    cout << "Prioridade: " << getPriority() << endl;
    cout << "Ordem: " << getOrder() << endl;
    cout << "Criado em: " << formatDate(getCreatedAt()) << endl;
    cout << "------------------------" << endl;
}