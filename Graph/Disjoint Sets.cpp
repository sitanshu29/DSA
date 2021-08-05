//Disjoint Sets Array Implementation
#include <bits/stdc++.h>
using namespace std;

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
	disjointSet st(5);
	cout << st.Union(0, 2)  << "\n";
	cout << st.Union(4, 2)  << "\n";
	cout << st.Union(3, 1)  << "\n";
	if (st.find(4) == st.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    if (st.find(1) == st.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
	
}
