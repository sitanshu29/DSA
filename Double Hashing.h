//Double Hashing
#include <iostream>
using namespace std;
#define prime 7

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
	HashNode<K, V> **arr;
	int capacity;
	int size;
	HashNode *dummy;
	
	HashMap()
	{
		capacity = 13;
		size = 0;
		arr = new HashNode<K, V>*[capacity];
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;
		dummy = new HashNode(-1, -1);
	}

	int hashcode1(K k)
	{
		return k%capacity;
	}
	int hashcode2(K k)
	{
		return prime-(key%prime);
	}
	
	void insert(K k, V v)
	{
		if (size == capacity)
			return;
		HashNode *temp = new HashNode<K, V>(k,v);
		int hashIndex1 = hashcode1(k);
		int hashIndex2 = hashcode2(k);
		int c = hashIndex1;
		int counter = 1;
		while(arr[c] != NULL && arr[c]->key != -1 && arr[c]->key != key)
		{
			c = hashIndex + (counter++)*hashIndex2;
		}
		if (arr[c] == NULL || arr[c]->key == -1)
			size++;
		arr[c] = temp;
		return;
	}
	
	V deleteNode(K k)
	{
		
		
			
	
