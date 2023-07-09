#include <iostream>

#include "../include/TestTask.h"

TestTask::TestTask(Column column, FeatureTask *feature) : Task(column)
{
    this->feature = feature;
}

TestTask::TestTask(Column column, std::string title, std::string description, tm deadline, FeatureTask *feature) : Task(column, title, description, deadline)
{
    this->feature = feature;
}

TestTask::TestTask(Column column, std::string title, std::string description, FeatureTask *feature) : Task(column, title, description)
{
    this->feature = feature;
}

TestTask::TestTask(Column column, std::string title, FeatureTask *feature) : Task(column, title)
{
    this->feature = feature;
}

FeatureTask *TestTask::getFeature()
{
    return feature;
}

void TestTask::print()
{
    std::cout << "TestTask" << std::endl;
}