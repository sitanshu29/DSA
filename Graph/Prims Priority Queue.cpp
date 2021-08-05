#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>


int MST(vector<pair<int, int>> adj[], int V)
{
    vector<bool> inMST(V, 0);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V);
    int src = 0;
    key[src] = 0;
    parent[src] = -1;
    int ans = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, src});

    while(!pq.empty())
    {
        src = pq.top().second; pq.pop();
        
        if (inMST[src] == 1)
        continue;

        inMST[src] = 1;
        ans+= key[src];
        for(pair<int, int> it: adj[src])
        {
            if (inMST[it.first] == 0 && key[it.first] > it.second)
            {
                pq.push({it.second, it.first});
                key[it.first] = it.second;
                parent[it.first] = src;
            }
        }
    }

    return ans;
}

int main()
{
    

    return 0;
}