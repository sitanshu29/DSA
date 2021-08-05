#include <iostream>
using namespace std;

void shiftarr(int arr[], int a, int b, int n)
{
	int temp = arr[a];
	arr[a] = arr[b];
	for (int i = a+2; i < n-1; i++)
	arr[i+1] = arr[i];
	arr[a+1] = temp;
	
}
void insertsort(int arr[],int n)
{
	for(int i = 1; i < n; i++)
	for(int j = 0; j < i; j++)
	{
		if(arr[j]>arr[i])
		{
			shiftarr(arr, j , i , n);
			break;
		}
	}	
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	cout << arr[i] << " ";
}

int main()
{
	int arr[] = {7, 9 , 1 , 3 , 4 , 5 , 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertsort(arr, n);
	print(arr, n);
	return 0;
}
