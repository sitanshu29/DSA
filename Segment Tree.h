#include <bits/stdc++.h>
using namespace std;


int createUtill(int new_arr[], int arr[], int l, int r, int ind)
{
	if ( l == r)
	{
		new_arr[ind] = arr[l];
		return new_arr[ind];
	}
	int mid = l +(r-l)/2;
	new_arr[ind] = createUtill(new_arr, arr, l, mid, 2*ind +1) + createUtill(new_arr, arr, mid+1, r, 2*ind +2);
}


int *createSegmentTree(int arr[], int n, int k)
{
	int a = pow(2,k);
	int *new_arr = new int[a + 2*k +1];
	for(int j = 0; j < a + 2*k +1 ; j++)
	new_arr[j] = INT_MIN;
	createUtill(new_arr, arr, 0, n-1, 0);
	return new_arr;
}

int findSum(int arr[], int x, int y, int l, int r, int ind)
{
	if (x <= l && y >= r)
	return arr[ind];
	if (l == r)
	return 0;
	int mid = l + (r-l)/2;
	return findSum(arr, x, y, l, mid, 2*ind +1) + findSum(arr, x, y, mid+1, r, 2*ind +2);
}

int main()
{
	 int arr[] = {1, 3, 5, 7, 9, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
	int i;
	for (i = 0; i <= n/2; i++)
	{
		int x = pow(2,i);
		if ( x == n)
			break;
		if( x > n)
			break;
	}
	int *new_arr = createSegmentTree(arr, n, i);
	cout << "Given Segment Tree is: ";
	for(int j = 0; j <  pow(2,i) + 2*i +1; j++)
	{
		if (new_arr[j] != INT_MIN)
		cout << new_arr[j] << " ";
	}
	cout << endl;
	cout << "Enter the range for sum within size: ";
	int x, y;
	cin >> x >> y;
	cout << "The sum in range " << "[" << x << ", " << y << "] is :" << findSum(new_arr, x, y, 0, n-1, 0) << endl;
	
	
	return 0;
}



	