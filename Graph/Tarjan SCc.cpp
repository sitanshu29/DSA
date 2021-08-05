//Tarjan's Algorithm to print SCC
#include <bits/stdc++.h>
#define V 
using namespace std;

void Utility(int g[][V],int vertex,  bool stackMemb[], int visitTime[], int lowLink[], stack<int> &st)
{
    static int time = 0;
    stackMemb[vertex] = 1;
    visitTime[vertex] = lowLink[vertex] = ++time;
    st.push(vertex);

    for (int i = 0; i < V; i++)
    {
        if (g[vertex][i] != 0)
        {
            if (visitTime[i] == -1)
            {
                Utility(g, i, stackMemb, visitTime, lowLink, st);
                lowLink[vertex] = min(lowLink[vertex], lowLink[i]);
            }
            else if (stackMemb[i] == 1)
            lowLink[vertex] = min(lowLink[vertex], lowLink[i]);
        }
    }

    if (lowLink[vertex] == visitTime[vertex])
    {
        int w = 0;
        while(st.top() != vertex)
        {
            w = st.top();
            st.pop();
            cout << w << " ";
            stackMemb[w] = 0;
        }
        w = st.top();
        cout << w << "\n";
        stackMemb[w] = 0;
        st.pop();
    }
    
}

void SCC(int g[][V])
{
    bool stackMemb[V];
    int visitTime[V];
    stack<int> st;
    int lowLink[V];
    for (int i = 0; i < V; i++)
    {
        stackMemb[V] = 0;
        visitTime[i] = -1;
        lowLink[i] = -1;
    }

    for (int i = 0; i < V; i++)
    if (visitTime[i] == -1)
    Utility(g, i, stackMemb, visitTime, lowLink, st);
}

int main()
{
    int g[V][V];
    for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
    g[i][j] = 0;

    int i, j;
    while(1)
    {
        cin >> i >> j;
        if (i == -1 && j == -1)
        break;
        g[i][j] = 1;
    }
    SCC(g);
}