#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"
#include "list.h"
#include "wordsearch.h"

using namespace std;

// Given a directory, return all the files in that directory
// if the directory does not exist -- report error.
int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) 
  {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) 
  {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}

int main(int argc, char* argv[])
{
  string dir;
  vector<string> files = vector<string>();
  Word* head = NULL;

  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }
  
  // THIS PART OF THE CODE SETS UP THE INVERTED INDEX 

  string slash("/");
  for (unsigned int i = 0; i < files.size(); i++) {
    if(files[i][0]=='.') continue; //skip hidden files
    cout << "OPEN " << files[i] << endl;
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file..
    string word;
    while(true){
      fin>>word;
      if(fin.eof()) {cout << "EOF " << files[i] << endl; break;}
      insert_file(insert_word(head, word), files[i]);
      // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
      // Use these two strings to search/insert in your linked lists
    }
    fin.close();
  }

	cout << "This is the next part of the program " << endl;
  
	string keyword;
	bool found = false;
	cout << "Welcome to The Dictionary (Case Sensitive)\n";
	do
	{
		cout << "Please enter a word: ";
		cin >> keyword;
		if (keyword != "exit") //skip process if keyword == exit
		{
			Word* iterW = head;
			while (iterW != NULL && !found) //search word
			{
				if (iterW->getWord() == keyword) //word found
				{
					cout << "Keyword \"" + keyword + "\" found in: ";
					File* iterF = iterW->getFilePtr();
					while (iterF != NULL) //print files
					{
						cout << "[" << iterF->getFilename() << ", " << iterF->getCount() <<"] ";
						iterF = iterF->getNext();
					}
					cout << endl;
					found = true;
				}
				iterW = iterW->getNext();
			}
			found = false;
		}
	} while (keyword != "exit");
  
  return 0;
}



