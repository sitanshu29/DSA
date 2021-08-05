#include <bits/stdc++.h>
using namespace std;

class Minheap
{
	public:
	int size, capacity;
	double *arr;
	
	Minheap(int cap)
	{
		capacity = cap;
		size = 0;
		arr = new double[cap];
	}
	
	void insert(double x)
	{
		if (size == capacity)
		{
			cout << "Heap Overflow" << endl;
			return;
		}
		size++;
		int i = size-1;
		arr[i] = x;
		while(i>0 && arr[i] < arr[(i-1)/2])
		{
			arr[i] = arr[(i-1)/2];
			i = (i-1)/2;
		}
		arr[i] = x;
	}
	
	double extractMin()
	{
		double min = arr[0];
		arr[0] = arr[size-1];
		size--;
		int i = 0;
		int j = 2*i +1;
		while(j < size-1)
		{
			if (arr[j+1] < arr[j])
				j = j+1;
			if (arr[j] < arr[i])
			{
				swap(arr[i], arr[j]);
				i = j;
				j = 2*i+1;
			}
			else
				break;
		}
		if (j == size-1)
			if ( arr[j] < arr[i])
				swap(arr[i], arr[j]);
			
		return min;
	}
};

class Maxheap
{
	public:
	int size, capacity;
	double *arr;
	
	Maxheap(int cap)
	{
		capacity = cap;
		size = 0;
		arr = new double[cap];
	}
	
	void insert(double x)
	{
		if (size == capacity)
		{
			cout << "Heap Overflow" << endl;
			return;
		}
		size++;
		int i = size-1;
		arr[i] = x;
		while(i>0 && arr[i] > arr[(i-1)/2])
		{
			arr[i] = arr[(i-1)/2];
			i = (i-1)/2;
		}
		arr[i] = x;
	}
	
	double extractMax()
	{
		double max = arr[0];
		arr[0] = arr[size-1];
		size--;
		int i = 0;
		int j = 2*i +1;
		while(j < size-1)
		{
			if (arr[j+1] > arr[j])
				j = j+1;
			if (arr[j] > arr[i])
			{
				swap(arr[i], arr[j]);
				i = j;
				j = 2*i+1;
			}
			else
				break;
		}
		if (j == size-1)
			if ( arr[j] > arr[i])
				swap(arr[i], arr[j]);
			
		return max;
	}
};

void runningNumber()
{
	double median = 0;
	Minheap min(100);
	Maxheap max(100);
	while(1)
	{
		double x;
		cin >> x;
		if (x == -1)
			break;
		if( x > median)
			min.insert(x);
		else
			max.insert(x);
		if (min.size - max.size == 2 || min.size - max.size == -2)
		{	
			if (min.size - max.size == 2)
			{
				double t = min.extractMin();
				max.insert(t);
			}
			else
			{
				double t = max.extractMax();
				min.insert(t);
			}
		}
			
			
		if (min.size - max.size == 1 || min.size - max.size == -1)
		{	
			if (min.size - max.size == 1)
			{
				median = min.arr[0];
			}
			else if (min.size - max.size == -1)
				median = max.arr[0];
		}
		else if ( min.size- max.size == 0)
		{
			median = (min.arr[0] + max.arr[0])/2;
		}
		cout << "median "<< median << "\n";
	}
}
		

int main()
{
	runningNumber();
	return 0;
}

			
		