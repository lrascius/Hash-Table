#include <iostream>
#include "hashtable.h"
using namespace std;

int main(int argc, char const *argv[])
{
	HashTable hash; 
	hash.insert("lol0", "someval1");
	hash.insert("lol1", "someval2");
	hash.insert("lol2", "someval3");
	hash.insert("lol3", "someval4");
	hash.insert("lol4", "someval5");
	hash.insert("lol5", "someval6");
	hash.insert("lol6", "someval7");
	hash.insert("lol7", "someval8");
	hash.insert("lol8", "someval9");
	hash.print();
	return 0;

}