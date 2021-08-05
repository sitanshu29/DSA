// MaxHeap Class Representation
#include <iostream>
using namespace std;

class MaxHeap
{
	int *arr;
	int size;
	int capacity;
	
	public:
	
	Maxheap(int cap)
	{
		capacity = cap;
		size = 0;
		arr = new int(cap);
	}
	
	int parent(int i)
	return (i-1)/2;
	int left(int i)
	return 2*i +1;
	int right(int i)
	return 2*i +2;
	
	int extractMax()
	{
		if( size <= 0)
			return INT_MIN;
		if (size == 1)
		{
			size--;
			return arr[0];
		}
		int temp = arr[0];
		arr[0] = arr[size-1];
		size--;
		Maxheapify(0);
		return temp;
	}
	
	void insert(int x)
	{
		if(size == capacity)
		{
			cout << "Overflow\n";
			return;
		}
		size++;
		int i = size-1;
		arr[i] = x;
		while(i!= 0 && arr[i] > arr[parent(i)])
		{
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	
	void increseKey(int index, int val)
	{
		arr[index] = val;
		while(index!= 0 && arr[index] > arr[parent(i)])
		{
			swap(arr[index], arr[parent(i)]);
			index = parent(i);
		}
	}
	
	void deleteKey(int index)
	{
		arr[index] = INT_MIN;
		Maxheapify(index);
		size--;
		
		/* // oTHER Way
		increseKey(index, INT_MAX);
		extractMax();   */
	}
	
	void Maxheapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int largest = i;
		if (l < size && arr[l] >  arr[largest])
			largest = l;
		if (r < size && arr[r] > arr[largest])
			largest = r;
		if (largest != i)
		{
			swap(arr[i] , arr[largest]);
			Maxheaify(largest);
		}
	}
};


		