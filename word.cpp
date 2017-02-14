#include <string>
#include <cstdlib>
#include "itemtype.h"
#include "list.h"
#include "word.h"
using namespace std;

void Word::setWord( string str ) //set the word
{
	word = str;
}

void Word::setNext( Node<T>* node ) //set link to next word
{
	nextWord = node;
}

void Word::setList( List<T>* list ) //set link to a list of files
{
	fileList = list;
}

string Word::getWord() const //get the word
{
	return word;
}

Node<T>* Word::getNext() const //get link to next word
{
	return nextWord;
}

List<T>* Word::getList() const //get list of files
{
	return fileList;
}