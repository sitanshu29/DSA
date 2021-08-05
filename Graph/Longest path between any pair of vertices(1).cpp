#include <bits/stdc++.h>
#define V 6
using namespace std;

void Utility(int g[][V], vector<bool> visited, int vertex, vector<int> path, int max, vector<pair<vector<int>, int>> &v)
{
    path.push_back(vertex);
    visited[vertex] = 1;
    bool flag = 0;
	for (int i = 0; i < V; i++)
    {
        if (g[vertex][i]!= 0 && visited[i] == 0)
        {
            flag = 1;
			Utility(g, visited, i, path, max+g[vertex][i], v);
        }
    }
    if (flag == 0)
    {
    	v.push_back(make_pair(path, max));
	}
}

void longestPath(int g[][V])
{
    vector<bool> visited(V, false);
    vector<int> path;
    int m = 0;
    vector<pair<vector<int>, int>> v;
    for (int i = 0; i < V; i++)
    Utility(g, visited, i, path, m, v);

    m = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second > m)
        m = i;
    }
    for (int i = 0; i < v[m].first.size(); i++)
    {
        cout << v[m].first[i] << " ";
    }
    cout << endl << v[m].second << endl;
}


int main()
{
    int g[V][V];
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
    g[i][j] = 0;
    int x, y, z; 
    while(1)
    {
        cin >> x >> y >> z;
        if (z == -1)
        break;
        g[x-1][y-1] = g[y-1][x-1] = z;
    }

    longestPath(g);
    return 0;
}