//Detect Cycle in a Undirected Graph
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int v, head;
	list<int> *adj;
	
	public:
	
	Graph(int s, int h = 0)
	{
		this->head = h;
		this->v = s;
		this->adj = new list<int>[s];
	}
	
	void addEdge(int a, int b)
	{
		adj[a].push_back(b);
		adj[b].push_back(a);
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
	
	bool cycleUtill(int i, bool visited[], int h)
	{
		visited[i] = true;
		for (list<int>::iterator itr = adj[i].begin(); itr!= adj[i].end(); itr++)
		{
			if (visited[*itr] == false)
			{
				if (cycleUtill(*itr, visited, i))
					return true;
			}
			else
			{
				if (*itr != h)
					return true;
			}
		}
		return false;
	}
	
	bool detectCycle()
	{
		bool *visited = new bool[v];
		for (int i = 0; i < v; i++)
			visited[i] = false;
		if (head != 0)
		{
			if (cycleUtill(head, visited, -1))
				return true;
		}
		for (int i = 0; i < v ; i++)
		{
			if (visited[i] == false)
				if(cycleUtill(i, visited, -1))
					return true;
		}
		return false;
	}
	
};


int main()
{
	Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.detectCycle()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.detectCycle()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    return 0; 
}