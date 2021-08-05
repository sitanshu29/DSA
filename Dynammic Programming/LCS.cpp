#include <bits/stdc++.h>
using namespace std;
/*
int LCS(string s1, string s2, int a, int b)
{
    if (a == s1.length() || b == s2.length())
    return 0;

    if (s[a] == s[b])
    return 1+LCS(s1, s2, a+1, b+1);

    return max(LCS(s1, s2, a+1, b), LCS(s1, s2, a, b+1));

}*/

int LCSDP(string s1, string s2)
{
    int dp[s1.length()+1][s2.length()+1];
    for(int i = 0; i < s1.length(); i++)
    for(int j = 0; j < s2.lenght(); j++)
    {
        if (i == 0 || j == 0)
        dp[i][j] = 0;
        else if (s1[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1]+1;
        else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    return dp[s1.length()][s2.length()];
}

int main()  
{  
    string X = "AGGTAB";  
    string Y = "GXTXAYB";
      
    cout << "Length of LCS is " 
         << LCSDP( X, Y);  
      
    return 0;  
}  