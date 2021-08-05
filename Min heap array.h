// Min Heap Operations Using Array
#include <iostream>
using namespace std;

void insert(int arr[], int n)  // Here n denotes the index of the last element currently in the arr
{
	
	int i = n;
	int temp = arr[i];
	while(i > 0 && temp < arr[(i-1)/2])
	{
		arr[i] = arr[(i-1)/2];
		i = (i-1)/2;
	}
	arr[i] = temp;
	
}

void createHeap(int arr[], int n)     // Here n denotes the size of the array
{
	for(int i = 1; i < n ; i++)
		insert(arr, i);
}

void deleteSmallest(int arr[], int n)	// Only the smallest element can be deletes from the min Heap(viceversa Max Heap)
{
	swap(arr[0] , arr[n]);
	int i = 0;
    int j = 2*i+1;
	while(j < n-1)
	{
		if (arr[j+1] < arr[j])
			j = j+1;
		if (arr[i] > arr[j])
		{
			swap(arr[i], arr[j]);
			i = j;
			j = 2*i+1;
		}
		else 
			break;
	}
	if(j== n-1)
	{
		if(arr[i]>arr[j])
		swap(arr[i],arr[j]);
	}
}

void heapSort(int arr[], int n)    // A way to sort the heap
{
	for(int i = n-1; i > 0; i--)
		deleteSmallest(arr, i);
}

void heapify(int arr[], int n)
{
	for(int i = n-1; i >= 0; i--)
	{
		int p = i;
		int j = 2*p +1;
		while(j < n-1)
		{
			if (arr[j+1] < arr[j])
				j = j+1;
			if (arr[j] < arr[p])
			{
				swap(arr[j], arr[p]);
				p = j;
				j =2*p +1;
			}
		}
		if (j == n-1)
		{
			if(arr[j] < arr[p])
				swap(arr[j], arr[p]);
		}
	}
}



int main()
{
	int arr[7] = {10, 20, 30, 25, 5, 40, 35};
	/*createHeap(arr, 7);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;
	*/
	heapify(arr, 7);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;
	heapSort(arr, 7);
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
