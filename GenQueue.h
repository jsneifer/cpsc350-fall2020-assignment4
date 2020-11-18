//GenQueue.h

#include "DoublyLinkedList.cpp"

template <class T>
class GenQueue {
  public:
    GenQueue(); // default
    ~GenQueue<T>();

    // core functions
    T peek();
    T pop();
    void push(T d);
    bool isEmpty();
    unsigned int getSize();

  private:
    int front; // AKA head
    int rear; // AKA back
    unsigned int numElements; //Size of queue

    DoublyLinkedList<T> *myQueue;
};
