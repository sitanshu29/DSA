#include <iostream>
using namespace std;

int dowork(int arr[], int x , int y);
int findindex(int arr[], int l, int h)
{
	int i, j;
	for(i = l; i < h-1; i++)
	{
		if (arr[i+1]< arr[i])
		{
			j = dowork(arr, i+1 , h);
			if (j!= (h-1) && findindex(arr, j , h)!= -1 )
			j =findindex(arr, j , h);
			return (i*10)+j;
			
		}
	}
	return -1;
}

int dowork(int arr[], int x, int y)
{
	int temp;
	for (int k = x; k < y ; k++)
	{
		if (arr[k] < arr[x-1])
		temp = k;
	}
	return temp;
}

int main()
{
	int arr[] = {2, 3, 4, 9 , 6 , 5 , 11 , 10};
	int h = sizeof(arr)/sizeof(arr[0]);
	int result = findindex(arr, 0 , h);
	cout << result << endl;
	return 0;
	
}
