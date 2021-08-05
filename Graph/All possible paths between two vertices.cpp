//DFS with sort of backtracking
#include <bits/stdc++.h>
#define V 4
using namespace std;

void printVector(vector<int> path, int end)
{
    vector<int>::iterator itr = path.begin();
    cout << "Path: ";
    while(itr!= path.end())
    {
        cout << *itr << "->";
        itr++;
    }
    cout << end << endl;
}

void DFS(list<int> *adj,vector<bool> visited,vector<int> path, int head, int end, int &count)
{
    if (head == end)
    {
        count++;
        printVector(path, end);
        return;
    }
    visited[head] = 1;
    path.push_back(head);
    list<int>::iterator itr = adj[head].begin();
    while(itr != adj[head].end())
    {
        if (visited[*itr] == 0)
        DFS(adj, visited,path, *itr, end, count);
        itr++;
    }
}

int countPath(list <int> *adj, int s, int e)
{
    vector<bool> visited;
    for (int i = 0; i < V; i++)
    visited.push_back(0);

    int count = 0;
    vector<int> path;
    DFS(adj, visited, path, s, e, count);
    return count;
}

int main()
{
    list<int> *adj = new list<int>[V];
    int i , j;
    while(1)
    {
        cin >> i >> j;
        if (i == -1 && j == -1)
        break;
        adj[i].push_back(j);
    }
    cout << countPath(adj, 2, 3);
    return 0;
}