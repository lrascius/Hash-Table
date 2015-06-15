#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "hashtable.h"

HashTable::HashTable()
{
	count = 0;
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
		index += (int) key[i];

	return index % size;
}

string HashTable::getValue(string key)
{
	int index = hash(key);
	item* item_ptr = table[index];

	if(item_ptr->key == key)
		return item_ptr->value;

	while(item_ptr->next != NULL)
	{
		item_ptr = item_ptr->next;
		if(item_ptr->key == key)
			return item_ptr->value;
	}
	throw std::invalid_argument("Key is not in the table");
}

void HashTable::insert(string key, string value)
{
	if(!inTable(key, value))
	{
		int index = hash(key);

		if(table[index]->key == "EMPTY" && table[index]->value == "EMPTY")
		{
			table[index]->key = key;
			table[index]->value = value;
		}
		else
		{
			item* new_item = new item;
			new_item->key = key;
			new_item->value = value;
			new_item->next = table[index];
			table[index] = new_item;
		}
		count++;
	}
}

void HashTable::print()
{
	for(int i = 0; i < size; i++)
	{
		if(table[i]->next != NULL)
		{
			item* item_ptr = table[i]; 
			while(item_ptr->next != NULL)
			{
				cout << i << ": " << item_ptr->key << " : " << item_ptr->value << ", " << endl;
				item_ptr = item_ptr->next;
			}
			cout << i << ": " << item_ptr->key << " : " << item_ptr->value << ", " << endl;
		}
		else
		{
			cout << i << ": " << table[i]->key << " : " << table[i]->value << ", " << endl;
		}
	}
}

bool HashTable::inTable(string key, string value)
{
	int index = hash(key);
	item* item_ptr = table[index];

	if(item_ptr->key == key)
		return true;

	while(item_ptr->next != NULL)
	{
		item_ptr = item_ptr->next;
		if(item_ptr->key == key)
		{
			item_ptr->value = value;
			return true;
		}
	}
	return false;
}

void HashTable::remove(string key)
{
	bool found = false;
	int index = hash(key); 
	if(table[index]->key == "EMPTY" && table[index]->value == "EMPTY")
		throw std::invalid_argument("Key is not in the table");

	item* item_ptr = table[index];
	if(item_ptr->key == key && item_ptr->next == NULL)
	{
		found = true;
		item_ptr->key = "EMPTY";
		item_ptr->value = "EMPTY";
	}

	if(item_ptr->key == key && item_ptr->next != NULL)
	{
		found = true;
		table[index] = item_ptr->next;
		delete item_ptr;
	}

	while(item_ptr->next != NULL)
	{
		if(item_ptr->next->key == key)
		{
			found = true;
			item_ptr->next = item_ptr->next->next;
			delete item_ptr->next;
			break;
		}
		item_ptr = item_ptr->next;
	}

	if(found)
		count--;
	else
		throw std::invalid_argument("Key is not in the table");
}

size_t HashTable::length()
{
	return count;
}
