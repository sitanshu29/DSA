//Ford Fulkerson And Edmons Karp Max Flow Algorithm
//Reading Material - https://www.topcoder.com/community/competitive-programming/tutorials/maximum-flow-section-2/
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> &parent)
{
	fill(parent.begin(), prent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, INT_MAX});
	pair<int, int> temp;
	while(!q.empty())
	{
		int curr = q.front().first;
		int flow = q.front().second;
		q.pop();
		for(auto i : adj[curr])
		{
			if (parent[i] == -1 && capacity[curr][i])
			{
				parent[i] = curr;
				int new_flow = min(flow, capacity[curr][i]);
				
				if (i == t)
				return new_flow;
				q.push({i, new_flow});
			}
		}
	}
	
	return 0;
	
}


int maxFlow(int s, int t)
{
	int maxflow = 0;
	int new_flow;
	vector<int> parent(n);
	
	while(new_flow = bfs(s, t, parent))
	{
		maxflow+= new_flow;
		int curr = t;
		while(curr!= s)
		{
			int prev = parent[curr];
			capacity[prev][curr]-= new_flow;
			capacity[curr][prev]+= new_flow;
			curr = prev;
		}
	}
	
	//To print min cut edges, we do a dfs to get all the vertices reachable from s in the final residual graph
	//All the edges that are from a visited vertex to a non visited vertex in the original graph consists of
	//min cut edges
	
	bool visited[n];
	memset(visited, 0, sizeof(visited));
	dfs(capacity, s, visited);
	
	for(int i = 0; i < n; i++)
	{
		for(int j : adj[i])
		{
			if (visited[i] && !visited[j])
			cout << i << "---" << j << endl;
		}
	}
	
	return maxflow;
}



