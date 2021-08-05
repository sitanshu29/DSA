//m-coloring Problem (prints all possible ways to color a graph using m color)
#include <bits/stdc++.h>
#define V 4
using namespace std;

void printVector(vector<int> color)
{
    for (int i = 0; i < V; i++)
    cout << color[i] << "\t";
    cout << endl;
}

void Utility(int g[][V], int m,int vertex,int c, vector<int> color)
{
    if (vertex == V)
    {
        printVector(color);
        return;
    }
    for (int i= 0; i < V; i++)
    {
        if (g[vertex][i]!= 0)
        {
            if (color[i] == c)
            return;
        }
    }
    color[vertex] = c;
    for (int i = 1; i <=m; i++)
    Utility(g, m, vertex+1, i, color);
}

void graphColoring(int g[][V], int m)
{
    vector<int> color;
    for (int i = 0; i < V; i++)
    color.push_back(0);

    for (int i = 0; i < V; i++)
    cout << "V" << i+1 << "\t";
    cout << endl;

    for (int i = 1; i <= m; i++)
    Utility(g, m,0, i, color);
}

int main()
{
    int g[V][V] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 
    int m = 3; // Number of colors 
    graphColoring (g, m); 
    return 0; 
}