//Kadane Algorithm
#include <bits/stdc++.h>
using namespace std;

int lscs(int arr[], int n)
{
    int max_so_far = arr[0], max_here = 0;
    int start = 0, end = 0, s = 0;
    
    for(int i = 0; i < n ; i++)
    {
        max_here += arr[i];
        if (max_so_far < max_here)
        {
            max_so_far = max_here;
            start = s;
            end = i;
        }
        if (max_here < 0)
        {
            max_here = 0;
            s = i+1;
        }
    }
    cout << "start: " << start << "  end: " << end << "\n";
    return max_so_far;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]); 
    int max_sum = lscs(arr, n); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
}