#include "../include/Column.h"
#include <map>
#include <vector>
#include <string>

int Column::nextId = 1;

Column::Column() {}

Column::Column(const& string name, const& string description, int order)
{
    this->id = Column::getNextId();
    this->name = name;
    this->description = description;
    this->order = order;

    time_t currentTime = time(nullptr);
    this->createdAt = localtime(&currentTime);

    this->tasks = vector<Task *>();
}

Column::Column(const& string name, const& string description)
{
    this->id = Column::getNextId();
    this->name = name;
    this->description = description;
    this->order = 0;

    time_t currentTime = time(nullptr);
    this->createdAt = localtime(&currentTime);

    this->tasks = vector<Task *>();
}

Column::Column(const& string name)
{
    this->id = Column::getNextId();
    this->name = name;
    this->description = "";
    this->order = 0;

    time_t currentTime = time(nullptr);
    this->createdAt = localtime(&currentTime);

    this->tasks = vector<Task *>();
}

Column::~Column()
{
    for (auto task : this->tasks)
    {
        delete task;
    }
}

string Column::getId()
{
    return this->id;
}

string Column::getName()
{
    return this->name;
}

void Column::setName(const& string name)
{
    this->name = name;
}

int Column::getTaskCount()
{
    return this->tasks.size();
}

tm Column::getCreatedAt()
{
    return *this->createdAt;
}

string Column::getDescription()
{
    return this->description;
}

void Column::setDescription(const& string description)
{
    this->description = description;
}

int Column::getOrder()
{
    return this->order;
}

void Column::setOrder(int order)
{
    this->order = order;
}

vector<Task *> Column::getTasks()
{
    return this->tasks;
}

bool Column::addTask(Task *task)
{
    if (task == nullptr)
    {
        return false;
    }

    this->tasks.push_back(task);

    return true;
}

bool Column::removeTask(const Task *task)
{
    return std::any_of(this->tasks.begin(), this->tasks.end(), task);
}

bool Column::operator==(const Column &column) const
{
    return this->id == column.id;
}

void Column::print()
{

    cout << "+----------------------------\n";
    cout << "| " << this->name << " (Id: " << this->id << ")" << endl;
    cout << "+----------------------------\n";
    for (auto task : this->tasks)
    {
        task->printResume();
        cout << "-----------------------------\n";
    }
}

string Column::getNextId()
{
    return "C" + to_string(nextId++);
}

void Column::serialize(std::ostream &stream)
{
    size_t idLength = id.length();
    size_t nameLength = name.length();
    size_t descriptionLength = description.length();
    int taskCount = tasks.size();

    stream.write(reinterpret_cast<const char *>(&idLength), sizeof(idLength));
    stream.write(id.c_str(), idLength);

    stream.write(reinterpret_cast<const char *>(&nameLength), sizeof(nameLength));
    stream.write(name.c_str(), nameLength);

    stream.write(reinterpret_cast<const char *>(&descriptionLength), sizeof(descriptionLength));
    stream.write(description.c_str(), descriptionLength);

    stream.write(reinterpret_cast<const char *>(&order), sizeof(order));

    stream.write(reinterpret_cast<const char *>(&taskCount), sizeof(taskCount));

    for (Task *task : tasks)
    {
        if (FeatureTask *featureTask = dynamic_cast<FeatureTask *>(task))
        {
            int taskType = 1;
            stream.write(reinterpret_cast<const char *>(&taskType), sizeof(taskType));

            featureTask->serialize(stream);
        }
        else if (TestTask *testTask = dynamic_cast<TestTask *>(task))
        {
            int taskType = 2;
            stream.write(reinterpret_cast<const char *>(&taskType), sizeof(taskType));

            testTask->serialize(stream);
        }
        else if (BugTask *bugTask = dynamic_cast<BugTask *>(task))
        {
            int taskType = 3;
            stream.write(reinterpret_cast<const char *>(&taskType), sizeof(taskType));

            bugTask->serialize(stream);
        }
    }
}

void Column::deserialize(std::istream &stream)
{
    size_t idLength;
    size_t nameLength;
    size_t descriptionLength;
    // int order;
    int taskCount;

    stream.read(reinterpret_cast<char *>(&idLength), sizeof(idLength));
    id.resize(idLength);
    stream.read(&id[0], idLength);

    string idString = id.substr(0, id.length());
    int idInt = stoi(idString.substr(1, idString.length() - 1));

    nextId = max(idInt, nextId) + 1;

    stream.read(reinterpret_cast<char *>(&nameLength), sizeof(nameLength));
    name.resize(nameLength);
    stream.read(&name[0], nameLength);

    stream.read(reinterpret_cast<char *>(&descriptionLength), sizeof(descriptionLength));
    description.resize(descriptionLength);
    stream.read(&description[0], descriptionLength);

    stream.read(reinterpret_cast<char *>(&order), sizeof(order));
    // this->order = order;

    stream.read(reinterpret_cast<char *>(&taskCount), sizeof(taskCount));

    tasks.clear();

    for (int i = 0; i < taskCount; i++)
    {
        int taskType;
        stream.read(reinterpret_cast<char *>(&taskType), sizeof(taskType));

        Task *task = nullptr;

        switch (taskType)
        {
        case 1:
        {
            FeatureTask *featureTask = new FeatureTask();
            featureTask->deserialize(stream);
            task = featureTask;
            break;
        }
        case 2:
        {
            TestTask *testTask = new TestTask();
            testTask->deserialize(stream);
            task = testTask;
            break;
        }
        case 3:
        {
            BugTask *bugTask = new BugTask();
            bugTask->deserialize(stream);
            task = bugTask;
            break;
        }
        default:
            throw "Task type not found";
            break;
        }

        if (task)
        {
            tasks.push_back(task);
        }
    }
}

void Column::sortTasksBy(const& string property)
{
    vector<string> properties = {"id", "title", "description"};
    bool isPropertyValid = std::any_of(properties.begin(), properties.end(), property);

    if (!isPropertyValid)
    {
        throw "Invalid property";
    }

    Task *tasksArray[this->tasks.size()];

    int length = sizeof(tasksArray) / sizeof(tasksArray[0]);

    for (int i = 0; i < this->tasks.size(); i++)
    {
        tasksArray[i] = this->tasks[i];
    }

    function<bool(Task *, Task *)> compare;

    if (property == "id")
    {
        compare = [](Task *a, Task *b)
        {
            return a->getId() > b->getId();
        };
    }
    else if (property == "title")
    {
        compare = [](Task *a, Task *b)
        {
            return a->getTitle() > b->getTitle();
        };
    }
    else if (property == "description")
    {
        compare = [](Task *a, Task *b)
        {
            return a->getDescription() > b->getDescription();
        };
    }

    bubbleSort<Task *>(tasksArray, length, compare);

    this->tasks.clear();

    for (int i = 0; i < length; i++)
    {
        this->tasks.push_back(tasksArray[i]);
    }
}