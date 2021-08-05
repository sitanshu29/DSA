//kth smallest elements using max heapcheck
#include <bits/stdc++.h>
using namespace std;

	void Maxheapify(int arr[], int i, int n)
	{
		int largest = i;
		int l = 2*i+1;
		int r = 2*i +2;
		if (l < n && arr[largest] < arr[l])
			largest = l;
		if (r < n && arr[largest] < arr[r])
			largest = r;
		if (largest!= i)
		{
			swap(arr[i], arr[largest]);
			Maxheapify(arr, largest, n);
		}
	}
	
	
	void buildMaxheap(int arr[], int n)
	{
		for(int i = n-1; i>= 0; i--)
		
			Maxheapify(arr, i, n);
	}
	
	void kthSmallest(int arr[], int n, int k)
	{
		buildMaxheap(arr, k);
		for(int i = k; i < n; i++)
		{
			if (arr[0] < arr[k])
				continue;
			else
			{
				swap(arr[0], arr[k]);
				Maxheapify(arr, 0, k);
			}
		}
		for (int i = 0; i < k; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	
	
	
int main() 
{ 
    int arr[] = {12, 3, 5, 7, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]), k = 4; 
    cout << "K'th smallest element is ";
	kthSmallest(arr, n, k); 
    return 0; 
}