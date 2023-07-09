#ifndef DOUBLY_LINKED_LIST_CLASS
#define DOUBLY_LINKED_LIST_CLASS

#include "Node.hpp"

/**
 * @brief The DoublyLinkedList class represents a doubly linked list.
 *
 * It allows for efficient insertion and removal of elements at both the head and tail of the list.
 */
template <class T>
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
    DoublyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    /**
     * @brief Destroys the DoublyLinkedList object and frees the memory.
     */
    ~DoublyLinkedList()
    {
        Node<T> *current = this->head;
        Node<T> *next = nullptr;

        while (current != nullptr)
        {
            next = current->getNext();
            delete current;
            current = next;
        }
    }

    /**
     * @brief Get the head (first node) of the list.
     *
     * @return A pointer to the head node.
     */
    Node<T> *getHead()
    {
        return this->head;
    }

    /**
     * @brief Get the tail (last node) of the list.
     *
     * @return A pointer to the tail node.
     */
    Node<T> *getTail()
    {
        return this->tail;
    }

    /**
     * @brief Get the element at the specified index.
     *
     * @param index The index of the element to get.
     * @return The element at the specified index.
     */
    T get(int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw std::out_of_range("Index out of range at retrieve.");
        }

        Node<T> *current = this->head;
        int i = 0;

        while (current != nullptr)
        {
            if (i == index)
            {
                return current->getValue();
            }

            current = current->getNext();
            i++;
        }

        throw std::out_of_range("Index out of range at retrieve.");
    }

    /**
     * @brief Search for the specified element in the list.
     *
     * @param element The element to search for.
     * @return The index of the first occurrence of the element, or -1 if not found.
     */
    int search(T element)
    {
        Node<T> *current = this->head;
        int i = 0;

        while (current != nullptr)
        {
            if (current->getValue() == element)
            {
                return i;
            }

            current = current->getNext();

            i++;
        }

        return -1;
    }

    /**
     * @brief Insert an element into the list in an ordered manner.
     *
     * The element will be inserted at the correct position in the list based on its order.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertSorted(T element)
    {
        //  Insert an element into the list in an ordered manner.

        Node<T> *newNode = new Node<T>(element);

        if (newNode == nullptr)
        {
            return false;
        }

        Node<T> *current = this->head->getNext();

        if (current == nullptr)
        {
            return insertAtHead(element);
        }

        while (current != nullptr)
        {
            if (current->getValue() > element || current->getNext() == nullptr)
            {
                newNode->setNext(current);
                newNode->setPrevious(current->getPrevious());
                current->getPrevious()->setNext(newNode);
                current->setPrevious(newNode);

                this->size++;

                return true;
            }

            current = current->getNext();
        }

        return false;
    }

    /**
     * @brief Insert an element at the head (start) of the list.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAtHead(T element)
    {
        Node<T> *newNode = new Node<T>(element);

        if (newNode == nullptr)
        {
            return false;
        }

        newNode->setNext(this->head->getNext());
        newNode->setPrevious(this->head);
        this->head->getNext()->setPrevious(newNode);
        this->head->setNext(newNode);

        this->size++;

        return true;
    }

    /**
     * @brief Insert an element at the tail (end) of the list.
     *
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAtTail(T element)
    {
        Node<T> *newNode = new Node<T>(element);

        if (newNode == nullptr)
        {
            return false;
        }

        newNode->setNext(this->tail);
        newNode->setPrevious(this->tail->getPrevious());
        this->tail->getPrevious()->setNext(newNode);
        this->tail->setPrevious(newNode);

        this->size++;

        return true;
    }

    /**
     * @brief Insert an element at the specified index in the list.
     *
     * @param index The index at which to insert the element.
     * @param element The element to insert.
     * @return True if the element was successfully inserted, false otherwise.
     */
    bool insertAt(int index, T element)
    {
        if (index < 0 || index > this->size)
        {
            return false;
        }

        if (index == 0)
        {
            return this->insertAtHead(element);
        }

        if (index == this->size)
        {
            return this->insertAtTail(element);
        }

        Node<T> *newNode = new Node<T>(element);

        if (newNode == nullptr)
        {
            return false;
        }

        Node<T> *current = this->head->getNext();

        int i = 0;

        while (current != nullptr)
        {
            if (i == index)
            {
                newNode->setNext(current);
                newNode->setPrevious(current->getPrevious());
                current->getPrevious()->setNext(newNode);
                current->setPrevious(newNode);

                this->size++;

                return true;
            }

            current = current->getNext();

            i++;
        }

        return false;
    }

    /**
     * @brief Remove the element at the head (first node) of the list.
     *
     * @return The removed element.
     */
    T removeFromHead()
    {
        Node<T> *current = this->head->getNext();

        if (current == nullptr)
        {
            throw std::out_of_range("List is empty.");
        }

        T value = current->getValue();

        this->head->setNext(current->getNext());
        current->getNext()->setPrevious(this->head);

        delete current;

        this->size--;

        return value;
    }

    /**
     * @brief Remove the element at the tail (last node) of the list.
     *
     * @return The removed element.
     */
    T removeFromTail()
    {
        Node<T> *current = this->tail->getPrevious();

        if (current == nullptr)
        {
            throw std::out_of_range("List is empty.");
        }

        T value = current->getValue();

        this->tail->setPrevious(current->getPrevious());
        current->getPrevious()->setNext(this->tail);

        delete current;

        this->size--;

        return value;
    }

    /**
     * @brief Remove the element at the specified index in the list.
     *
     * @param index The index of the element to remove.
     * @return The removed element.
     */
    T removeAt(int index)
    {
        if (index < 0 || index >= this->size)
        {
            throw std::out_of_range("Index out of range at removeAt.");
        }

        if (index == 0)
        {
            return this->removeFromHead();
        }

        if (index == this->size - 1)
        {
            return this->removeFromTail();
        }

        Node<T> *current = this->head->getNext();

        int i = 0;

        while (current != nullptr)
        {
            if (i == index)
            {
                T value = current->getValue();

                current->getPrevious()->setNext(current->getNext());
                current->getNext()->setPrevious(current->getPrevious());

                delete current;

                this->size--;

                return value;
            }

            current = current->getNext();
            i++;
        }

        throw std::out_of_range("Index out of range at removeAt.");
    }

    /**
     * @brief Remove the specified element from the list.
     *
     * @param element The element to remove.
     * @return True if the element was successfully removed, false otherwise.
     */
    bool remove(T element)
    {
        Node<T> *current = this->head->getNext();

        while (current != nullptr)
        {
            if (current->getValue() == element)
            {
                current->getPrevious()->setNext(current->getNext());
                current->getNext()->setPrevious(current->getPrevious());

                delete current;

                this->size--;

                return true;
            }

            current = current->getNext();
        }

        return false;
    }

    /**
     * @brief Check if the list is empty.
     *
     * @return True if the list is empty, false otherwise.
     */
    bool isEmpty()
    {
        return this->size == 0;
    }

    /**
     * @brief Get the number of elements in the list.
     *
     * @return The number of elements in the list.
     */

    int getSize()
    {
        return this->size;
    }
};

#endif