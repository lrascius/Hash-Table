#include <iostream>
#include <string>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{

	private:
		static const int size = 10;
		size_t count;

		struct item
		{
			string key;
			string value;
			item* next;
		};

		item* table[size];
		int hash(string key);
		bool inTable(string key, string value);

	public:
		HashTable();
		void insert(string key, string value);
		size_t length();
		void print();
		string getValue(string key);
		void remove(string key);

};

#endif