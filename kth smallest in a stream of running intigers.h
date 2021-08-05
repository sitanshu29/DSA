//kth largest element in a stream of intigers
#include <bits/stdc++.h>
using namespace std;


void maxHeapify(vector<int> &v, int i, int n)
{
	int t = i;
	int j = 2*t+1;
	while(j < n-1)
	{
		if( v[j+1] > v[j])
			j = j+1;
		if (v[t] < v[j])
		{
			swap(v[t], v[j]);
			t = j;
			j = 2*t+1;
		}
		else
		break;
	}
	if (j == n-1)
	{
		if (v[j] > v[t])
			swap(v[j], v[t]);
	}
}


int kthsmallest(vector<int> &v, int k)
{
	for(int i = k-1; i>= 0; i--)
	{
		maxHeapify(v, i, v.size());
		for (int w = 0; w< k; w++)
		cout << v[w] << " ";
		cout << endl;
	}
	for(int i = k; i < v.size(); i++)
		if (v[0] >v[i])
		{
			swap(v[0], v[i]);
			maxHeapify(v, 0, k);
		}
		else
			continue;
	return v[0];
}
			

int main()
{
	vector<int> v;
	int k;
	cin >> k;
	while(1)
	{
		int x;
		cin >> x;
		if (x == 0)
			break;
		v.push_back(x);
		if (v.size()< k)
		cout << "kth smallest:\t" << 0 << "\n";
		else
		{
			cout << "kth smallest:\t" << kthsmallest(v, k) << "\n";
		}
	}
}
