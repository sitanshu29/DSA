//Count and Radix Sort
#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
	int max = INT_MIN;
	for (int i= 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	
	return max;
	
}

void countSort(int arr[], int n, int exp)
{
	int temp[10] = {};
	for (int i = 0; i < n; i++)
		temp[(arr[i]/exp)%(10)]++;
		
	int newarr[n];
	
	for (int i = 1; i < 10; i++)
	temp[i] += temp[i-1];
	
	for (int i = n-1; i >= 0; i--)
	{
		newarr[temp[(arr[i]/exp)%(10)] - 1] = arr[i];
		temp[(arr[i]/exp)%(10)]--;
	}
	
	for (int i = 0; i < n; i++)
		arr[i] = newarr[i];
}

void radixSort(int arr[], int n)
{
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
	countSort(arr, n, exp);
	
}

int main()
{
	int arr[] = { 87, 513, 109, 6, 3, 17, 2, 8941, 5, 21};
	radixSort(arr, 10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
}
