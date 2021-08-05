//Sum Of Subsets Problem - Backtracking (Not Working)
#include <bits/stdc++.h>
using namespace std;

void printVector(int arr[], int n, vector<bool> visited)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool Utility(int arr[], int m, int n, int sum, int remain,int index, vector<bool> visited)
{
    if (sum > m)                                //Bounding Conditions
    return false;
    if (sum + remain < m)
    return false;
    
    if (sum == m)
    {
        printVector(arr, n, visited);
        return true;
    }

    if (index+1 < n)
    {
        visited[index] = 1;
        
        if(Utility(arr, m, n, sum+arr[index], remain-arr[index], index+1, visited))
        return true;
        else
        {
            visited[index] = 0;
            if (Utility(arr, m, n, sum, remain-arr[index], index+1, visited))
            return true;
        }
    }
    else
    return false;
}

bool sumOfSubset(int arr[], int m, int n)
{
    vector<bool> visited(n, false);
    int left = 0;
    for (int i = 0; i < n; i++)
    left += arr[i];
    if(Utility(arr, m, n, 0, left, 0, visited))
    return true;
    else return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    cin >> arr[i];

    cout << sumOfSubset(arr, m, n);
    return 0;
}