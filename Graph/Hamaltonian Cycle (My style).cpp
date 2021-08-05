#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        cin >> arr[i];
        
        int inc[n], dec[n];
        for(int i = 0; i < n; i++)
        {
        	inc[i] = 1;
        	dec[i] = 1;
		}
        
        for(int i = n-2; i>= 0; i--)
        for(int j = i+1; j < n; j++)
        if (arr[j] < arr[i] && dec[j]+1 > dec[i])
        dec[i] = 1+dec[j];
        
        for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && 1+inc[j] > inc[i])
            inc[i] = 1+inc[j];
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        if (inc[i]+dec[i]-1 > ans)
        ans = inc[i]+dec[i]-1;
        
        for(int i= 0; i < n; i++)
        cout << dec[i] << " ";
        cout << endl;
        
        for(int i= 0; i < n; i++)
        cout << dec[i] << " ";
        cout << endl;
        cout << ans << endl;
        
    }
    return 0;
}
