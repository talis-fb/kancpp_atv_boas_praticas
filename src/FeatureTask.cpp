#include "../include/FeatureTask.h"

FeatureTask::FeatureTask(Column column, std::string project) : Task(column)
{
    this->project = project;
}

FeatureTask::FeatureTask(Column column, std::string title, std::string project) : Task(column, title)
{
    this->project = project;
}

FeatureTask::FeatureTask(Column column, std::string title, std::string description, std::string project) : Task(column, title, description)
{
    this->project = project;
}

FeatureTask::FeatureTask(Column column, std::string title, std::string description, tm deadline, std::string project) : Task(column, title, description, deadline)
{
    this->project = project;
}

std::string FeatureTask::getProject()
{
    return project;
}
