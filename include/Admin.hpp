#ifndef ADMIN_CLASS_HPP
#define ADMIN_CLASS_HPP

#include "./User.hpp"

/**
 * @brief The Admin class represents an administrator in the system.
 *
 * An admin is a type of user with additional privileges.
 */
class Admin : public User
{
public:
    /**
     * @brief Constructs a new Admin object.
     *
     * @param id The ID of the admin.
     * @param name The name of the admin.
     * @param password The password of the admin.
     * @param role The role of the admin.
     */
    Admin(const string &id, const string &name, const string &password, const string &role);

    /**
     * @brief Destroys the Admin object and frees the memory.
     */
    ~Admin();

    /**
     * @brief Promotes a user to admin status.
     *
     * @param user The user to be promoted.
     */
    void promoteToAdmin(User &user);
};

#endif