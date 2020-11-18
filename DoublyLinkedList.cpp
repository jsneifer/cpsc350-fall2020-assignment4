#include "DoublyLinkedList.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
  front = NULL;
  back = NULL;
  size = 0;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  ListNode<T> *current = front;
  while(current != 0) {
    ListNode<T>* next = current->next;
    delete current;
    current = next;
  }
  front = 0;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d) {
  ListNode<T> *node = new ListNode<T>(d);
  if(size == 0) {
    back = node;
  } else {
    node->next = front;
  }
  front = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeFront() {
  ListNode<T> *current = front;
  delete front;
  front = current->next;
  return front->data;
}

template <class T>
T DoublyLinkedList<T>::removeBack() {
  ListNode<T> *current = back;
  delete back;
  back = current->prev;
  return back->data;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d) {
  ListNode<T> *node = new ListNode<T>(d);
  if(front == NULL) {
    front = back;
  } else {
    back->next = node;
  }
  back = node;
  ++size;
}

template <class T>
int DoublyLinkedList<T>::getSize() {
  return size;
}

template <class T>
void DoublyLinkedList<T>::printList() {
  ListNode<T> *current = front;

  while(current != NULL) {
    cout << current->data << endl;
    current = current->next;
  }
}

template <class T>
T DoublyLinkedList<T>::getFront() {
  return front->data;
}


/*
template <class T>
int DoublyLinkedList<T>::find(T value) {
  int pos = -1;
  ListNode<T> *current = front;

  while(pos != NULL) {
    ++pos;
    if(current->data == value) {
      break;
    }
    current = current->next;
  }
  if(current == NULL) {
    pos = -1;
  }

  return pos;
}
*/

/*
template <class T>
int DoublyLinkedList<T>::deletePos(int pos) {
  int p = 0;
  ListNode<T> *current = front;
  ListNode<T> *prev = front;

  while(p != pos) {
    prev = current;
    current = current->next;
    ++p;
  }

  prev->next = current->next;
  current->next = NULL;
  int temp = current->data;
  --size;
  delete current;
  return temp;
}
*/
