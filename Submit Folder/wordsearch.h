#ifndef WORD_H
#define WORD_H
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"
#include "list.h"
using namespace std;

int getdir (string dir, vector<string> &files);
int main(int argc, char* argv[]);
#endif



