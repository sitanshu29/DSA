//Bridges in an undirected Graph
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

vector<int> adj[101];
vector<bool> visited;
vector<int> dfn, low;
vector<pii> ans;
int timer;

void dfs(int u, int p = -1)
{
	visited[u] = 1;
	dfn[u] = low[u] = ++timer;
	
	for(int i: adj[u])
	{
		if (i == p) continue;
		
		if (visited[i])
		low[u] = min(low[u], dfn[i]);
		else
		{
			dfs(i, u);
			low[u] = min(low[u], low[i]);
			if (low[i] > dfn[u])
			ans.push_back({u, i});
		}
	}	
}

void AP(int V)
{
	visited.assign(V, 0);
	dfn.assign(V, -1);
	low.assign(V, -1);
	ans.clear();
	timer = 0;
	for(int i = 0; i < V; i++)
	{
		if (!visited[i])
		dfs(i);
	}

	for(auto it: ans)
	{
		cout << it.first << "-" << it.second << endl;
	}
	
}

int main()
{
	

	return 0;
}