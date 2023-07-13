#include <iostream>

#include "../include/TestTask.h"

TestTask::TestTask() : Task("TEST") {}

TestTask::TestTask(std::string title, std::string description, tm *deadline) : Task(title, description, deadline, "TEST") {}

TestTask::TestTask(std::string title, std::string description) : Task(title, description, "TEST") {}

TestTask::TestTask(std::string title) : Task(title, "TEST") {}

TestTask::TestTask(FeatureTask *feature) : Task("TEST")
{
    this->feature = feature;
}

TestTask::TestTask(std::string title, std::string description, tm *deadline, FeatureTask *feature) : Task(title, description, deadline, "TEST")
{
    this->feature = feature;
}

TestTask::TestTask(std::string title, std::string description, FeatureTask *feature) : Task(title, description, "TEST")
{
    this->feature = feature;
}

TestTask::TestTask(std::string title, FeatureTask *feature) : Task(title, "TEST")
{
    this->feature = feature;
}

TestTask::~TestTask()
{
    delete this->feature;
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