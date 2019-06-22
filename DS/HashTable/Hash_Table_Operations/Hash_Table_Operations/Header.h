#include<iostream>
#include<string>
using namespace std;

template <class KEY, class VAL >
struct Entry
{
	KEY key;
	VAL value;
	Entry *next;

	Entry(KEY k, VAL val) 
	{
		key = k;
		value = val;
		next = nullptr;
	}
};


template <class KEY, class VAL >
class HashTable
{
	Entry<KEY, VAL> **table;
	int size;

public:
	HashTable(int s=10) 
      {
           	size = s;
	      table = new  Entry<KEY, VAL>*[size];
	         for (int i = 0; i < size; i++)
	         {
	           	table[i] = nullptr;
           	}
  }
	int hash(KEY k) {
		return k%size;
	}

	void put(KEY k, VAL val)
	{
		int offset = hash(k);
		Entry <KEY, VAL> *newEntry = new Entry <KEY, VAL>(k,val);
		if (table[offset] == nullptr)
			table[offset] = newEntry;
		else
			newEntry->next = table[offset];
		    table[offset] = newEntry;
	}

	void print()
	{
		for (int offset = 0; offset < size; offset++)
		{
			cout << offset << ": ";


			for (Entry<KEY, VAL> *current = table[offset]; current; current=current->next)
			{
				cout << "[" << current->key << ", " << current->value << "]";
			}
			cout << endl;

		}
	}

	void Get(KEY k, VAL &val)
	{
		int offset = hash(k);
		for (Entry<KEY, VAL> *current = table[offset]; current; current=current->next)
		{
			if (current->key == k)
			{
				val = current->value;
			}
		}
	}

	bool remove(KEY k)
	{
		Entry<KEY, VAL> *temp;
		int offset = hash(k);
	
			for (Entry<KEY, VAL> *current= table[offset]; current;temp=current,current=current->next)
			{
				if (current->key==k)
				{
					if (current == table[offset])
					
						table[offset] = current->next;
						
					else
						temp->next = current->next;
					delete current;
					return true;
				}
			} 
			return false;
	}
};