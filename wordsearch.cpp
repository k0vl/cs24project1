#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"
//#include "document.h"

using namespace std;

// Given a directory, return all the files in that directory
// if the directory does not exist -- report error.
int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}

int main(int argc, char* argv[])
{
  string dir; //
  vector<string> files = vector<string>();
  Word wordIndex;

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
      cout<<"       " << files[i]<<"::"<<word<<endl;
      wordIndex.insert(word);
      // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
      // Use these two strings to search/insert in your linked lists
    }
    fin.close();
  }

  cout << "This is the next part of the program " << endl;
  wordIndex.print();
  return 0;
}


