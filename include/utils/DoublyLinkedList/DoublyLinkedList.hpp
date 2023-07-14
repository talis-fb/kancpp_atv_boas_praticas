#ifndef DOUBLY_LINKED_LIST_CLASS
#define DOUBLY_LINKED_LIST_CLASS

#include "Node.hpp"
#include <stdexcept>

/**
 * @brief The DoublyLinkedList class represents a doubly linked list.
 *
 * It allows for efficient insertion and removal of elements at both the head and tail of the list.
 */
template <typename T>
class DoublyLinkedList
{
private:
    Node<T> *head; /**< The head (first node) of the list. */
    Node<T> *tail; /**< The tail (last node) of the list. */
    int size;      /**< The number of elements in the list. */

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
    Node<T> *getHead();
    /**
     * @brief Get the tail (last node) of the list.
     *
     * @return A pointer to the tail node.
     */
    Node<T> *getTail();
    /**
     * @brief Get the element at the specified index.
     *
     * @param index The index of the element to get.
     * @return The element at the specified index.
     */
    T *get(int index);
    /**
     * @brief Search for the specified element in the list.
     *
     * @param element The element to search for.
     * @return The index of the first occurrence of the element, or -1 if not found.
     */
    int search(T element);

    /**
     * @brief Insert an element into the list in an ordered manner.
     *
     * The element will be inserted at the correct position in the list based on its order.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertSorted(T element);

    /**
     * @brief Insert an element at the head (start) of the list.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAtHead(T element);

    /**
     * @brief Insert an element at the tail (end) of the list.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAtTail(T *element);

    /**
     * @brief Insert an element at the specified index in the list.
     *
     * @param index The index at which to insert the element.
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAt(int index, T element)

        ;

    /**
     * @brief Remove the element at the head (first node) of the list.
     *
     * @return The removed element.
     */
    T removeFromHead();

    /**
     * @brief Remove the element at the tail (last node) of the list.
     *
     * @return The removed element.
     */
    T removeFromTail();

    /**
     * @brief Remove the element at the specified index in the list.
     *
     * @param index The index of the element to remove.
     * @return The removed element.
     */
    T removeAt(int index);

    /**
     * @brief Remove the specified element from the list.
     *
     * @param element The element to remove.
     * @return True if the element was successfully removed, false otherwise.
     */
    bool remove(T element);

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

    /**
     * @brief Remove all elements from the list.
     */
    void clear();
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = new Node<T>();
    tail = new Node<T>();
    head->setNext(tail);
    tail->setPrevious(head);
    size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
    delete head;
    delete tail;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::getHead()
{
    return head;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::getTail()
{
    return tail;
}

template <typename T>
T *DoublyLinkedList<T>::get(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    Node<T> *current = head->getNext();
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }

    return current->getValue();
}

template <typename T>
int DoublyLinkedList<T>::search(T element)
{
    Node<T> *current = head->getNext();
    int index = 0;
    while (current != tail)
    {
        if (*(current->getValue()) == element)
            return index;
        current = current->getNext();
        index++;
    }
    return -1;
}

template <typename T>
bool DoublyLinkedList<T>::insertSorted(T element)
{
    Node<T> *newNode = new Node<T>(element);
    if (newNode == nullptr)
        return false;

    Node<T> *current = head->getNext();

    while (current != tail && *(current->getValue()) < element)
    {
        current = current->getNext();
    }

    newNode->setPrevious(current->getPrevious());
    newNode->setNext(current);
    current->getPrevious()->setNext(newNode);
    current->setPrevious(newNode);
    size++;

    return true;
}

template <typename T>
bool DoublyLinkedList<T>::insertAtHead(T element)
{
    Node<T> *newNode = new Node<T>(element);
    if (newNode == nullptr)
        return false;

    newNode->setPrevious(head);
    newNode->setNext(head->getNext());
    head->getNext()->setPrevious(newNode);
    head->setNext(newNode);
    size++;

    return true;
}

template <typename T>
bool DoublyLinkedList<T>::insertAtTail(T *element)
{
    Node<T> *newNode = new Node<T>(element);
    if (newNode == nullptr)
        return false;

    newNode->setPrevious(tail->getPrevious());
    newNode->setNext(tail);
    tail->getPrevious()->setNext(newNode);
    tail->setPrevious(newNode);
    size++;

    return true;
}

template <typename T>
bool DoublyLinkedList<T>::insertAt(int index, T element)
{
    if (index < 0 || index > size)
        return false;

    if (index == 0)
        return insertAtHead(element);
    if (index == size)
        return insertAtTail(element);

    Node<T> *newNode = new Node<T>(element);
    if (newNode == nullptr)
        return false;

    Node<T> *current = head->getNext();

    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }

    newNode->setPrevious(current->getPrevious());
    newNode->setNext(current);
    current->getPrevious()->setNext(newNode);
    current->setPrevious(newNode);
    size++;

    return true;
}

template <typename T>
T DoublyLinkedList<T>::removeFromHead()
{
    if (isEmpty())
        throw std::runtime_error("List is empty");

    Node<T> *nodeToRemove = head->getNext();
    T *removedElement = nodeToRemove->getValue();

    head->setNext(nodeToRemove->getNext());
    nodeToRemove->getNext()->setPrevious(head);
    delete nodeToRemove;
    size--;

    return *removedElement;
}

template <typename T>
T DoublyLinkedList<T>::removeFromTail()
{
    if (isEmpty())
        throw std::runtime_error("List is empty");

    Node<T> *nodeToRemove = tail->getPrevious();
    T removedElement = *(nodeToRemove->getValue());

    tail->setPrevious(nodeToRemove->getPrevious());
    nodeToRemove->getPrevious()->setNext(tail);
    delete nodeToRemove;
    size--;

    return removedElement;
}

template <typename T>
T DoublyLinkedList<T>::removeAt(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    if (index == 0)
        return removeFromHead();
    if (index == size - 1)
        return removeFromTail();

    Node<T> *current = head->getNext();
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }

    T removedElement = *(current->getValue());
    current->getPrevious()->setNext(current->getNext());
    current->getNext()->setPrevious(current->getPrevious());
    delete current;
    size--;

    return removedElement;
}

template <typename T>
bool DoublyLinkedList<T>::remove(T element)
{
    Node<T> *current = head->getNext();
    while (current != tail)
    {
        if (*(current->getValue()) == element)
        {
            current->getPrevious()->setNext(current->getNext());
            current->getNext()->setPrevious(current->getPrevious());
            delete current;
            size--;
            return true;
        }
        current = current->getNext();
    }
    return false;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
int DoublyLinkedList<T>::getSize()
{
    return size;
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
    while (!isEmpty())
    {
        removeFromHead();
    }
}

#endif