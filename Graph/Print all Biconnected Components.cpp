//Find all the Biconnected Components of the Graph (Need li'll changes)
#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<int> dfn, low;
set<int> ans;
int timer;
stack<pair<int, int>> st;

void dfs(vector<int> adj[], int u, int p = -1)
{
	visited[u] = true;
	dfn[u] = low[u] = timer++;
	int children = 0;
	if (p!= -1)
	st.push({p, u});
	for(int i: adj[u])
	{
		if (i == u) continue;
		
		if (visited[i])
		{
			low[u] = min(low[u], dfn[i]);
			st.push({u, i});
		}
		else
		{
			dfs(adj, i, u);
			low[u] = min(low[u], low[i]);
			++children;
			
			if (low[i] >= dfn[u] && p != -1)
			{
				ans.insert(u);
				while(st.top() != make_pair(u, i))
				{
					cout << st.top().first << "--" << st.top().second << ", ";
					st.pop();
				}
				cout << endl;
				st.pop();
			}
		}
	}
	
	if (children > 1 && p == -1)
	ans.insert(u);
}


void biconnectedComponents(vector<int> adj[], int n)
{
	timer = 0;
	visited.assign(n, 0);
	dfn.assign(n, -1);
	low.assign(n, -1);
	ans.clear();
	
	cout << "Biconnected Components are: \n";
	for(int i = 0; i < n; i++)
	if (!visited[i])
	dfs(adj, i);
	while(!st.empty())
	{
		cout << st.top().first << "---" << st.top().second << endl;
		st.pop();
	}
	cout << "Articulation Points are: \n";
	for(auto i : ans)
	cout << i << " ";
	cout << endl;
	
}


int main()
{
	int n;
	cin >> n;
	vector<int> adj[n];
	int x, y;
	while(1)
	{
		cin >> x >> y;
		if (x == -1)
		break;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	biconnectedComponents(adj, n);
}
