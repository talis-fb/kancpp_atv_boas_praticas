#ifndef NODE_CLASS
#define NODE_CLASS

#include <iostream>
#include "../../Task.hpp"

/**
 * @brief The Node class represents a node in a doubly linked list.
 *
 * It stores a value of generic type and maintains references to the next and previous nodes.
 *
 * @tparam T The type of the value stored in the node.
 */
template <class T>
class Node
{
private:
    T value;        /**< The value stored in the node. */
    Node *next;     /**< Pointer to the next node. */
    Node *previous; /**< Pointer to the previous node. */

public:
    /**
     * @brief Default constructor.
     */
    Node();

    /**
     * @brief Constructor with a value parameter.
     *
     * @param val The value to be stored in the node.
     */
    Node(T val);

    /**
     * @brief Constructor with value, next, and previous parameters.
     *
     * @param val The value to be stored in the node.
     * @param n Pointer to the next node.
     * @param p Pointer to the previous node.
     */
    Node(T val, Node *n, Node *p);

    /**
     * @brief Destructor for the Node class that frees the memory.
     */
    ~Node();

    /**
     * @brief Get the value stored in the node.
     *
     * @return The value stored in the node.
     */
    T getValue();

    /**
     * @brief Set the value stored in the node.
     *
     * @param val The value to be set.
     */
    void setValue(T val);

    /**
     * @brief Get the next node.
     *
     * @return Pointer to the next node.
     */
    Node *getNext();

    /**
     * @brief Set the next node.
     *
     * @param n Pointer to the next node.
     */
    void setNext(Node *n);

    /**
     * @brief Get the previous node.
     *
     * @return Pointer to the previous node.
     */
    Node *getPrevious();

    /**
     * @brief Set the previous node.
     *
     * @param p Pointer to the previous node.
     */
    void setPrevious(Node *p);
};

#endif