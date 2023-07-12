#include <iostream>

#include "../include/TestTask.h"

TestTask::TestTask(Column *column) : Task(column, "TEST") {}

TestTask::TestTask(Column *column, std::string title, std::string description, tm deadline) : Task(column, title, description, deadline, "TEST") {}

TestTask::TestTask(Column *column, std::string title, std::string description) : Task(column, title, description, "TEST") {}

TestTask::TestTask(Column *column, std::string title) : Task(column, title, "TEST") {}

TestTask::TestTask(Column *column, FeatureTask *feature) : Task(column, "TEST")
{
    this->feature = feature;
}

TestTask::TestTask(Column *column, std::string title, std::string description, tm deadline, FeatureTask *feature) : Task(column, title, description, deadline, "TEST")
{
    this->feature = feature;
}

TestTask::TestTask(Column *column, std::string title, std::string description, FeatureTask *feature) : Task(column, title, description, "TEST")
{
    this->feature = feature;
}

TestTask::TestTask(Column *column, std::string title, FeatureTask *feature) : Task(column, title, "TEST")
{
    this->feature = feature;
}

FeatureTask *TestTask::getFeature()
{
    return feature;
}

void TestTask::print()
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