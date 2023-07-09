#ifndef FEATURE_TASK_CLASS
#define FEATURE_TASK_CLASS

#include "Task.h"

/**
 * @brief Class representing a FeatureTask, derived from Task.
 */
class FeatureTask : public Task
{
private:
    std::string project; /**< The project associated with the feature task. */

public:
    /**
     * @brief Constructs a FeatureTask object with a specified column and project.
     * @param column The column associated with the feature task.
     * @param project The project associated with the feature task.
     */
    FeatureTask(Column column, std::string project);

    /**
     * @brief Constructs a FeatureTask object with a specified column, title, and project.
     * @param column The column associated with the feature task.
     * @param title The title of the feature task.
     * @param project The project associated with the feature task.
     */
    FeatureTask(Column column, std::string title, std::string project);

    /**
     * @brief Constructs a FeatureTask object with a specified column, title, description, and project.
     * @param column The column associated with the feature task.
     * @param title The title of the feature task.
     * @param description The description of the feature task.
     * @param project The project associated with the feature task.
     */
    FeatureTask(Column column, std::string title, std::string description, std::string project);

    /**
     * @brief Constructs a FeatureTask object with a specified column, title, description, deadline, and project.
     * @param column The column associated with the feature task.
     * @param title The title of the feature task.
     * @param description The description of the feature task.
     * @param deadline The deadline of the feature task.
     * @param project The project associated with the feature task.
     */
    FeatureTask(Column column, std::string title, std::string description, tm deadline, std::string project);

    /**
     * @brief Get the project associated with the feature task.
     * @return The project associated with the feature task.
     */
    std::string getProject();
};

#endif // FEATURE_TASK_CLASS