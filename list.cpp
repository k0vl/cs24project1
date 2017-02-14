// Implementation file for Unsorted.h
#include <iostream>
#include "itemtype.h"
template <typename T> List<T>::List()
{
  wlist = NULL;
}
template <typename T> void List<T>::insert(T data)
// If the fname already exists -- increment the count of the node;
// Otherwise add the node
{
  List<T>* newNode;

  newNode = new List<T>(data, wlist);
  wlist = newNode;
}

template <typename T> void List<T>::print() {
  List<T>* cursor;

  for (cursor = wlist; cursor != NULL; cursor = cursor->getNext()) {
    cout << cursor->getData() << endl;
  }
}
