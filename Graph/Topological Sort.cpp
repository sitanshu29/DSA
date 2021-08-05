//Printing All topological Sorts for Dirercted Acyclic Graph(Kahn's Algorithm)
#include <bits/stdc++.h>
#define V 6
using namespace std;

void print(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

void Utility(list<int> *adj, vector<int> indegree, int vertex, queue<int> order, vector<bool> visited)
{
    order.push(vertex);
    visited[vertex] = true;
    list<int>::iterator itr;
    for (itr = adj[vertex].begin(); itr!= adj[vertex].end(); itr++)
    {
        --indegree[*itr];
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i]!= 1 && indegree[i] == 0)
        {
            Utility(adj, indegree, i, order, visited);
        }
    }

    if (order.size() == V)
    print(order);
}

void topologicalSort(list<int> *adj, vector<int> indegree)
{
    queue<int> order;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            Utility(adj, indegree, i, order, visited);
        }
    }
    
}

int main()
{
    list<int> *adj = new list<int>[V];
    vector<int> indegree(V, 0);

    int x, y;
    while(1)
    {
        cin >> x >> y;
        if (x == -1 && y == -1)
        break;
        adj[x].push_back(y);
        ++indegree[y];
    }

    topologicalSort(adj, indegree);
    return 0;
}