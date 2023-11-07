#include <iostream>
#include "../include/FeatureTask.h"
#include "../include/formatters/Date.h"

FeatureTask::FeatureTask() : Task()
{
}

FeatureTask::~FeatureTask()
{
}

FeatureTask::FeatureTask(const std::string& project) : Task("FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(const std::string& title, const std::string& project) : Task(title, "FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(const std::string& title, const std::string& description, const std::string& project) : Task(title, description, "FEATURE")
{
    this->project = project;
}

FeatureTask::FeatureTask(const std::string& title, const std::string& description, tm deadline, const std::string& project) : Task(title, description, deadline, "FEATURE")
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

void FeatureTask::serialize(std::ostream &stream)
{
    size_t projectLength = project.length();

    stream.write(reinterpret_cast<const char *>(&projectLength), sizeof(projectLength));
    stream.write(project.c_str(), projectLength);

    Task::serialize(stream);
}

void FeatureTask::deserialize(std::istream &stream)
{
    size_t projectLength;

    stream.read(reinterpret_cast<char *>(&projectLength), sizeof(projectLength));
    project.resize(projectLength);
    stream.read(&project[0], projectLength);

    Task::deserialize(stream);
}
