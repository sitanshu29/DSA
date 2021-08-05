#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y =temp;
}

int partition(int arr[], int l, int h)
{
	int temp = arr[h];
	int i = l-1;
	for(int j = l; j < h ; j++)
	{
		if (arr[j]<=temp)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[h]);
	return i+1;
}

void quicksort(int arr[], int l , int h)
{
	if (l < h)
	{
		int pi = partition(arr, l, h);
		quicksort(arr, l, pi-1);
		quicksort(arr,pi+1, h);
	}
}


void print(int arr[], int n)
{
	for (int i= 0; i < n; i++)
	cout << arr[i] << " ";
}

int main()
{
	int arr[] = {8, 5 , 1, 6, 3, 7, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	quicksort(arr, 0 , n-1);
	print(arr, n);
	return 0;
}
