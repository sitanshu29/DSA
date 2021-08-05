#include <bits/stdc++.h>
#define V 7
using namespace std;

void DFS1(int g[][V], bool visited[], stack<int> &st, int head)
{
    visited[head] = 1;
    for (int i = 0; i < V; i++)
    if (g[head][i] != 0)
    {
        if (visited[i] == 0)
        {
            DFS1(g, visited, st, i);
        }
    }
    st.push(head);
}

void DFS2(int g[][V], bool visited[], int head)
{
    cout << head+1 << " ";
    visited[head] = 1;
    for (int i = 0; i < V; i++)
    if (g[head][i] != 0)
    {
        if (visited[i] == 0)
        {
            DFS2(g, visited, i);
        }
    }
}

void KosarajuSCC(int g[][V])
{
    bool visited[V] = {};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        DFS1(g, visited, st, i);
    }

    int reversed[V][V];                 //Create graph with links reversed
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
    reversed[i][j] = 0;

    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
    if (g[i][j] == 1)
    reversed[j][i] = 1;

    for (int i = 0; i < V; i++)
    visited[i] = 0;
    int counter = 1, temp;
    while(!st.empty())
    {
        temp = st.top();
        st.pop();
        if (visited[temp] == 0)
        {
            cout << counter++ << ".)  ";
            DFS2(reversed, visited, temp);
            cout << endl;
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
        
        g[i-1][j-1] = 1;
    }

    KosarajuSCC(g);
    return 0;
}