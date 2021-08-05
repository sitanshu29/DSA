//Shortest Path in an unweighted Graph from Source to Dest(Uisng dijkstra's)
#include <bits/stdc++.h>
#define v 8
using namespace std;

void printPath(vector<pair<pair<int,bool>, int>> dist, int i)
{
	if(dist[i].second == -1)
	return;
	printPath(dist, dist[i].second);
	cout << dist[i].second << "->";
}

void shortestPathUtill(int g[][v], vector<pair<pair<int, bool>, int>> &dist, int h, int dest)
{
	if (dist[dest].first.second == 1)
	return;
	for (int i = 0; i < v; i++)
	{
		if (g[h][i] != 0)
		if (dist[i].first.second == 0)
		{
			if (dist[h].first.first + g[h][i] < dist[i].first.first)
			{
				dist[i].first.first = dist[h].first.first + g[h][i];
				dist[i].second = h;
			}
		}
	}
	int index = -1; int min = INT_MAX;
	
	for (int i = 0; i < v; i++)
	{
		if (dist[i].first.second == 0)
		{
			if (dist[i].first.first <= min)
			{
				min = dist[i].first.first;
				index = i;
			}
		}
	}
	if (index != -1)
	{
		dist[index].first.second=true;
		shortestPathUtill(g, dist, index, dest);
	}
}

void shortestPath(int g[][v], int source, int dest)
{
	vector<pair<pair<int,bool>, int>> dist;
	for (int i = 0; i < v; i++)
	{
		dist.push_back(make_pair(make_pair(INT_MAX, 0), -1));
	}
	dist[source].first.first = 0;
	dist[source].first.second = 1;
	
	shortestPathUtill(g,dist, source, dest);
	
	cout << "Shortest distance from the source " << source << " to " << dest <<" is: \n";
	cout << dist[dest].first.first << endl;
	printPath(dist, dest);
	cout <<dest << endl;
	
}

int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[v][v];
    
	for (int i = 0; i < v ; i++)
    for (int j = 0; j< v; j++)
    graph[i][j] = 0;
    int x, y;
    while(1)
    {
    	cin >> x >> y;
    	if (x == -1 && y == -1)
    	break;
    	graph[x][y] = 1;
    	graph[y][x] = 1;
	}
  
    shortestPath(graph, 0, 7);
	
  
    return 0; 
}