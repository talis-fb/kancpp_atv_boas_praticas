#ifndef TASK_CLASS
#define TASK_CLASS

#include <iostream>
#include <ctime>
#include <string>

#include "./Column.hpp"

using namespace std;

/**
 * @brief Class that represents a task.
 */
class Task
{
private:
    string id;                     /**< ID of the task */
    string title;                  /**< Title of the task */
    string description;            /**< Description of the task */
    int order;                     /**< Order of the task */
    tm deadline;                   /**< Deadline of the task */
    unordered_set<User> assignees; /**< Set of assignees for the task */
    unordered_set<string> labels;  /**< Set of labels for the task */
    Column *column;                /**< Column containing the task */
    tm createdAt;                  /**< Creation date and time of the task */

public:
    /**
     * @brief Get the ID of the task.
     * @return The ID of the task.
     */
    string getId();

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
    tm getDeadline();

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
     * @brief Get the assignees for the task.
     * @return The assignees for the task.
     */
    unordered_set<User> getAssignees();

    /**
     * @brief Add an assignee to the task.
     * @param user The user to be added as an assignee.
     * @return True if the assignee was added successfully, false otherwise.
     */
    bool addAssignee(User user);

    /**
     * @brief Remove an assignee from the task.
     * @param user The user to be removed as an assignee.
     * @return True if the assignee was removed successfully, false otherwise.
     */
    bool removeAssignee(User user);

    /**
     * @brief Get the labels for the task.
     * @return The labels for the task.
     */
    unordered_set<string> getLabels();

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