#ifndef NODE_CLASS
#define NODE_CLASS

#include <iostream>

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
    Node()
    {
        this->next(nullptr);
    }

    /**
     * @brief Constructor with a value parameter.
     *
     * @param val The value to be stored in the node.
     */
    Node(T val) : value(val), next(nullptr), previous(nullptr) {}

    /**
     * @brief Constructor with value, next, and previous parameters.
     *
     * @param val The value to be stored in the node.
     * @param n Pointer to the next node.
     * @param p Pointer to the previous node.
     */
    Node(T val, Node *n, Node *p) : value(val), next(n), previous(p) {}

    /**
     * @brief Destructor for the Node class that frees the memory.
     */
    ~Node()
    {
        //
    }

    /**
     * @brief Get the value stored in the node.
     *
     * @return The value stored in the node.
     */
    T getValue()
    {
        return this->value;
    }

    /**
     * @brief Set the value stored in the node.
     *
     * @param val The value to be set.
     */
    void setValue(T val)
    {
        this->value = val;
    }

    /**
     * @brief Get the next node.
     *
     * @return Pointer to the next node.
     */
    Node<T> *getNext()
    {
        return this->next;
    }

    /**
     * @brief Set the next node.
     *
     * @param n Pointer to the next node.
     */
    void setNext(Node<T> *n)
    {
        this->next = n;
    }
    /**
     * @brief Get the previous node.
     *
     * @return Pointer to the previous node.
     */
    Node<T> *getPrevious()
    {
        return this->previous;
    }

    /**
     * @brief Set the previous node.
     *
     * @param p Pointer to the previous node.
     */
    void setPrevious(Node<T> *p)
    {
        this->previous = p;
    }
};

#endif