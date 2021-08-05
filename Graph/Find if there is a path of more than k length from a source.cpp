//Find if there is a path of more than k length from a source (BackTracking)
#include <bits/stdc++.h>
#define V 10
using namespace std;

bool checkUtility(int g[][V], vector<bool> visited, int head, int dist, int curr)
{
    visited[head] = 1;
    if (curr >= dist)
        return true;

    for (int i = 0; i < V; i++)
    {
        if (g[head][i] != 0 && visited[i] == 0)
        {
            if (checkUtility(g, visited, i, dist, curr + g[head][i]))
                return true;
        }
    }
    return false;
}

bool check(int g[][V], int source, int dist)
{
    vector<bool> visited(V, false);
    if (checkUtility(g, visited, source, dist, 0))
        return true;
    return false;
}