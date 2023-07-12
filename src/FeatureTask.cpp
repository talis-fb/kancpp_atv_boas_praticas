#include <iostream>
#include "../include/FeatureTask.h"

FeatureTask::FeatureTask() : Task()
{
    project = "";
}

FeatureTask::FeatureTask(Column *column, std::string project) : Task(column, "FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(Column *column, std::string title, std::string project) : Task(column, title, "FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(Column *column, std::string title, std::string description, std::string project) : Task(column, title, description, "FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(Column *column, std::string title, std::string description, tm deadline, std::string project) : Task(column, title, description, deadline, "FEATURE")
{
    this->project = project;
}

std::string FeatureTask::getProject()
{
    return project;
}

void FeatureTask::print()
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