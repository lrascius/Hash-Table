#include <iostream>
#include "hashtable.h"
using namespace std;

int main(int argc, char const *argv[])
{
	HashTable hash; 
	hash.insert("lol", "someval");
	hash.insert("lol1", "someval");
	hash.insert("lol2", "someval");
	hash.insert("lol3", "someval");
	hash.insert("lol4", "someval");
	hash.insert("lol5", "someval");
	hash.insert("lol6", "someval");
	hash.insert("lol7", "someval");
	hash.insert("lol8", "someval");
	hash.print();
	// struct item
	// {
	// 	string key;
	// 	string value;
	// 	item* next;
	// };
	
	// item table[10];

	// item l;
	// item g;

	// l.key = "1";
	// l.value = "ds";
	// l.next = &g;

	// table[0] = l; 
	// cout << &l << endl;

	// table[1] = 2;
	// cout << table[1] << endl;
	return 0;

}