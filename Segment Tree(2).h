#include <bits/stdc++.h>
using namespace std;

int constructSegmentTree(int *root[3], int *arr, int l, int r, int ind)
{
	if (l == r)
	{
		root[ind][0] = arr[l];
		return root[ind][0];
	}
	int mid = l + (r-l)/2;
	root[ind][0] = constructSegmentTree(root, arr, l, mid, 2*ind +1) + constructSegmentTree(root, arr, mid+1, r, 2*ind +2);
}

int getMin(int *root[3], int *arr, int l, int r, int ind)
{
	if (l == r)
	{
		root[ind][1] = arr[l];
		return root[ind][1];
	}
	int mid = l + (r-l)/2;
		root[ind][2] = min(getMin(root, arr, l, mid, 2*ind +1), getMin(root, arr, mid+1, r, 2*ind +2));
}

int getMax(int *root[3], int *arr, int l, int r, int ind)
{
	if (l == r)
	{
		root[ind][2] = arr[l];
		return root[ind][2];
	}
	int mid = l + (r-l)/2;
		root[ind][2] = max(getMax(root, arr, l, mid, 2*ind +1), getMax(root, arr, mid+1, r, 2*ind +2));
}


class SegmentTree
{
	public:
	int **root;
	int size;
	
	SegmentTree(int arr[], int s)
	{
		int i;
		for (i = 0; i < s; i++)
		{
			if (pow(2,i) >= s)
				break;
		}
		size = 2*i+1 + pow(2,i);
		root = new int*[size];
		for (int k = 0; k < size; k++)
		root[k] = new int[3];
		for(int j = 0; j < size; i++)
		for(int k = 0; k < 3; k++)	
		root[j][k] = INT_MIN;
		constructSegmentTree(root, arr, 0, s-1, 0);
		getMin(root, arr, 0, s-1, 0);
		getMax(root, arr, 0, s-1, 0);
	}
	
	int findSum(int x, int y, int l, int r, int ind)
	{
	if (x <= l && y >= r)
	return root[ind][0];
	if (l == r)
	return 0;
	int mid = l + (r-l)/2;
	return findSum(x, y, l, mid, 2*ind +1) + findSum(x, y, mid+1, r, 2*ind +2);
	}
	
	int minQuery(int x, int y, int l, int r, int ind)
	{
		if (x <= l && y >= r)
	return root[ind][1];
	if (l == r)
	return INT_MAX;
	int mid = l + (r-l)/2;
	return min(minQuery(x, y, l, mid, 2*ind +1), minQuery(x, y, mid+1, r, 2*ind +2));
	}
	
	int maxQuery(int x, int y, int l, int r, int ind)
	{
		if (x <= l && y >= r)
		return root[ind][1];
		if (l == r)
		return INT_MIN;
		int mid = l + (r-l)/2;
		return max(maxQuery(x, y, l, mid, 2*ind +1), maxQuery(x, y, mid+1, r, 2*ind +2));
	}
	
};

int main()
{
	 int arr[] = {1, 3, 5, 7, 9, 11};  
     int n = sizeof(arr)/sizeof(arr[0]);
	 
	 SegmentTree st(arr, n);
	 cout << st.findSum(2, 5, 0, 5, 0) << endl;
	 cout << st.minQuery(2,5, 0 , 5, 0) << endl;
	 cout << st.maxQuery(2, 5, 0, 5, 0) << endl;
	 
	 return 0;
}