#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <iostream>
#include <cstdlib>

using namespace std;

struct File
{
	string filename;
	int count;
	File* next;
};
#endif
