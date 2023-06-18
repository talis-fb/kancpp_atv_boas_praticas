#ifndef MEMBER_CLASS_HPP
#define MEMBER_CLASS_HPP

#include <string>
#include "./User.hpp"

using namespace std;

/**
 * @brief The Member class represents a member in the system.
 *
 * A member is a type of user with an additional role.
 */
class Member : public User
{
private:
    string role; /**< The role of the member. */

public:
    /**
     * @brief Constructs a new Member object.
     *
     * @param id The ID of the member.
     * @param name The name of the member.
     * @param password The password of the member.
     * @param role The role of the member.
     */
    Member(const string &id, const string &name, const string &password, const string &role);

    /**
     * @brief Get the role of the member.
     *
     * @return The role of the member.
     */
    string getRole() const;
};

#endif
