//Insertion Sort in Array
#include <bits/stdc++.h>
using namespace std;

void insertSort(int arr[], int n)
{
	int temp;
	for (int i = 1; i < n; i++)
	{
		temp = arr[i];
		int j;
		for (j = i-1; j >=0; j--)
		{
			if (arr[j] > temp)
				arr[j+1] = arr[j];
			else
				break;
		}
		arr[j+1] = temp;
	}
}

int main()
{
	int arr[] = {5, 31, 14, 6, 41, 2, 9, 29, 4};
	insertSort(arr, 9);
	for (int i = 0; i < 9; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

		