//Prim's Minimum Cost Spanning Tree (Without Heap)
#include <bits/stdc++.h>
#define V 7
using namespace std;

int MSTUtill(int g[][V], bool visited[], int sum, int i, int gMST[][V])
{
	if (i == V-1)
		return sum;
	int min = INT_MAX;
	int minKey;
	int node;
	for (int j = 0; j < V; j++)
	{
		if (visited[j] == 1)
		{
			for (int k = 0; k < V; k++)
			{
				if (visited[k] == 0 && g[j][k]!= 0 && g[j][k] <= min)
				{
					min = g[j][k];
					minKey = k;
					node = j;
				}
			}
		}
	}
	
	gMST[node][minKey] = gMST[minKey][node] = min;
	visited[minKey] = 1;
	return MSTUtill(g, visited, sum+min, i+1, gMST);
}
	
	

int MST(int g[][V])
{
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = 0;
	visited[0] = 1;
	int gMST[V][V];
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			gMST[i][j] = 0;
	
	int min = MSTUtill(g, visited, 0, 0, gMST);
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			cout << gMST[i][j] << " ";
		cout << "\n";
	}
	return min; 
}

int main()  
{  
    
    int graph[V][V] = { { 0,2,0,11,0,0,0 },  
                        {2, 0,10,4,14,0,0},  
                        {0, 10,0,9,3,5,8},  
                        {11,4,9,0,0,0,0},  
                        {0,14,3,0,0,0,6},
						{0,0,5,0,0,0,0},
						{0,0,8,0,6,0,0 } };  
  
    // Print the solution  
    cout << MST(graph);  
  
    return 0;  
}  

