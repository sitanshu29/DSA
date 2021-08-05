//Friend Pairing Problem
#include <bits/stdc++.h>
using namespace std;
/* //Recursive Approach
int pairs(int n)
{
    if (n == 2)
    return 2;
    if (n == 1)
    return 1;

    return pairs(n-1) + (n-1)*pairs(n-2);
}*/

int pairs(int n)
{
    int arr[n+1];
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        arr[i] = arr[i-1] + (i-1)*arr[i-2];
    }
    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << pairs(n) << endl;
    return 0;
}