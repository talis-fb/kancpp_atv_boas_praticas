#ifndef USER_CLASS
#define USER_CLASS

#include <ctime>
#include <string>

#include "./Task.hpp"

using namespace std;

/**
 * @brief Class representing a user.
 */
class User
{
private:
    string id;       /**< User ID. */
    string name;     /**< User name. */
    string password; /**< User password. */
    tm createdAt;    /**< User creation timestamp. */

public:
    /**
     * @brief Constructor for the User class.
     * @param id User ID.
     * @param name User name.
     * @param password User password.
     */
    User(const string &id, const string &name, const string &password);

    /**
     * @brief Get the user ID.
     * @return User ID.
     */
    string getId() const;

    /**
     * @brief Get the user password.
     * @return User password.
     */
    string getPassword() const;

    /**
     * @brief Get the user name.
     * @return User name.
     */
    string getName() const;

    /**
     * @brief Get the user creation timestamp.
     * @return User creation timestamp.
     */
    tm getCreatedAt() const;

    /**
     * @brief Updates a task for the user.
     *
     * This is a pure virtual function that needs to be implemented in derived classes.
     * It allows updating a task based on the provided Task object.
     *
     * @param task The task to be updated.
     * @return true if the task was updated successfully, false otherwise.
     */
    virtual bool updateTask(const Task &task) = 0;
};

#endif