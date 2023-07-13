#include <iostream>
#include "../include/FeatureTask.h"
#include "../include/formatters/Date.h"

FeatureTask::FeatureTask() : Task()
{
    project = "";
}

FeatureTask::~FeatureTask()
{
}

FeatureTask::FeatureTask(std::string project) : Task("FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(std::string title, std::string project) : Task(title, "FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(std::string title, std::string description, std::string project) : Task(title, description, "FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(std::string title, std::string description, tm deadline, std::string project) : Task(title, description, deadline, "FEATURE")
{
    this->project = project;
}

std::string FeatureTask::getProject()
{
    return project;
}

void FeatureTask::print()
{
    tm date = getDeadline();
    string formattedDeadline = date.tm_year == 0 && date.tm_mon == 0 && date.tm_mday == 0 ? "Sem prazo" : formatDate(date);

    cout << "------------------------" << endl;
    cout << "ID: " << getId() << endl;
    cout << "Tipo: " << getType() << endl;
    cout << "Titulo: " << getTitle() << endl;
    cout << "Descricao: " << getDescription() << endl;
    cout << "Prazo: " << formattedDeadline << endl;
    cout << "Projeto: " << getProject() << endl;
    cout << "Ordem: " << getOrder() << endl;
    cout << "Criado em: " << formatDate(getCreatedAt()) << endl;
    cout << "------------------------" << endl;
}