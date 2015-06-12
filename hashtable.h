#include <iostream>
#include <string>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{

	private:
		static const int size = 10;

		struct item
		{
			string key;
			string value;
			item* next;
		};

		item table[size];

		int hash(string key);

	public:
		HashTable();
		void insert(string key, string value);
		void print();

};

#endif