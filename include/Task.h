#ifndef TASK_CLASS
#define TASK_CLASS

#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "Column.h"
#include "TADS/Set/Set.h"

using namespace std;

class Column;

/**
 * @brief Class that represents a task.
 */
class Task
{
private:
    long int id;           /**< ID of the task */
    string title;          /**< Title of the task */
    string description;    /**< Description of the task */
    int order;             /**< Order of the task */
    tm *deadline;          /**< Deadline of the task */
    Set<string> labels;    /**< Set of labels for the task */
    Column *column;        /**< Column containing the task */
    tm *createdAt;         /**< Creation date and time of the task */
    static long int count; /** Add description*/

public:
    /**
     * @brief Constructs a new Task object.
     * @param id The ID of the task.
     * @param title The title of the task.
     * @param description The description of the task.
     * @param order The order of the task.
     * @param deadline The deadline of the task.
     * @param column The column containing the task.
     */
    Task(const string title, const string description, tm *deadline);

    /**
     * @brief Constructs a new Task object.
     * @param id The ID of the task.
     * @param title The title of the task.
     * @param description The description of the task.
     * @param order The order of the task.
     * @param column The column containing the task.
     */
    Task(const string title, const string description);

    /**
     * @brief Constructs a new Task object.
     * @param id The ID of the task.
     * @param title The title of the task.
     * @param column The column containing the task.
     */
    Task(const string title);

    /**
     * @brief Destroys the Task object and frees the memory.
     */
    ~Task();

    /**
     * @brief
     *
     */
    void setCreatedAt();

    /**
     * @brief
     *
     */
    void displayCreatedAt();

    /**
     * @brief Get the ID of the task.
     * @return The ID of the task.
     */
    int getId();

    /**
     * @brief Get the column containing the task.
     * @return The column containing the task.
     */
    Column *getColumn();

    /**
     * @brief Get the title of the task.
     * @return The title of the task.
     */
    string getTitle();

    /**
     * @brief Set the title of the task.
     * @param title The new title of the task.
     */
    void setTitle(string title);

    /**
     * @brief Set the order of the task.
     * @param order The new order of the task.
     */
    void setOrder(int order);

    /**
     * @brief Get the order of the task.
     * @return The order of the task.
     */
    int getOrder();

    /**
     * @brief Get the deadline of the task.
     * @return The deadline of the task.
     */
    tm *getDeadline();

    /**
     * @brief Set the deadline of the task.
     * @param date The new deadline of the task.
     */
    void setDeadline(tm date);

    /**
     * @brief Get the description of the task.
     * @return The description of the task.
     */
    string getDescription();

    /**
     * @brief Set the description of the task.
     * @param description The new description of the task.
     */
    void setDescription(string description);

    /**
     * @brief Get the labels for the task.
     * @return The labels for the task.
     */
    Set<string> getLabels();

    /**
     * @brief Add a label to the task.
     * @param label The label to be added.
     * @return True if the label was added successfully, false otherwise.
     */
    bool addLabel(string label);

    /**
     * @brief Remove a label from the task.
     * @param label The label to be removed.
     * @return True if the label was removed successfully, false otherwise.
     */
    bool removeLabel(string label);

    /**
     * @brief Get the creation date and time of the task.
     * @return The creation date and time of the task.
     */
    tm getCreatedAt();
};

#endif