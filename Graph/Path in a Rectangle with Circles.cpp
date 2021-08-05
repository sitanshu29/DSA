//Path in a Rectangle with Circles
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, k, r;
    cin >> m >> n >> k >> r;
    vector<pair<int, int>> cordinate;   //To store the cordinate(x,y)
    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        cordinate.push_back(make_pair(x-1,y-1));
    }
    
    bool arr[m][n];
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    arr[i][j] = 0;
    
    for (int i = 0; i < k; i++)         //Assigning cordinates inside the circle
    for (int a =0; a < m ; a++)
    for (int b =0; b < n; b++)
    {
        if (pow(a-cordinate[i].first,2)+pow(b-cordinate[i].second,2) <= r)
        arr[a][b] = 1;
    }
	
	if (arr[0][0] == 1)					//Case when the start point comes inside any circle
	{
		cout << "Not Posiible\n";
		return 0;
	}
    pair<int, int> temp = {0,0};
    pair<int, int> dest = {m-1,n-1};
    bool flag = 0;
    queue<pair<int, int>> q;
    q.push(temp);
    arr[0][0] = 1;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == dest)
        {
            cout << "Possible\n";
            flag = 1;
            break;
        }
        if (temp.first +1 <= m-1 && arr[temp.first +1][temp.second] != 1)
        {
            q.push(make_pair(temp.first+1, temp.second));
            arr[temp.first +1][temp.second] = 1;
        }
        if (temp.first -1 >= 0 && arr[temp.first -1][temp.second] != 1)
        {
            q.push(make_pair(temp.first-1, temp.second));
            arr[temp.first -1][temp.second] = 1;
        }
        if (temp.second +1 <= n-1 && arr[temp.first][temp.second +1] != 1)
        {
            q.push(make_pair(temp.first, temp.second +1));
            arr[temp.first][temp.second +1] = 1;
        }
        if (temp.second -1 >= 0 && arr[temp.first][temp.second -1] != 1)
        {
            q.push(make_pair(temp.first, temp.second -1));
            arr[temp.first][temp.second -1] = 1;
        }
    }
    if (flag == 0)
    cout << "Not Possible\n";

    return 0;
}