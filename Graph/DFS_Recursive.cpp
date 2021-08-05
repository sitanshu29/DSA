#include <bits/stdc++.h>
#define V 5
using namespace std;

void DFSRecursive(int g[][V], int head)
{
    bool visited[V] = {};
    stack<int> st;
    st.push(head);
    int i;
    while(!st.empty())
    {
        i = st.top();
        st.pop();
        if (visited[i]== 0)
        {
            cout << i << " ";
            visited[i] = 1;
            for (int j = V-1; j >= 0; j--)
            {
                if (g[i][j]!= 0)
                {
                    st.push(j);
                }
            }
        }
    }
}

int main()
{
    int g[V][V];
    for (int i = 0; i < V; i++)
    for (int j =0; j < V; j++)
    g[i][j] = 0;

    int i, j, head;
    while(1)
    {
        cin >> i >> j;
        if (i == -1 && j ==-1)
        break;
        
        g[i][j] = 1;
    }
    cin >> head;

    DFSRecursive(g, head);
    
    return 0;
}