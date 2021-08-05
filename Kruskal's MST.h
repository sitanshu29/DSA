//Kruskal's MST
#include <bits/stdc++.h>
#define V 10
using namespace std;
typedef pair<int, pair<int, int> > pi;
//Detect Cycle in a Undirected Graph
bool cycleUtill(int g[][V],vector<bool> visited, int head, int parent)
{
	visited[head] = 1;
	for (int i = 0; i < V; i++)
	{
		if (g[head][i] != 0)
		{
			if (visited[i] == false)
			{
				if (cycleUtill(g, visited, i, head))
					return true;
			}
			else if (visited[i] == true && i != parent && i!= head)
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
	if (cycleUtill(g,visited, head, -1))
		return true;
	return false;
}

// Kruskal Program

int KruskalMST()
{
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	int weight, i, j;
	while(1)
	{
		cin >> weight >> i >> j;
		if (weight == -1)
			break;
		pq.push(make_pair(weight, make_pair(i, j)));
	}
	int gMST[V][V];
	for (int a = 0; a < V; a++)
		for (int b = 0; b < V; b++)
			gMST[a][b] = 0;
		
	int e = 0;
	int sum = 0;
	pi temp;
	while(e != V-1)
	{
		temp = pq.top();
		pq.pop();
		gMST[temp.second.first][temp.second.second] = temp.first;
		gMST[temp.second.second][temp.second.first] = temp.first;
		if (detectCycle(gMST, temp.second.first))
		{
			gMST[temp.second.first][temp.second.second] = 0;
			gMST[temp.second.second][temp.second.first] = 0;
		}
		else
		{
			cout << temp.second.first << "----" << temp.second.second << " = " << temp.first << "\n"; 
			sum += temp.first;
			++e;
		}
	}
	
	for (int a = 0; a < V; a++)
	{
		for (int b =0 ; b< V; b++)
			cout << gMST[a][b] << " ";
		cout << "\n";
	}
	
	cout << "Sum is: " << sum << "\n";
}

int main()
{
	cout << KruskalMST();
	return 0;
}
