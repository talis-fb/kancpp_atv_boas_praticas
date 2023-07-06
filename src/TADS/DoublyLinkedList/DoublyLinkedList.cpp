#include "Node.cpp"
#include "..\..\..\include\TADS\DoublyLinkedList\DoublyLinkedList.hpp"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(void)
{
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
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

template <class T>
Node<T> *DoublyLinkedList<T>::getHead()
{
  return this->head;
}

template <class T>
Node<T> *DoublyLinkedList<T>::getTail()
{
  return this->tail;
}

template <class T>
T DoublyLinkedList<T>::retrieve(int index)
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

template <class T>
int DoublyLinkedList<T>::search(T element)
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

template <class T>
bool DoublyLinkedList<T>::insert(T element)
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
    return DoublyLinkedList<T>::insertAtHead(element);
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

template <class T>
bool DoublyLinkedList<T>::insertAtHead(T element)
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

template <class T>
bool DoublyLinkedList<T>::insertAtTail(T element)
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

template <class T>
bool DoublyLinkedList<T>::insertAt(int index, T element)
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

template <class T>
T DoublyLinkedList<T>::removeFromHead()
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

template <class T>
T DoublyLinkedList<T>::removeFromTail()
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

template <class T>
T DoublyLinkedList<T>::removeAt(int index)
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

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return this->size == 0;
}

template <class T>
int DoublyLinkedList<T>::getSize()
{
  return this->size;
}
