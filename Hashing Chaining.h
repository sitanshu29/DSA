// Hashing Using Chaining
#include <bits/stdc++.h>

template<typename K, typename V>
class HashNode
{
	public:
	K key;
	V value;
	HashNode(K k, V v)
	{
		this->key = k;
		this->value = v;
	}
};

template<typename K, typename V>
class HashMap
{
	list<HashNode<K, V>*> *arr;
	int capacity;

	public:
	HashMap()
	{
		capacity = 20;
		arr = new list<HashNode<K, V>*>[capacity];
	}
	
	int hashcode(K k)
	{
		return k%capacity;
	}
	
	void insert(K k, V v)
	{
		int hashIndex = hashcode(k);
		HashNode *temp = new HashNode(k, v);
		arr[hashIndex].push_back(temp);
	}
	
	V deleteNode(K k)
	{
		int hashIndex = hashcode(k);
		list<HashNode<K, V>*>::iterator itr = arr[hashIndex].begin();
		HashNode *temp;
	    while(itr!= arr[hashIndex].end())
		{
			if ((*itr)->key == k)
			{
				temp = *itr;
				arr[hashIndex].erase(itr);
				return temp->value;
			}
		}
		return NULL;
	}
	
	V get(K k)
	{
		int hashIndex = hashcode(k);
		list<HashNode<K, V>*>::iterator itr = arr[hashIndex].begin();
		while(itr!= arr[hashIndex].end())
		{
			if ((*itr)->key == k)
			{
				return (*itr)->value;
			}
		}
		return NULL;
	}
};

int main()
{
	HashMap<int, int> *h = new HashMap<int, int>;
	h->insertNode(1,1); 
    h->insertNode(2,2); 
	
	return 0;
}


		
	