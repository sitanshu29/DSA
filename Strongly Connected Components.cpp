//Kosaraju Strongly Connected Components
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int i, bool visited[])
{
	visited[i] = 1;
	
	for(auto it: adj[i])
	{
		if (!visited[it])
		dfs(adj, it, visited);
	}
	cout << i << "->";
}

void fill(vector<int> adj[], int i, bool visited[], stack<int> &ftime)
{
	visited[i] = 1;
	for(auto it: adj[i])
	{
		if (visited[it]== 0)
		fill(adj, it, visited, ftime);
	}
	ftime.push(i);
}


void printSCC(vector<int> adj[], int v)
{
	bool visited[v];
	memset(visited, 0, v);
	
	stack<int> ftime;
	for(int i = 0; i < v; i++)
	{
		if (visited[i] == 0)
		fill(adj,i, visited, ftime);
	}
	
	memset(visited, 0, v);
	vector<int> rev[v];
	for(int i = 0; i < v; i++)
	{
		for(auto it: adj[i])
		{
			rev[it].push_back(i);
		}
	}
	int x;
	while(!ftime.empty())
	{
		x = ftime.top();
		ftime.pop();
		if (!visited[x])
		{
			dfs(rev, x, visited);
			cout << endl;
		}
	}
}

int main()
{
	int v;
	cin >> v;
	vector<int> adj[v];
	int x, y;
	while(1)
	{
		cin >> x >> y;
		if (x == -1)
		break;
		adj[x].push_back(y);
	}
	
	printSCC(adj, v);
	return 0;
}
