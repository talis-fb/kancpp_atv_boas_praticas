#ifndef BOARD_CLASS
#define BOARD_CLASS

#include <ctime>
#include <string>
#include <vector>

#include "Column.h"
#include "Task.h"
#include "utils/DoublyLinkedList/DoublyLinkedList.hpp"

using namespace std;

/**
 * @brief Class that represents a board.
 */
class Board
{
private:
    string name;                       /**< Name of the board */
    string description;                /**< Description of the board */
    DoublyLinkedList<Column> *columns; /**< List of columns in the board */
    vector<Task *> backlog;            /**< List of tasks in the backlog */
    tm createdAt;                      /**< Creation date and time of the board */

public:
    /**
     * @brief Constructs an empty Board object.
     */
    Board();

    /**
     * @brief Constructs a new Board object.
     * @param name The name of the board.
     * @param description The description of the board.
     */
    Board(const string& name, const string& description);

    /**
     * @brief Constructs a new Board object.
     * @param name The name of the board.
     */
    Board(const string& name);

    /**
     * @brief Destroys the Board object and all its columns and tasks.
     */
    ~Board();

    /**
     * @brief Get the name of the board.
     * @return The name of the board.
     */
    string getName();

    /**
     * @brief Get the description of the board.
     * @return The description of the board.
     */
    string getDescription();

    /**
     * @brief Get the creation date and time of the board.
     * @return The creation date and time of the board.
     */
    tm getCreatedAt();

    /**
     * @brief Get the number of columns in the board.
     * @return The number of columns in the board.
     */
    int getColumnCount();

    /**
     * @brief Set the Created At
     */
    void setCreatedAt();

    /**
     * @brief
     *
     */
    void displayCreatedAt();

    /**
     * @brief Add a column to the board.
     * @param column The column to be added.
     */
    void addColumn(Column *column);

    /**
     * @brief Get the columns of the board.
     * @return The columns of the board.
     */
    DoublyLinkedList<Column> *getColumns();

    /**
     * @brief Remove a column from the board.
     * @param column The column to be removed.
     */
    void removeColumn(Column *column);

    /**
     * @brief Move a task to a different column.
     * @param task The task to be moved.
     * @param column The target column.
     */
    void moveTask(Task *task, Column &column);

    /**
     * @brief Add a task to the backlog.
     * @param task The task to be added.
     */
    void addTaskToBacklog(Task *task);

    /**
     * @brief Remove a task from the backlog.
     * @param task The task to be removed.
     */
    void removeTaskFromBacklog(Task *task);

    /**
     * @brief Get the tasks in the backlog and in the columns.
     * @param id The id of the task to be searched.
     * @return Task* The task with the specified id.
     */
    Task *searchTaskById(const string& id);

    /**
     * @brief Get the Column By Id object
     * @param id The id of the column to be searched.
     * @return Column The column with the specified id.
     */
    Column *getColumnById(const string& id);

    /**
     * @brief Get the Column By Task object
     * @param task The task to be searched.
     * @return Column The column that contains the specified task.
     * @return nullptr If the task is not found.
     */
    Column *getColumnByTask(Task *task);

    /**
     * @brief Get the Task By Id object
     */
    void sortTask(const string& property);

    /**
     * @brief Print the board.
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
};

#endif