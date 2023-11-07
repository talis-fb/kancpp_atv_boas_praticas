#ifndef BUGTASK_CLASS
#define BUGTASK_CLASS

#include "Task.h"

/**
 * @brief Class representing a BugTask, derived from Task.
 */
class BugTask : public Task
{
private:
    int priority; /**< The priority of the bug task. */

public:
    /**
     * @brief Constructs a BugTask object with a specified column and project.
     */
    BugTask();

    /**
     * @brief Constructs a BugTask object with a specified column and priority.
     * @param priority The priority of the bug task.
     */
    BugTask(int priority);

    /**
     * @brief Constructs a BugTask object with a specified column, title, and priority.
     * @param title The title of the bug task.
     * @param priority The priority of the bug task.
     */
    BugTask(const std::string& title, int priority);

    /**
     * @brief Constructs a BugTask object with a specified column, title, description, and priority.
     * @param title The title of the bug task.
     * @param description The description of the bug task.
     * @param priority The priority of the bug task.
     */
    BugTask(const std::string& title, const std::string& description, int priority);

    /**
     * @brief Constructs a BugTask object with a specified column, title, description, deadline, and priority.
     * @param title The title of the bug task.
     * @param description The description of the bug task.
     * @param deadline The deadline of the bug task.
     * @param priority The priority of the bug task.
     */
    BugTask(const std::string& title, const std::string& description, tm deadline, int priority);

    /**
     * @brief Destroys the BugTask object.
     */
    ~BugTask();

    /**
     * @brief Get the priority of the bug task.
     * @return The priority of the bug task.
     */
    int getPriority();

    /**
     * @brief Set the priority of the bug task.
     * @param priority The new priority of the bug task.
     */
    void setPriority(int priority);

    /**
     * @brief Prints the bug task.
     */
    void print() override;

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
};

#endif // BUGTASK_CLASS