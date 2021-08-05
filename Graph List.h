//Graph List Implementation
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v, head;
	list<int> *adj;
	
	public:
	
	Graph(int s, int h = -1)
	{
		this->head = h;
		this->v = s;
		this->adj = new list<int>[s];
	}
	
	void addEdge(int a, int b)
	{
		adj[a].push_back(b);
	}
	
	void BFS()
	{
		bool visited[v] = {0};
		queue<int> q;
		q.push(head);
		visited[head] = 1;
		int temp;
		while(q.empty() == false)
		{
			temp = q.front();
			cout << temp << " ";
			q.pop();
			for (list<int>::iterator i = adj[temp].begin(); i != adj[temp].end(); i++)
			{
				if (visited[*i] == 0)
				{
					visited[*i] = 1;
					q.push(*i);
				}
			}
		}
	}
	
	void DFSUtil(bool *visited, int x)
	{
		visited[x] = 1;
		cout << x << " ";
		list<int>::iterator i;
		for (i = adj[x].begin(); i != adj[x].end(); i++)
		{
			if (visited[*i] == 0)
				DFSUtil(visited, *i);
		}
	}
	
	void DFS()
	{
		bool *visited = new bool[v];
		for (int i = 0; i < v; i++)
			visited[i] = false;
		DFSUtil(visited, head);
	}
	
};


int main()
{
	Graph g(7, 5);
	 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 
    g.DFS();
    cout << endl;
    return 0;
	
}