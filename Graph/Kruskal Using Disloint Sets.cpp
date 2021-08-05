//Kruskal MST using Disjoint Set
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, pair<int, int>> 

class disjointSet
{
	public:
		int *arr;
		int size;
		
		disjointSet(int n)
		{
			size = n;
			arr = new int[n];
			for(int i = 0; i < n; i++)
			arr[i] = -1;
		}
		
		int find(int i)			//Find Method With Path Compression
		{
			if (arr[i] < 0)
			return i;
			
			arr[i] = find(arr[i]);
			return arr[i];
		}
		
		int Union(int i, int j)		//Union By rank
		{
			int x = find(i);
			int y = find(j);
			
			if (x == y)
			return x;
			
			else if (abs(arr[x]) >= abs(arr[y]))
			{
				arr[x]+= arr[y];
				arr[y] = x;
				return x;
			}
			else
			{
				arr[y]+= arr[x];
				arr[x] = y;
				return y;
			}
		}
		
};


int main()
{
	int v;
	cin >> v;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int x, y, z;
	while(1)
	{
		cin >> x >> y >> z;
		if(x == -1)
		break;
		pq.push(make_pair(x, make_pair(y, z)));
		
	}
	
	vector<vector<int>> gMST(v, vector<int>(v, 0));
	disjointSet st(v);
	
	int e = 0, sum = 0;
	pii temp;
	while(e!= v-1)
	{
		temp = pq.top();
		pq.pop();
		
		if(st.find(temp.second.first) != st.find(temp.second.second))
		{
			++e;
			sum+= temp.first;
			
			gMST[temp.second.first][temp.second.second] = temp.first;
			gMST[temp.second.second][temp.second.first] = temp.first;
			st.Union(temp.second.first, temp.second.second);
		}	
	}
	
	cout << sum << endl;
	
}
