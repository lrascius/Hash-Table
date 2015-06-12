#include <iostream>
#include <string>
using namespace std;

#include "hashtable.h"

HashTable::HashTable()
{
	for(int i = 0; i < size; i++)
	{
		item* new_item = new item;
		new_item->key = "EMPTY";
		new_item->value = "EMPTY";
		new_item->next = NULL;

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

	if(table[index]->key == "EMPTY" && table[index]->value == "EMPTY")
	{
		table[index]->key = key;
		table[index]->value = value;
		table[index]->next = NULL;
	}
	else
	{
		item* new_item = new item;
		new_item->key = key;
		new_item->value = value;
		new_item->next = table[index];
		table[index] = new_item;
	}
}

void HashTable::print()
{
	for(int i = 0; i < size; i++)
	{
		// if(table[i]->next != NULL)
		// {
		// 	item* item_ptr = table[i]; 
		// 	// while(item_ptr != NULL)
		// 	// {
		// 		cout << item_ptr << endl;
		// 		cout << i << ": " << table[i]->key << " : " << table[i]->value << ", " << endl;
		// 		item_ptr = item_ptr->next;
		// 		cout << item_ptr->next << endl;
		// 	// }
		// }
		// else
		// {
			cout << i << ": " << table[i]->key << " : " << table[i]->value << ", " << endl;
	// 	}
	}
}
