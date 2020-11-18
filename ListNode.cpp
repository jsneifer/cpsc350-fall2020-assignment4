#include "ListNode.h"


template <class T>
ListNode<T>::ListNode() {
}

template <class T>
ListNode<T>::ListNode(T d) {
  next = NULL;
  prev = NULL;
  data = d;
}

template <class T>
ListNode<T>::~ListNode() {
  // research
  
}
