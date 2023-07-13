#ifndef TASK_CLASS
#define TASK_CLASS

#include <string>
#include <ctime>

using namespace std;

/**
 * @brief Class representing a Task.
 */
class Task
{

private:
    static int nextId; /**< ID of the next task to be created. */
    string id;         /**< The ID of the task. */

protected:
    string title;       /**< The title of the task. */
    string description; /**< The description of the task. */
    int order;          /**< The order of the task. */
    tm *deadline;       /**< The deadline of the task. */
    tm *createdAt;      /**< The creation date of the task. */
    string type;        /**< The type of the task. */

public:
    /**
     * @brief Default constructor for Task.
     */
    Task();

    /**
     * @brief Constructs a Task object with a specified column.
     */
    Task(string type);

    /**
     * @brief Constructs a Task object with a specified column and title.
     * @param title The title of the task.
     */
    Task(string title, string type);

    /**
     * @brief Constructs a Task object with a specified column, title, and description.
     * @param title The title of the task.
     * @param description The description of the task.
     */
    Task(string title, string description, string type);

    /**
     * @brief Constructs a Task object with a specified column, title, description, and deadline.
     * @param title The title of the task.
     * @param description The description of the task.
     * @param deadline The deadline of the task.
     */
    Task(string title, string description, tm *deadline, string type);

    /**
     * @brief Destroys the Task object and frees the memory.
     */
    virtual ~Task();

    /**
     * @brief Get the ID of the task.
     * @return The ID of the task.
     */
    string getId();

    /**
     * @brief Get the type of the task.
     * @return The type of the task.
     */
    string getType();

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
     * @brief Get the creation date of the task.
     * @return The creation date of the task.
     */
    tm *getCreatedAt();

    /**
     * @brief Set the creation date of the task.
     */
    virtual void print() = 0;

    /**
     * @brief Get the next ID available.
     * @return The next ID available.
     */
    static string getNextId();

    /**
     * @brief Overload of the == operator.
     * @param task The task to compare.
     * @return True if the tasks are equal, false otherwise.
     */
    bool operator==(const Task &task) const;
};

#endif // TASK_CLASS