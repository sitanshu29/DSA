//Dijkstra's Single Source Shortest Path Algorithm
#include <bits/stdc++.h>
#define v 9
using namespace std;

void printPath(vector<pair<pair<int,bool>, int>> dist, int i)
{
	if(dist[i].second == -1)
	return;
	printPath(dist, dist[i].second);
	cout << dist[i].second << " ";
}

void shortestPathUtill(int g[][v], vector<pair<pair<int, bool>, int>> &dist, int h)
{
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
		shortestPathUtill(g, dist, index);
	}
}

void shortestPath(int g[][v], int source)
{
	vector<pair<pair<int,bool>, int>> dist;
	for (int i = 0; i < v; i++)
	{
		dist.push_back(make_pair(make_pair(INT_MAX, 0), -1));
	}
	dist[source].first.first = 0;
	dist[source].first.second = 1;
	
	shortestPathUtill(g,dist, source);
	
	cout << "Shortest distance from the source " << source << " are:\n";
	for (int i = 0; i < v; i++)
	{
		cout << i << "- distance: " << dist[i].first.first << "\n ";
		cout << "Path to vertex " << i << " from " << source << " is: ";
		printPath(dist,i);
		cout << endl;
	}
	cout << endl;
	
}

int main() 
{ 
    /* Let us create the example graph discussed above */
    int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    shortestPath(graph, 0); 
  
    return 0; 
}