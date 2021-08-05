//Print all the Hamaltonian Cycles in a Graph (Not Working)
#include <bits/stdc++.h>
#define V 5
using namespace std;

void print(vector<int> include)
{
	cout << "Hamaltonian Cycle : ";
	for (int i = 0; i < V; i++)
	{
		cout << include[i] << " ";
	}
	cout << endl;
}

void nextVertex(int g[][V], int vertex, vector<int> &include)
{
    do
    {
        
		include[vertex] = (include[vertex]+1)%(V+1);
        if (include[vertex] == 0)
        {
			for (int i = 0; i < V; i++)				//For loop run for debugging
			{
				cout << include[i] << " ";
			}
			cout << endl;
			return;
		}
        if (g[include[vertex-1]-1][include[vertex]-1]!= 0)
        {
            int i;
            for (i = 0; i < vertex; i++)
            {
                if (include[i] == include[vertex])
                break;
            }
            if (i == vertex)
            {
                if (vertex < V-1 || (vertex == V-1 && g[0][include[vertex]-1] != 0))
                {
                	for (int i = 0; i < V; i++)					//for loop run for debugging
					{
						cout << include[i] << " ";
					}
					cout << endl;
					return;
				}
            }
        }
    }
    while(true);
}

void hamaltonian(int g[][V], int vertex, vector<int> &include)
{
    do
    {
        cout << "Enter\n";					//Typing enter for debugging
		nextVertex(g, vertex, include);
        if (include[vertex] == 0)
        return;
        if (vertex == V-1)
        print(include);
        else
        hamaltonian(g, vertex+1, include);
    }
    while(true);
}

void printHamaltonianCycle(int g[][V])
{
    vector<int> include;
    for (int i = 0; i< V; i++)
    include.push_back(0);

    include[0] = 1;
    hamaltonian(g, 1, include);
}

int main()
{
    int g[V][V];
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
    g[i][j] = 0;
    int x, y;
    while(1)
    {
        cin >> x >> y;
        if (x == -1 && y == -1)
        break;
        g[x][y] = g[y][x] = 1;
    }
    printHamaltonianCycle(g);
    return 0;
}