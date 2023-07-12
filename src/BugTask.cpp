#include <iostream>
#include "../include/BugTask.h"
#include "../include/formatters/Date.h"

BugTask::BugTask(Column *column, int priority) : Task(column, "BUG")
{
    this->priority = priority;
}

BugTask::BugTask(Column *column, std::string title, int priority) : Task(column, title, "BUG")
{
    this->priority = priority;
}

BugTask::BugTask(Column *column, std::string title, std::string description, int priority) : Task(column, title, description, "BUG")
{
    this->priority = priority;
}

BugTask::BugTask(Column *column, std::string title, std::string description, tm deadline, int priority) : Task(column, title, description, deadline, "BUG")
{
    this->priority = priority;
}

int BugTask::getPriority()
{
    return priority;
}

void BugTask::print()
{
    std::cout << "------------------------" << std::endl;
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "Tipo: " << getType() << std::endl;
    std::cout << "Coluna: " << getColumn()->getName() << std::endl;
    // std::cout << "Titulo: " << getTitle() << std::endl;
    // // show description if it exists
    // if (getDescription() != "")
    //     std::cout << "Descricao: " << getDescription() << std::endl;
    // if (getDeadline() != nullptr)
    //     std::cout << "Deadline: " << formatDate(*getDeadline()) << std::endl;
    // std::cout << "Prioridade: " << getPriority() << std::endl;
    // std::cout << "Ordem: " << getOrder() << std::endl;
    // std::cout << "Criado em: " << formatDate(*getCreatedAt()) << std::endl;
    // std::cout << "------------------------" << std::endl;
}