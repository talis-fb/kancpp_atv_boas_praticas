#ifndef TASK_CLASS
#define TASK_CLASS

#include <string>
#include <ctime>
#include "Column.h"

class Column;

/**
 * @brief Class representing a Task.
 */
class Task
{

private:
    std::string id; /**< The ID of the task. */

protected:
    Column *column;          /**< The column associated with the task. */
    std::string title;       /**< The title of the task. */
    std::string description; /**< The description of the task. */
    int order;               /**< The order of the task. */
    tm *deadline;            /**< The deadline of the task. */
    tm *createdAt;           /**< The creation date of the task. */

public:
    /**
     * @brief Constructs a Task object with a specified column.
     * @param column The column associated with the task.
     */
    Task(Column column);

    /**
     * @brief Constructs a Task object with a specified column and title.
     * @param column The column associated with the task.
     * @param title The title of the task.
     */
    Task(Column column, std::string title);

    /**
     * @brief Constructs a Task object with a specified column, title, and description.
     * @param column The column associated with the task.
     * @param title The title of the task.
     * @param description The description of the task.
     */
    Task(Column column, std::string title, std::string description);

    /**
     * @brief Constructs a Task object with a specified column, title, description, and deadline.
     * @param column The column associated with the task.
     * @param title The title of the task.
     * @param description The description of the task.
     * @param deadline The deadline of the task.
     */
    Task(Column column, std::string title, std::string description, tm deadline);

    /**
     * @brief Default constructor for Task.
     */
    Task();

    /**
     * @brief Get the ID of the task.
     * @return The ID of the task.
     */
    std::string getId();

    /**
     * @brief Get the column associated with the task.
     * @return The column associated with the task.
     */
    Column *getColumn();

    /**
     * @brief Get the title of the task.
     * @return The title of the task.
     */
    std::string getTitle();

    /**
     * @brief Set the title of the task.
     * @param title The new title of the task.
     */
    void setTitle(std::string title);

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
    std::string getDescription();

    /**
     * @brief Set the description of the task.
     * @param description The new description of the task.
     */
    void setDescription(std::string description);

    /**
     * @brief Get the creation date of the task.
     * @return The creation date of the task.
     */
    tm getCreatedAt();

    /**
     * @brief Set the creation date of the task.
     */
    virtual void print() const = 0;

    /**
     * @brief Overload of the == operator.
     * @param task The task to compare.
     * @return True if the tasks are equal, false otherwise.
     */
    bool operator==(const Task &task) const;
};

#endif // TASK_CLASS