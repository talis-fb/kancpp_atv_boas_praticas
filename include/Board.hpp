#ifndef BOARD_CLASS
#define BOARD_CLASS

#include <ctime>
#include <string>
#include <vector>

#include "./Column.hpp"
#include "./Task.hpp"

using namespace std;

/**
 * @brief Class that represents a board.
 */
class Board
{
private:
    string name;              /**< Name of the board */
    string description;       /**< Description of the board */
    vector<Column *> columns; /**< List of columns in the board */
    vector<Task *> backlog;   /**< List of tasks in the backlog */
    tm createdAt;             /**< Creation date and time of the board */

public:
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
     * @brief Add a column to the board.
     * @param column The column to be added.
     */
    void addColumn(Column *column);

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
    void moveTask(Task *task, Column *column);

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
};

#endif