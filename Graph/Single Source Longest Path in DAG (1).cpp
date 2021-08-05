//Single Source Longest Path Algo Using Topological Sort in DAG
#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> st)
{
	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

class Graph
{
    public:
    int V;
    list<pair<int, int>> *adj;

    Graph(int x)
    {
        this->V = x;
        adj = new list<pair<int, int>>[x];
    }

    void addEdge(int u, int v, int x)
    {
        adj[u].push_back(make_pair(v, x));
    }

    void sortUtility(stack<int> &st, bool visited[], int vertex);
    void printLongestPath(int source);
    stack<int> TopologicalSort();
};

void Graph::sortUtility(stack<int> &st, bool visited[], int vertex)
{
    visited[vertex] = 1;
    list<pair<int,int>>::iterator itr = adj[vertex].begin();
    while(itr != adj[vertex].end())
    {
        if (visited[itr->first] == false)
        sortUtility(st, visited, itr->first);
        ++itr;
    }
    st.push(vertex);
}

stack<int> Graph::TopologicalSort()
{
    stack<int> st;
    bool arr[V];
    for (int i = 0; i <V; i++)
    arr[i] = false;

    for (int i = 0; i < V; i++)
    if (arr[i] == false)
	sortUtility(st, arr, i);
    printStack(st);
	return st;
}

void Graph::printLongestPath(int source)
{
    stack<int> st = TopologicalSort();
    vector<int> dist(V, INT_MIN);
    dist[source] = 0;
    while(st.top()!= source)
    st.pop();
    while(!st.empty())
    {
        list<pair<int,int>>::iterator itr = adj[st.top()].begin();
        while(itr != adj[st.top()].end())
        {
            if (dist[itr->first] < dist[st.top()] + itr->second)
            dist[itr->first] = dist[st.top()] + itr->second;
            itr++;
        }
        st.pop();
    }

    for (int i = 0; i <  V; i++)
    cout << dist[i] << " ";
    cout << "\n";
}

int main()
{
    Graph g(6);  
    g.addEdge(0, 1, 5);  
    g.addEdge(0, 2, 3);  
    g.addEdge(1, 3, 6);  
    g.addEdge(1, 2, 2);  
    g.addEdge(2, 4, 4);  
    g.addEdge(2, 5, 2);  
    g.addEdge(2, 3, 7);  
    g.addEdge(3, 5, 1);  
    g.addEdge(3, 4, -1);  
    g.addEdge(4, 5, -2);  
    
    int s = 1;
    g.printLongestPath(s);
    return 0;
}