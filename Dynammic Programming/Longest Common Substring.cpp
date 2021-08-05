//Longest Common Substring
#include <bits/stdc++.h>
using namespace std;

/*
int lcSubstring(string a, string b, int i, int j, int count)
{
    if (i == 0 || j == 0)
    return count;
    if (a[i-1] == b[j-1])
    return lcSubstring(a, b, i-1, j-1, count+1);

    return max(count, lcSubstring(a, b, i-1, j, 0), lcSubstring(a, b, i, j-1, 0));
}
*/

int lcsDP(string s1, string s2)
{
    int arr[s1.length()+1][s2.length()+1];
    for(int i = 0; i <= s1.length(); i++)
    for(int j = 0; j <= s2.length(); j++)
    {
        if (i == 0 || j== 0)
        arr[i][j] = 0;
        else if(s1[i-1] == s2[j-1])
        arr[i][j] = 1+arr[i-1][j-1];
        else
        arr[i][j] = 0;
    }
    // FInd max int and check
}

