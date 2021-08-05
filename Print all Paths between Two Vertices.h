//Print all Paths between Two Vertices
#include <bits/stdc++.h>
#define V 5
using namespace std;

void printVector(vector<int> path)
{
	vector<int>::iterator itr = path.begin();
	while(itr!= path.end())
	{
		cout << *itr << "->";
		itr++;
	}
	cout << endl;
}


void modifiedDFS(int arr[][V], int head, int end, vector<bool> visited, vector<int> path)
{
	visited[head] = true;
	path.push_back(head);
	if (head == end)
	{
		printVector(path);
		return;
	}
	
	for (int i = 0; i < V; i++)
	{
		if (arr[head][i] == 1)
		if (visited[i] == NULL)
			modifiedDFS(arr, i, end, visited, path);
	}
}

void printAllPaths(int arr[][V], int start, int end)
{
	vector<bool> visited;
	for (int i = 0; i < V; i++)
		visited.push_back(false);
	vector<int> path;
	modifiedDFS(arr, start, end, visited, path);
}

int main()
{
	int arr[V][V];
	for (int i = 0; i < V; i++)
	for(int j = 0; j < V; j++)
	arr[i][j] = 0;
	cout << "Input the elements of the graph" << endl;
	int x, y;
	while(1)
	{
		cout << "Enter the edge u want to make between two node... -1, -1 to stop." << endl;
		cin >> x >> y;
		if (x == -1 && y == -1)
			break;
		arr[x][y] = 1;
	}
	
	printAllPaths(arr, 0, 4);
	return 0;
}
