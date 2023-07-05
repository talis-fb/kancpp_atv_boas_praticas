#include "ANode.cpp"
#include "..\..\..\include\TADS\DoublyLinkedList\DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList(void){
  Task temp1("HEAD");
  Task temp2("TAIL");

  this->head = new Node<Task>(temp1);
  this->tail = new Node<Task>(temp2);

  this->head->setNext(this->tail);
  this->head->setPrevious(nullptr);

  this->tail->setPrevious(this->head);
  this->tail->setNext(nullptr);

  this->size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node<Task> *current = head;
    while (current != nullptr) {
        Node<Task> *next = current->getNext();
        delete current;
        current = next;
    }
}