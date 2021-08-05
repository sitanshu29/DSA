//Count the number of ways to tile the floor of size n x m using 1 x m size tiles
#include <bits/stdc++.h>
using namespace std;

/* //Recursive Solution

int count(int n, int m)
{
    if (1<= n && n < m)
    return 1;
    if(n == m)
    return 2;
    return count(n-m, m) + count(n-1, m);
}
*/

int countDP(int n, int m)
{
    int arr[n+1];
    for (int i = 1; i <= n; i++)
    {
        if (i < m)
        arr[i] = 1;
        else if (i == m)
        arr[i] = 2;
        else
        arr[i] = arr[i-1] + arr[i-m];
    }
    return arr[n];
}

int main()
{
    int n = 7, m = 4; 
    cout << "Number of ways = "
         << countDP(n, m); 
    return 0; 
}