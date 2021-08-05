//Smallest Sum Contigious Subarray
#include <bits/stdc++.h>
using namespace std;

int sscs(int arr[], int n)
{
    int min_so_far = arr[0];
    int min_here = 0;
    int start = 0, end = 0, s = 0;

    for(int i = 0; i < n; i++)
    {
        min_here += arr[i];
        if (min_here < min_so_far)
        {
            min_so_far = min_here;
            start = s;
            end = i;
        } 
        if (min_here > 0)
        {
            min_here = 0;
            s = i+1;
        }
    }
    cout << start << " " << end << endl;
    return min_so_far;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int max_sum = sscs(arr, n); 
    cout << "Minimum contiguous sum is " << max_sum; 
    return 0; 
}