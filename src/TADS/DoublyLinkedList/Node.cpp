#include "..\..\..\include\TADS\DoublyLinkedList\Node.h"

class Task;

template <class T>
Node<T>::Node()
{
    this->next(nullptr);
}

template <class T>
Node<T>::Node(T val) : value(val), next(nullptr), previous(nullptr) {}

template <class T>
Node<T>::Node(T val, Node *n, Node *p) : value(val), next(n), previous(p) {}

template <class T>
Node<T>::~Node()
{
    //
}

template <class T>
T Node<T>::getValue()
{
    return this->value;
}

template <class T>
void Node<T>::setValue(T val)
{
    this->value = val;
}

template <class T>
Node<T> *Node<T>::getNext()
{
    return this->next;
}

template <class T>
void Node<T>::setNext(Node<T> *n)
{
    this->next = n;
}

template <class T>
Node<T> *Node<T>::getPrevious()
{
    return this->previous;
}

template <class T>
void Node<T>::setPrevious(Node<T> *p)
{
    this->previous = p;
}