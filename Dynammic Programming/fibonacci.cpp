#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    arr[i] = arr[i-2] + arr[i-1];
    return arr[n-1];
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);
}