//Merge k sorted arrays (STL implementation) using Min Heap

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pp;	//index of array and index of elemwnt in the array


vector<int> merge(vector <vector<int>> arr)
{
	vector<int> v;
	priority_queue< pp, vector<pp>, greater<pp>> pq;
	for (int i = 0; i < arr.size(); i++)
	{
		pq.push({arr[i][0], {i, 0}});
	}
	
	while(pq.empty() == false)
	{
		pp temp = pq.top();
		pq.pop();
		
		v.push_back(temp.first);
		int i = temp.second.first;
		int j = temp.second.second;
		
		if(j+1 < arr[i].size())
			pq.push({arr[i][j+1], {i, j+1}});
	}
	return v;
}



int main()
{
	vector <vector<int>> arr = { {1, 3},
                  {2, 4, 6},
                  {0, 9, 10, 11}} ;
	vector<int> v = merge(arr);
	for (int i = 0 ; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}