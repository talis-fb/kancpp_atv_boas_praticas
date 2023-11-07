#ifndef COLUMN_CLASS
#define COLUMN_CLASS

#include <ctime>
#include <string>
#include <vector>
#include <iostream>

#include "Task.h"
#include "BugTask.h"
#include "FeatureTask.h"
#include "TestTask.h"
#include "utils/Sort.hpp"

class Task;

using namespace std;

/**
 * @brief Class that represents a column.
 */
class Column
{
private:
    static int nextId;    /**< ID of the next column to be created */
    string id;            /**< ID of the column */
    string name;          /**< Name of the column */
    tm *createdAt;        /**< Creation date and time of the column */
    string description;   /**< Description of the column */
    int order;            /**< Order of the column */
    vector<Task *> tasks; /**< List of tasks in the column */

public:
    /**
     * @brief Construct a new Column object
     *
     */
    Column();

    /**
     * @brief Constructs a new Column object.
     * @param name The name of the column.
     * @param description The description of the column.
     * @param order The order of the column.
     */
    Column(const string& name, const string& description, int order);

    /**
     * @brief Constructs a new Column object.
     * @param name The name of the column.
     * @param description The description of the column.
     */
    Column(const string& name, const string& description);

    /**
     * @brief Constructs a new Column object.
     * @param name The name of the column.
     */
    Column(const string& name);

    /**
     * @brief Destroys the Column object and all its tasks.
     */
    ~Column();

    /**
     * @brief Get the ID of the column.
     * @return The ID of the column.
     */
    string getId();

    /**
     * @brief Get the name of the column.
     * @return The name of the column.
     */
    string getName();

    /**
     * @brief Set the name of the column.
     * @param name The new name of the column.
     */
    void setName(const string& name);

    /**
     * @brief Get the number of tasks in the column.
     * @return The number of tasks in the column.
     */
    int getTaskCount();

    /**
     * @brief Get the creation date and time of the column.
     * @return The creation date and time of the column.
     */
    tm getCreatedAt();

    /**
     * @brief Get the description of the column.
     * @return The description of the column.
     */
    string getDescription();

    /**
     * @brief Set the description of the column.
     * @param description The new description of the column.
     */
    void setDescription(const string& description);

    /**
     * @brief Get the order of the column.
     * @return The order of the column.
     */
    int getOrder();

    /**
     * @brief Set the order of the column.
     * @param order The new order of the column.
     */
    void setOrder(int order);

    /**
     * @brief Get the tasks in the column.
     * @return The tasks in the column.
     */
    vector<Task *> getTasks();

    /**
     * @brief Add a task to the column.
     * @param task The task to be added.
     * @return True if the task was added successfully, false otherwise.
     */
    bool addTask(Task *task);

    /**
     * @brief Remove a task from the column.
     * @param task The task to be removed.
     * @return True if the task was removed successfully, false otherwise.
     */
    bool removeTask(const Task *task);

    /**
     * @brief Overload of the == operator for the Column class.
     * @param other The column to be compared.
     * @return True if the columns are equal, false otherwise.
     */
    bool operator==(const Column &column) const;

    /**
     * @brief Overload of the != operator for the Column class.
     * @return The next ID available.
     */
    static string getNextId();
    /**
     * @brief Prints the column.
     */
    void print();

    /**
     * @brief Serialize the board.
     * @param stream The stream to be serialized.
     */
    void serialize(std::ostream &stream);

    /**
     * @brief Deserialize the board.
     * @param stream The stream to be deserialized.
     */
    void deserialize(std::istream &stream);

    /**
     * @brief Sort the tasks by a given property.
     * @param property The property to be sorted by.
     */
    void sortTasksBy(const string& property);
};

#endif