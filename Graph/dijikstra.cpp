#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second

void minimumCostPath(vector<vector<int>> &grid)
{

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    int n = grid.size();

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    dist[0][0] = 0;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    pq.push({0, {0, 0}});
    int x, y, z;

    while (!pq.empty())
    {
        cout << 1 << endl;
        z = pq.top().ff, x = pq.top().ss.ff, y = pq.top().ss.ss;
        pq.pop();

        if (x == n - 1 && y == n - 1)
            break;
        if (dist[x][y] < z)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || dist[nx][ny] < dist[x][y] + grid[x][y])
                continue;

            dist[nx][ny] = dist[x][y] + grid[x][y];
            pq.push({dist[nx][ny], {nx, ny}});
        }
    }

    cout << dist[n - 1][n - 1] + grid[n - 1][n - 1] << endl;
}

int main()
{

    vector<vector<int>> grid = {{4, 4}, {3, 7}};
    minimumCostPath(grid);
}