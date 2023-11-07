#ifndef TEST_TASK_CLASS
#define TEST_TASK_CLASS

#include "Task.h"
#include "FeatureTask.h"

/**
 * @brief Class representing a TestTask, derived from Task.
 */
class TestTask : public Task
{

private:
    FeatureTask *feature = nullptr; /**< The feature associated with the test task. */

public:
    /**
     * @brief Constructs a TestTask object with a specified column and project.
     * @param project The project associated with the test task.
     */
    TestTask();

    /**
     * @brief Constructs a TestTask object with a specified column, title, description, deadline, and project.
     * @param title The title of the test task.
     * @param description The description of the test task.
     * @param deadline The deadline of the test task.
     * @param project The project associated with the test task.
     */
    TestTask(const std::string &title, const std::string &description, tm deadline);

    /**
     * @brief Constructs a TestTask object with a specified column, title, description, and project.
     * @param title The title of the test task.
     * @param description The description of the test task.
     * @param project The project associated with the test task.
     */
    TestTask(const std::string& title, const std::string& description);

    /**
     * @brief Constructs a TestTask object with a specified column, title, and project.
     * @param title The title of the test task.
     * @param project The project associated with the test task.
     */
    TestTask(const std::string& title);

    /**
     * @brief Constructs a TestTask object with a specified column and project.
     * @param feature The feature associated with the test task.
     */
    TestTask(FeatureTask *feature);

    /**
     * @brief Constructs a TestTask object with a specified column, title, description, deadline, and project.
     * @param title The title of the test task.
     * @param description The description of the test task.
     * @param deadline The deadline of the test task.
     * @param feature The feature associated with the test task.
     */
    TestTask(const std::string& title, const std::string& description, tm deadline, FeatureTask *feature);

    /**
     * @brief Constructs a TestTask object with a specified column, title, description, and project.
     * @param title The title of the test task.
     * @param description The description of the test task.
     * @param feature The feature associated with the test task.
     */
    TestTask(const std::string& title, const std::string& description, FeatureTask *feature);

    /**
     * @brief Constructs a TestTask object with a specified column, title, and project.
     * @param title The title of the test task.
     * @param feature The feature associated with the test task.
     */
    TestTask(const std::string& title, FeatureTask *feature);

    /**
     * @brief Destroys the TestTask object.
     */
    ~TestTask();

    /**
     * @brief Get the feature associated with the test task.
     * @return The feature associated with the test task.
     */
    FeatureTask *getFeature();

    /**
     * @brief Prints the test task.
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

#endif // TEST_TASK_CLASS