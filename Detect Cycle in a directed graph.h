//Cycle in an Directed Graph
#include <bits/stdc++.h>
#define V 
using namespace std;

bool cycleUtill(int g[][V], vector<bool> visited, int head)
{
	visited[head] = 1;
	for (int i = 0; i < V; i++)
	{
		if (g[head][i] != 0)
		{
			if (visited[i] == 1)
				return true;
			else if (cycleUtill(g, visited, i))
				return true;
		}
	}
	return false;
}


bool detectCycle(int g[][V], int head)
{
	vector<bool> visited;
	for (int i = 0; i < V; i++)
		visited.push_back(0);
	
	if (cycleUtill(g, visited, head))
		return true;
	return false;
}

