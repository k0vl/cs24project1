#ifndef WORD_H
#define WORD_H
#include "itemtype.h"
using namespace std;

struct Word{
	string word;
	File* file_ptr = NULL;
	Word* next = NULL;
};
#endif