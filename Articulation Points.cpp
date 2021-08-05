#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> adj[], int i, int v, bool *visited, int *disc, int *low, int *parent, bool *ap)
{
	visited[i] = 1;
	static int time = 0;
	int children = 0;
	
	disc[i] = low[i] = ++time;
	
	for(auto it : adj[i])
	{
		if (!visited[it])
		{
			++children;
			parent[it] = i;
			DFS(adj, it, v, visited, disc, low, parent, ap);
			
			low[i] = min(low[i], low[it]);
			
			if (parent[i] == -1 && children > 1)
			ap[i] = 1;
			
			if (parent[i] != -1 && low[it] >= disc[i])
			ap[i] = 1;
		}
		else if (it != parent[i])
		{
			low[i] = min(disc[it], low[i]);
		}
	}
	
	
}


void articulationPoint(vector<int> adj[], int v)
{
	bool *visited = new bool[v];
	int *disc = new int[v];
	int *parent = new int[v];
	int *low = new int[v];
	bool *ap = new bool[v];
	for(int i = 0; i < v; i++)
	{
		parent[i] = -1;
		ap[i] = 0;
		visited[i] = 0;
	}
	
	for(int i = 0; i < v; i++)
	if (!visited[i])
	DFS(adj, i, v, visited, disc, low, parent, ap);
	
	for(int i = 0; i < v; i++)
	{
		if (ap[i])
		cout << i << " ";
		cout << endl;
	}
}


int main()
{
	int v;
	cin >> v;
	vector<int> adj[v];
	//Add Edges
	int x, y;
	while(1)
	{
		cin >> x >> y;
		if (x == -1)
		break;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	articulationPoint(adj, v);
	
}
