// can be used to sort the letters in a string. xD

#include <iostream>
using namespace std;
#define range 10
// Bhai ka SWAG

void countsort(int arr[], int n)
{
	int brr[range] = {};
	for (int i = 0; i < n; i++)
	{
		++brr[arr[i]];
	}
	for (int i = 1; i < range; i++)
	brr[i] += brr[i-1];
	
	int crr[n] = {};
	for (int i = 0; i < n; i++)
	{
		crr[brr[arr[i]]--] = arr[i];
	}
	for (int i = 0; i<n ; i++)
	arr[i] = crr[i];
}

int main()
{
	int arr[] = {6, 7, 4, 1 , 0 , 7, 2, 5, 1, 9, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	countsort(arr, n);
	for (int i = 0; i <n; i++)
	cout << arr[i] << " " ;
	return 0;
}
