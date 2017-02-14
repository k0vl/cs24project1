#include <string>
#include <cstdlib>
#include "itemtype.h"
#include "list.h"
using namespace std;

class Word
{
	public:
		void setWord( string str );
		void setNext( Node<T>* node );
		void setList( List<T>* list );
		string getWord() const;
		Node<T>* getNext() const;
		List<T>* getList() const;
	private:
		Node<T>* nextWord;
		List<T>* fileList;
		string word;
}