#include <iostream>
#include "../include/BugTask.h"
#include "../include/formatters/Date.h"

BugTask::BugTask() : Task("BUG")
{
    this->priority = 0;
}

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

void BugTask::setPriority(int priority)
{
    this->priority = priority;
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

void BugTask::serialize(std::ostream &stream)
{
    stream.write(reinterpret_cast<const char *>(&priority), sizeof(priority));

    Task::serialize(stream);
}

void BugTask::deserialize(std::istream &stream)
{
    stream.read(reinterpret_cast<char *>(&priority), sizeof(priority));

    Task::deserialize(stream);
}
