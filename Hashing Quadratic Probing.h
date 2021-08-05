//Hashing Quadratic Probing
#include <iostream>
using namespace std;

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
	int capacity;
	int size;
	HashNode<K, V> **arr;
	HashNode<K, V> *dummy;
	
	public:
	HashMap()
	{
		capacity = 20;
		size = 0;
		
		arr = new HashNode<K, V> *[capacity];
		
		for (int i = 0; i < capacity; i++)
			arr[i] = NULL;
		
		dummy = new HashNode<K, V>(-1, -1);
	}
	
	int hashcode(K k)
	{
		return k%capacity;
	}
	
	void insert(K k, V v)
	{
		if (size == capacity)
			return;
		HashNode *temp = new HashNode<K, V>(k, v);
		int htemp = hashcode(k);
		int hashIndex = htemp;
		int counter = 1;
		while(arr[hashIndex] != NULL && arr[hashIndex]->key != key && arr[hashIndex]->key != -1)
		{
			hashIndex = htemp + counter*counter;
			hashIndex %= capacity;
			counter++;
		}
		if ( arr[hashIndex] == NULL && arr[hashIndex]->key != -1)
			size++;
		arr[hashIndex] = temp;
	}
	
	V deleteNode(K k)
	{
		if (size == 0)
			return;
		int htemp = hashcode(k);
		int hashIndex = htemp;
		int counter = 1;
		while(arr[hashIndex] != NULL && arr[hashIndex]->key != -1 && counter-1 < capacity)
		{
			if (arr[hashIndex]->key == k)
			{
				HashNode<K, V> *temp = arr[hashIndex];
				arr[hashIndex] = dummy;
				return temp->value;
			}
			hashIndex = htemp + counter*counter;
			hashIndex %= capacity;
			counter++;
		}
		return NULL;
	}
	
	V get(K k)
	{
		if (size == 0)
			return;
		int htemp = hashcode(k);
		int hashIndex = htemp;
		int counter = 1;
		while(arr[hashIndex] != NULL && arr[hashIndex]->key != -1 && counter-1 < capacity )
		{
			if (arr[hashIndex]->key == k)
			{
				return arr[hashIndex]->value;
			}
			hashIndex = htemp + counter*counter;
			hashIndex %= capacity;
			counter++;
		}
		return NULL;
	}
	
	int sizeofMap() 
    { 
        return size; 
    }  
    bool isEmpty() 
    { 
        return size == 0; 
    } 
	
	void display() 
    { 
        for(int i=0 ; i<capacity ; i++) 
        { 
            if(arr[i] != NULL && arr[i]->key != -1) 
                cout << "key = " << arr[i]->key << "  value = "<< arr[i]->value << endl; 
        } 
    } 
};
	
int main()
{
	HashMap<int, int> *h = new HashMap<int, int>;
	h->insertNode(1,1); 
    h->insertNode(2,2); 
    h->insertNode(2,3); 
    h->display(); 
    cout << h->sizeofMap() <<endl; 
    cout << h->deleteNode(2) << endl; 
    cout << h->sizeofMap() <<endl; 
    cout << h->isEmpty() << endl; 
    cout << h->get(2); 
  
    return 0; 
} 
		
	
	