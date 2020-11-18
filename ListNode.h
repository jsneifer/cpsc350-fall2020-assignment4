#include <iostream>
using namespace std;

template <class T>
class ListNode {
  public:
    ListNode<T>();
    ListNode<T>(T d);
    ~ListNode<T>();

    T data;
    ListNode<T> *next;
    ListNode<T> *prev;
};
