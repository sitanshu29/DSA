#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	pair<int, int> arr[n];
	for(int i = 0; i < n; i++)
	{
		arr[i].first = 0;
		arr[i].second = i;
	}
	int u, v, x;
	while(1)
	{
		cin >> u >> v >> x;
		if (x == -1)
		break;
		arr[u].first-= x;
		arr[v].first+= x;
	}
	
	sort(arr, arr+n);
	int count = 0;
	
	int i = 0, j = n-1;
	while(i < j)
	{
		x = min(-arr[i].first, arr[j].first);
		cout << arr[i].second << " will give Rs." << x << " to " << arr[j].second << endl;
		++count;
		arr[i].first+= x;
		arr[j].first-= x;
		
		if (arr[i].first == 0)
		++i;
		if (arr[j].first == 0)
		--j; 
	}
	cout << count << endl;
	
	
}
