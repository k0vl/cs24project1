#ifndef LIST
#define LIST
#include "itemtype.h"
using namespace std;

template <typename T>
class List
{
 public:
  List();
  void insert(T data);
  void print();
 private:
  Node<T>* wlist;
};
#endif
