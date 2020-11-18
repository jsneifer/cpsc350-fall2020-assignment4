// implementation GenQueue.cpp

//Repurposed for Registrar's Office
#include "GenQueue.h"

template <class T>
GenQueue<T>::GenQueue() {
  myQueue = new DoublyLinkedList<T>();
  front = 0;
  //rear = 0; //circular queue
  rear = -1;
  numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue() {
  delete myQueue;
}

template <class T>
void GenQueue<T>::push(T d) {
  myQueue->insertBack(d);
  numElements++;
}

template <class T>
T GenQueue<T>::peek() {
  return myQueue->getFront();
}
template <class T>
T GenQueue<T>::pop() {
  return myQueue->removeFront();
}

template <class T>
bool GenQueue<T>::isEmpty() {
  return (numElements == 0);
}

template <class T>
unsigned int GenQueue<T>::getSize() {
  return numElements;
}
