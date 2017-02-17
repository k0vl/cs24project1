// Implementation file for Unsorted.h
#include <iostream>
#include "itemtype.h"
#include "word.h"

void insert_file(Word* word_ptr, string filename)
{
	if( !(word_ptr->file_ptr) )
	{
		word_ptr->file_ptr = new File{filename,1,NULL};
		return;
	}
	File* iterator = word_ptr->file_ptr;
	while(iterator && iterator->filename != filename)
		iterator = iterator->next;
	if(iterator)
		iterator->count++;
	else
		iterator->next = new File{filename,1,NULL};
}