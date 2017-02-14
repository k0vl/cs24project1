#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Node{
	public:
		Node(T data = "", Node* next = NULL) {this->data = data; this->next = next;}
		void setWord(T data) {this->data = data;}
		void setNext(Node* next) {this->next = next;}
		T getData() {return data;}
		Node* getNext() {return next;}
		bool hasNext() {return (getNext() != NULL);}
	private:
		T data;
		Node* next;
};
#endif
