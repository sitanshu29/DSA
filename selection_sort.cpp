#include <iostream>
using namespace std;

void change(int &x, int &y)
{
	int temp = x;
	x = y;
	y= temp;
}

void selectionsort(int arr[], int n)
{
	for (int i = 0; i< n-1; i++)
	{
		int min = arr[i];
		int index = i;
		for(int j = i; j< n; j++)
		if(min>arr[j])
		{
			min = arr[j];
			index = j;
		}
		change(arr[i], arr[index]);
		
	}
}

int main()
{
	int arr[] = {4, 2, 7, 1,9,3};
	selectionsort(arr, 6);
	for (int i=0; i < 6; i++)
	cout << arr[i] << "  " ;
	return 0;
}
