#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int k, int n)
{
	int i = k;
	int j = 2*i+1;
	while(j < n-1)
	{
		if (arr[j+1] > arr[j])
			j = j+1;
		if (arr[j] > arr[i])
		{
			swap(arr[j], arr[i]);
			i = j;
			j = 2*i+1;
		}
		else
		break;
	}
	if (j == n-1)
	{
		if (arr[j] > arr[i])
			swap(arr[j], arr[i]);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n-1; i >= 0; i--)
		heapify(arr, i , n);
	
	for (int i = n-1; i>= 0; i--)
	{
		swap(arr[i], arr[0]);
		heapify(arr, 0, i);
	}
}



int main()
{
	int arr[] = {5, 31, 14, 6, 41, 2, 9, 29, 4};
	heapSort(arr, 9);
	for (int i = 0; i < 9; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

		