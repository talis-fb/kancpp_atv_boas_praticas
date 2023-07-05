#ifndef DOUBLY_LINKED_LIST_CLASS
#define DOUBLY_LINKED_LIST_CLASS

#include "./ANode.hpp"
#include "../../Task.hpp"

/**
 * @brief The DoublyLinkedList class represents a doubly linked list.
 *
 * It allows for efficient insertion and removal of elements at both the head and tail of the list.
 */
class DoublyLinkedList
{
private:
    Node<Task> *head; /**< The head (first node) of the list. */
    Node<Task> *tail; /**< The tail (last node) of the list. */
    int size;         /**< The number of elements in the list. */

public:
    /**
     * @brief Constructs an empty DoublyLinkedList object.
     */
    DoublyLinkedList();

    /**
     * @brief Destroys the DoublyLinkedList object and frees the memory.
     */
    ~DoublyLinkedList();

    /**
     * @brief Get the head (first node) of the list.
     *
     * @return A pointer to the head node.
     */
    Node<Task> *getHead();

    /**
     * @brief Get the tail (last node) of the list.
     *
     * @return A pointer to the tail node.
     */
    Node<Task> *getTail();

    /**
     * @brief Retrieve the element at the specified index.
     *
     * @param index The index of the element to retrieve.
     * @return The element at the specified index.
     */
    Task retrieve(int index);

    /**
     * @brief Search for the specified element in the list.
     *
     * @param element The element to search for.
     * @return The index of the first occurrence of the element, or -1 if not found.
     */
    int search(Task element);

    /**
     * @brief Insert an element into the list in an ordered manner.
     *
     * The element will be inserted at the correct position in the list based on its order.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insert(Task element);

    /**
     * @brief Insert an element at the head (start) of the list.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAtHead(Task element);

    /**
     * @brief Insert an element at the tail (end) of the list.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAtTail(Task element);

    /**
     * @brief Insert an element at the specified index in the list.
     *
     * @param index The index at which to insert the element.
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAt(int index, Task element);

    /**
     * @brief Remove the element at the head (first node) of the list.
     *
     * @return The removed element.
     */
    Task removeFromHead();

    /**
     * @brief Remove the element at the tail (last node) of the list.
     *
     * @return The removed element.
     */
    Task removeFromTail();

    /**
     * @brief Remove the element at the specified index in the list.
     *
     * @param index The index of the element to remove.
     * @return The removed element.
     */
    Task removeAt(int index);

    /**
     * @brief Check if the list is empty.
     *
     * @return True if the list is empty, false otherwise.
     */
    bool isEmpty();

    /**
     * @brief Get the number of elements in the list.
     *
     * @return The number of elements in the list.
     */
    int getSize();
};

#endif