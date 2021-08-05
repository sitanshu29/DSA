//Binary Lifting In a Fenwick Tree
//Finfing idx with given prefix Sum
// 2 Variation - i.)  Finding the idx of the lower bound of given prefix Sum 
//				ii.) Finding the greatest idx with given prefix Sum
// Variation can be used to find kth smallest and kth largest element
// https://codeforces.com/contest/1354/problem/D Multiset Problem For Reference
#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int ft[1000005];
int n;


int find(int k)			//Finding lower bound of prefixSum
{
	int curr = 0, prevSum = 0;
	for(int i = (int)log2(n); i >= 0; i--)
	{
		if (curr+ (1<<i) <= n && ft[curr+ (1<<i)] + prevSum < k)
		{
			curr+= 1<<i;
			prevSum+= ft[curr];
		}
	}
	
	return curr+1;
}

// If in the tree exists more than one index with a same
// cumulative frequency, this procedure will return 
// the greatest one

int findG(int cumFreq)
{
	int bitMask = 1<<((int)log2(n));
	int idx = 0;
	
	while(bitMask != 0)
	{
		int tidx = idx + bitMask;
		bitMask>>= 1;
		
		if (tidx > n)
		continue;
		
		if (cumFreq >= ft[tidx])
		{
			idx = tidx;
			cumFreq-= ft[tidx];	
		}		
	}
	
	if (cumFreq != 0)
	return -1;
	else
	return idx;
}

void update(int i, int val)
{
	while(i <= n)
	{
		ft[i]+= val;
		i+= (i&-i);
	}
}

int main()
{
	cin >> n;
	memset(ft, 0, sizeof(ft));
	
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		update(i, arr[i]);
	}
	
	int k;
	cin >> k;
	cout << find(k) << " " << findG(k) << endl;
}
