#include <iostream>

#include "../include/TestTask.h"
#include "../include/formatters/Date.h"

TestTask::TestTask() : Task("TEST") {}

TestTask::TestTask(const std::string &title, const std::string &description, tm deadline) : Task(title, description, deadline, "TEST") {}

TestTask::TestTask(const std::string &title, const std::string &description) : Task(title, description, "TEST") {}

TestTask::TestTask(const std::string &title) : Task(title, "TEST") {}

TestTask::TestTask(FeatureTask *feature) : Task("TEST")
{
    this->feature = feature;
}

TestTask::TestTask(const std::string& title, const std::string& description, tm deadline, FeatureTask *feature) : Task(title, description, deadline, "TEST")
{
    this->feature = feature;
}

TestTask::TestTask(const std::string& title, const std::string& description, FeatureTask *feature) : Task(title, description, "TEST")
{
    this->feature = feature;
}

TestTask::TestTask(const std::string& title, FeatureTask *feature) : Task(title, "TEST")
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
    tm date = getDeadline();
    string formattedDeadline = date.tm_year == 0 && date.tm_mon == 0 && date.tm_mday == 0 ? "Sem prazo" : formatDate(date);

    cout << "------------------------" << endl;
    cout << "ID: " << getId() << endl;
    cout << "Tipo: " << getType() << endl;
    cout << "Titulo: " << getTitle() << endl;
    cout << "Descricao: " << getDescription() << endl;
    cout << "Prazo: " << formattedDeadline << endl;
    if (getFeature() != nullptr)
    {
        cout << "Feature ID: " << getFeature()->getId() << endl;
        cout << "Feature Titulo: " << getFeature()->getTitle() << endl;
    }
    cout << "Ordem: " << getOrder() << endl;
    cout << "Criado em: " << formatDate(getCreatedAt()) << endl;
    cout << "------------------------" << endl;
}

void TestTask::serialize(std::ostream &stream)
{
    bool hasFeature = (feature != nullptr);

    stream.write(reinterpret_cast<const char *>(&hasFeature), sizeof(hasFeature));

    if (hasFeature)
    {
        feature->serialize(stream);
    }

    Task::serialize(stream);
}

void TestTask::deserialize(std::istream &stream)
{
    bool hasFeature;
    stream.read(reinterpret_cast<char *>(&hasFeature), sizeof(hasFeature));
    if (hasFeature)
    {
        feature = new FeatureTask();
        feature->deserialize(stream);
    }
    else
    {
        feature = nullptr;
    }

    Task::deserialize(stream);
}
