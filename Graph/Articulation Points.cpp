//Find Articulation Point/ Cut Vertices of a Graph
// Low(u) = min{ dfn(u), min of low values of children, min of dfn values of back edges from u }
// If low(v) >= dfn(u), where v are the children in dfs tree from u, then u is an articulation point
//It means that there is no backedge that connects back the ancestor of u and to do so it has to pass through u

#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> dfn, low;
set<int> ans;
int timer;

void dfs(vector<int> adj[], int u, int p = -1)
{
	visited[u] = true;
	dfn[u] = low[u] = timer++;
	int children = 0;
	for (int i : adj[u])
	{
		if (i == p)
			continue;

		if (visited[i])
			low[u] = min(low[u], dfn[i]);
		else
		{
			dfs(adj, i, u);
			low[u] = min(low[u], low[i]);
			++children;
			if (low[i] >= dfn[u] && p != -1)
				ans.insert(u);
		}
	}

	if (children > 1 && p == -1)
		ans.insert(u);
}

void articulationPoints(vector<int> adj[], int n)
{
	timer = 0;
	visited.assign(n, 0);
	dfn.assign(n, -1);
	low.assign(n, -1);
	ans.clear();

	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs(adj, i);

	for (auto i : ans)
		cout << i << " ";
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> adj[n];
	int x, y;
	while (1)
	{
		cin >> x >> y;
		if (x == -1)
			break;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	articulationPoints(adj, n);
}
