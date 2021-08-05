#include <bits/stdc++.h>
#define V 4
using namespace std;


void BFS(int g[][V], int head)
{
    bool visited[V];
    for (int i =0 ;i < V; i++)
    visited[i] = false;

    visited[head] = 1;
    queue <int> q;
    q.push(head);
    int i;
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        for (int j = 0; j < V; j++)
        {
            if (g[i][j]!= 0)
            {
                if (visited[j] == 0)
                {
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }
        cout << i << " ";
    }
    cout << endl;
}

void DFSUtill(int g[][V], bool visited[], int node)
{
    visited[node] = 1;
    cout << node << " ";
    for (int i = 0; i < V; i++)
    {
        if (g[node][i]!= 0)
        {
            if (visited[i] == 0)
            DFSUtill(g, visited, i);
        }
    }
}

void DFS(int g[][V], int head)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    visited[i] = 0;

    DFSUtill(g, visited, head);

    for (int i = 0; i < V; i++)       // This for loop to print disconnected components
    if (visited[i] == 0)
    DFSUtill(g, visited, i);
}


int main()
{
    int g[V][V];
    for (int i = 0; i < V; i++)
    for (int j =0; j < V; j++)
    g[i][j] = 0;

    int i, j, head;
    while(1)
    {
        cin >> i >> j;
        if (i == -1 && j ==-1)
        break;
        
        g[i][j] = 1;
    }
    cin >> head;

    DFS(g, head);
    BFS(g , head);
    
    return 0;
}