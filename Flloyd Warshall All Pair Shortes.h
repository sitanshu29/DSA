//Flloyd Warshall All Pair Shortest Algorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int v;
	cin >> v;
	
	vector<vector<int>> g(v, vector<int>(v, 1e4));
	int x, y, z;
	while(1)
	{
		cin >> x >> y >> z;
		g[x][y] = z;
	}
	for(int i = 0; i < v; i++)
	g[i][i] = 0;
	
	for(int k = 0; k < v; k++)
	{
		for(int i = 0; i < v; i++)
		{
			for(int j = 0; j < v; j++)
			{
				if (i!= j && i!= k && j!= k)
				{
					g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
				}
			}
		}
	}
	
	for(int i = 0; i < v; i++)
	{
		for(int j = 0; j < v;j++)
		cout << g[i][j]  << " ";
		cout << endl;
	}
	
}

