//Merge Sort
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int h)
{
	int n1 = mid - l +1;
	int n2 = h - mid;
	int i, j;
	int temp1[n1], temp2[n2];

	for(i = 0; i < n1; i++)
		temp1[i] = arr[l+i];
	for(j = 0; j < n2; j++)
		temp2[j] = arr[mid+1+j];
	
	i = 0; j = 0;
	int k = l;
	while(i < n1 && j < n2)
	{
		if (temp1[i] < temp2[j])
		{
			arr[k] = temp1[i];
			++i;
		}
		else
		{
			arr[k] = temp2[j];
			++j;
		}
		++k;
	}
	while (i < n1)
	{
		arr[k] = arr[i];
		k++;
		i++;
	}
	while(j < n2)
	{
		arr[k] = arr[j];
		j++;
		k++;
	}
}

		
		
		
void mergeSort(int arr[], int n)
{
	int p, i, l, mid, h;
	for (p = 2; p <= n; p= p*2)
	{
		for (i = 0; i+p-1 < n; i = i+p)
		{
			l = i;
			h = i+p-1;
			mid = (l+h)/2;
			merge(arr, l, mid, h);
		}
	}
	if (p/2 < n)
	{
		merge(arr, 0, p/2, n-1);
	}
}

void mergeSortRec(int arr[], int l, int h)
{
	if (l < h)
	{
		int mid = (l+h)/2;
		mergeSortRec(arr, l, mid);
		mergeSortRec(arr, mid+1, h);
		merge(arr, l, mid, h);
	}
}

