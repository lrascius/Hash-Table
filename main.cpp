#include <iostream>
#include "hashtable.h"
using namespace std;

int main(int argc, char const *argv[])
{
	HashTable hash; 
	hash.insert("lol", "someval1");
	hash.insert("lol3", "someval4");
	hash.insert("lol4", "someval5");
	hash.insert("lol5", "someval6");
	// hash.insert("lol6", "someval7");
	// hash.insert("lol7", "someval8");
	// hash.insert("lol8", "someval9");
	// hash.insert("lol9", "someval10");
	// hash.insert("lol10", "someval11");
	// hash.insert("lol11", "someval12");
	// hash.insert("lol12", "someval13");
	// hash.insert("lol13", "someval14");
	hash.insert("lol14", "someval15");
	hash.insert("lol15", "someval16");
	hash.insert("lol16", "someval17");
	// hash.insert("lol17", "someval18");
	// hash.insert("lol18", "someval19");
	// hash.insert("lol19", "someval20");
	// hash.insert("lol20", "someval21");
	hash.print();
	cout << "--------------------------" << endl;
	hash.remove("lol14");
	hash.remove("lol15");
	hash.remove("lol16");
	hash.remove("lol");
	hash.remove("lol3");
	hash.remove("lol4");
	hash.remove("lol5");
	hash.print();
	cout << hash.length();

	return 0;

}