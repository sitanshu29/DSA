//Bellmen Ford Single source Shortest Path Algo DP
//Works also for negative edges, Fails for graph containing negative weight cycle 
#include <bits/stdc++.h>
#define pii pair<pair<int, int>, int>
using namespace std;

int main()
{
	int v;
	cin >> v;
	
	vector<pii> arr;
	int x, y, z;
	while(1)
	{
		cin >> x >> y >> z;
		if (x == -1)
		break;
		arr.push_back(make_pair(make_pair(x, y), z));
	}
	
	int source; cin >> source;
	int dist[v];
	for(int i = 0; i < v; i++)
	dist[i] = INT_MAX;
	dist[source] = 0;
	pii temp;
	for(int i = 0; i < v-1; i++)
	{
		for(int j = 0; j < arr.size(); j++)
		{
			if (dist[arr[j].first.first] != INT_MAX)
			{
				if (dist[arr[j].first.first]+arr[j].second < dist[arr[j].first.second])
				dist[arr[j].first.second] = dist[arr[j].first.first]+arr[j].second;
			}
		}
	}
	
	for(int i = 0; i < v; i++)
	{
		cout << i << "->" << dist[i] << endl;
	}
	return 0;
}
