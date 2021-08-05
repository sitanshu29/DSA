//0-1 KnapSack Problem
#include <bits/stdc++.h>
using namespace std;
/* // Recursive Approach
int max = INT_MIN;
vector<int> global;
void Utility(int p[], int w[], int n, int m,int index,  int size, int total, vector<int> v)
{
    if (size > m)
    return;
    if (v.size() == n)
    {
        if (total > ::max)
        {
            ::max = total; ::global = v;
        }
        return;
    }
    v.push_back(1);
    Utility(p, w, n, m, index+1, size+w[index], total+p[index], v);
    v.pop_back();
    v.push_back(0);
    Utility(p, w, n, m,index+1, size, total, v);
    
}

vector<int> knapSack(int p[], int w[], int n, int m)
{
    vector<int> v;
    v.push_back(1);
    Utility(p, w, n, m, 1, w[0], p[0], v);
    v.pop_back();
    v.push_back(0);
    Utility(p, w, n, m, 1, 0, 0, v);
    return ::global;
}*/

void knapSack(int p[], int w[], int n, int m)
{
    int arr[n][m+1];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m+1; j++)
    {
        if (j == 0)
        arr[i][j] = 0;
        else if (i == 0)
        {
            if (j < w[i])
            arr[i][j] = 0;
            else
            arr[i][j] = p[i];
        }
        else if (j < w[i])
        arr[i][j] = arr[i-1][j];
        else
        {
            arr[i][j] = max(arr[i-1][j], p[i]+arr[i-1][j-w[i]]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << w[i] << "->\t";
        for(int j = 0; j < m+1; j++)
        cout << arr[i][j] << "\t";
        cout << endl;
    }
    int i = n-1, j = m;
    stack<bool> st;
    while(st.size() != n)
    {
    	if (i == 0)
    	{
    		if (j == 0)
    		st.push(0);
    		else
    		st.push(1);
		}
		else if (arr[i][j] == arr[i-1][j])
    	{
			st.push(0);
			i -= 1;
		}
    	else
    	{
			st.push(1);
    		j -= w[i];
    		i -= 1;
    	}
	}
	while(!st.empty())
	{
		cout << st.top() << " ";	st.pop();
	}

}

int main()
{
	int val[] = {1,4,4,5,7};  
    int wt[] = {1,2,3,4,5};  
    int W = 9;  
    int n = sizeof(val)/sizeof(val[0]);
    knapSack(val, wt, n, W);
    //vector<int> v = knapSack(val, wt, n, W);
    //for(int i = 0; i < n; i++)
    //cout << v[i] << " ";
    return 0;
}