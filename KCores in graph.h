//Graph List Implementation
#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

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
	
	void printKCores(int k);
	
};

void Graph::printKCores(int k)
{
	vector<pair<int, int>> arr;
	for (int m = 0;m < v; m++)
	arr.push_back(make_pair(m, adj[m].size()));
	sort(arr.begin(), arr.end(), sortbysec);
	int i = 0;
	while(i < v)
	{
		if(arr[i].second == 0)
		i++;
		else if(arr[i].second < k)
		{
			adj[arr[i].first].clear();
			for (int j = 0; j < v; j++)
			{
				adj[j].remove(arr[i].first);
			}
			arr.clear();
			for (int m = 0;m < v; m++)
			arr.push_back(make_pair(m, adj[m].size()));
			sort(arr.begin(), arr.end(), sortbysec);
			i = 0;
		}
		else
		break;
	}
	for (int i = 0; i < v; i++)
	{
		if (adj[i].size() == 0)
			continue;
		else
		{
			cout << "[" << i << "]: ";
			for (list<int>::iterator itr = adj[i].begin(); itr!= adj[i].end(); itr++)
				cout << *itr << "->";
		}
	}
}
int main()
{
	Graph g1(9, 0); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.DFS();
    cout << endl;
    g1.printKCores(3);
   
    cout << endl;
    return 0;
	
}