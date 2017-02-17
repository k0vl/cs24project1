// Implementation file for Unsorted.h
#include <iostream>
#include <string>
#include "itemtype.h"
#include "word.h"
using namespace std;
void insert_file(Word* word_ptr, string filename)
{
	if( !(word_ptr->file_ptr) )
	{
		word_ptr->file_ptr = new File{filename,1,NULL};
		return;
	}
	File* iterator = word_ptr->file_ptr;
	while (iterator->next) {
		iterator = iterator->next;
		if(iterator->filename == filename)
			iterator->count++;
	}
	iterator->next = new File{filename,1,NULL};
}

Word* insert_word(Word*& head, string search)
{
	if (!head) {
		head = new Word{ search,NULL,NULL };
		return head;
	}
	Word* ptr = head;
	while (ptr->next) {
		ptr = ptr->next;
		if (ptr->word == search)
			return ptr;
	}
	return ptr->next = new Word{search,NULL,NULL};
}

void print_all(Word* head)
{
	while(head){
		cout << "\"" << head->word << "\"" << endl;
		for(File* i = head->file_ptr; i; i = i->next)
			cout << i->filename << ":" << i->count << endl;
		head = head->next;
	}
}