#include <bits/stdc++.h>
#define size 7
using namespace std;

int shortestPath(int arr[][size],bool visited[size], int head, int dest, int dist)
{
	visited[head] = 1;
	if (head == dest)
		return dist;
	else if(check(arr, visited, head))
		return INT_MAX;
	else
	{
		for (int i = 0; i < size; i++)
		{
			<int> v;
			if (arr[head][i])
			if (visited[i] != 1)
				v.push_back(shortestPath(arr, visited, i, dest, dist+arr[head][i]));
		}
	}
	v.sort(v.begin(), v.end());
	return v[0];
}
		
	
	

void printBredthFirst(int arr[][size], int head)
{
	bool visited[size] = {0};
	queue<int> q;
	q.push(head);
	int temp;
	visited[head] = 1;
	while(q.empty() == false)
	{
		temp = q.front();
		q.pop();
		
		for(int i = 0; i< size; i++)
		{
			if (arr[temp][i] == 1)
			if (visited[i] != 1)	
			{
				visited[i] = 1;
				q.push(i);
			}
		}
		cout << temp << " ";
	}
	cout << endl;
}

void printDepthFirst(int arr[][size], bool visited[], int head)
{
	cout << head << " ";
	visited[head] = 1;
	for (int i = 0; i < size; i++)
	{
		if (arr[head][i] == 1)
			if (visited[i] != 1)
			printDepthFirst(arr, visited, i);
	}
}

void printVector(vector<int> v, int i)
{
	vector<int>::iterator it = v.begin();
	while((*it)!= i)
	{
		it++;
	}
	while(it!= v.end())
	{
		cout << *it << "->";
		it++;
	}
	cout << i << endl;
}
void findCycleDirected(int arr[][size], bool visited[], int head)
{
	visited[head] = 1;
	static vector<int> v;
	v.push_back(head);
	for(int i = 0; i < size; i++)
	{
		if (arr[head][i] == 1)
		{
			if (visited[i] == 1)
			{
				printVector(v, i);
			}
			else
			{
				//visited[i] = 1;
				//v.push_back(i);
				findCycleDirected(arr, visited, i);
			}
		}
	
	}
		v.pop_back();
}

	

int main()
{
	int arr[size][size];
	for (int i = 0; i < size; i++)
	for(int j = 0; j < size; j++)
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
	cout << "Enter the head: ";
	int head;
	cin >> head;
	printBredthFirst(arr, head);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
	for(int j = 0; j < size; j++)
	cout <<arr[i][j] << " ";
	cout << endl;
	}
	cout << endl;
	bool visited[size] = {0};
	printDepthFirst(arr,visited,  head);
	cout << endl;
	
	for (int i= 0; i < size; i++)
		visited[i] = 0;
	findCycleDirected(arr, visited, head);
	cout << endl;
	return 0;
}
