#include <iostream>
#include <string>
using namespace std;

#include "hashtable.h"

HashTable::HashTable()
{
	for(int i = 0; i < size; i++)
	{
		item new_item;
		new_item.key = "EMPTY";
		new_item.value = "EMPTY";
		new_item.next = NULL;

		table[i] = new_item;
	}
}

int HashTable::hash(string key)
{
	int index = 0; 

	for(int i = 0; i < key.length(); i++)
	{
		index += (int) key[i];
	}

	return index % size;
}

void HashTable::insert(string key, string value)
{
	int index = hash(key);
	if(table[index].key == "EMPTY" && table[index].value == "EMPTY")
	{
		item new_item;
		new_item.key = key;
		new_item.value = value;
		new_item.next = NULL;
		table[index] = new_item;
	}
	else
	{
		item new_item;
		new_item.key = key;
		new_item.value = value;
		new_item.next = &table[index];
		table[index] = new_item;		
	}
}

void HashTable::print()
{
	for(int i = 0; i < size; i++)
	{
		cout << i << ": " << table[i].key << " : " << table[i].value << ", " << endl;
	}
}
