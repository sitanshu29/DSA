//Printing Max Sum Increasing SubSequence
#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)
{
    int dp[n];
    int subseq[n];
    for(int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
        subseq[i] = i;
    }

    for(int i = 1; i < n; i++)
    for(int j = 0; j < i; j++)
    {
        if (arr[i] > arr[j] && dp[j]+arr[i] > dp[i])
        {
            dp[i] = dp[j] + arr[i];
            subseq[i] = j;
        }
    }
    /*
    for(int i = 0; i < n; i++)
    {
    	cout << dp[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < n; i++)
    {
    	cout << subseq[i] << " ";
	}
	cout << endl;
	*/
	    
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if (dp[i] > max)
        max = i;
    }
    int temp = dp[max];
    vector<int> v;
    v.push_back(arr[max]);
    while(subseq[max] != max)
    {
        max = subseq[max];
        v.push_back(arr[max]);
    }

    for(int i = v.size()-1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return temp;
}

  int main() 
{ 
    int arr[] = {1,2,10,3,4,5,11}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // construct and print Max Sum IS of arr 
    cout << maxSumIS(arr, n); 
  
    return 0; 
} 
