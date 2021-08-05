#include <bits/stdc++.h>
using namespace std;


int main()
{
    string text, pattern;
    cin >> text >> pattern;
    int n = text.length(), m = pattern.length();
    vector<int> pref(m);
    pref[0] = 0;

    for(int i = 1; i < m; i++)
    {
        int j = pref[i-1];

        while(j > 0 && pattern[i] != pattern[j])
        j = pref[j-1];  

        if (pattern[i] == pattern[j])
        j++;
        pref[i] = j;
    }

    vector<int> occurence;

    int prev = 0;
    for(int i = 0; i < n; i++)
    {
        int j = prev;
        
        while(j > 0 && pattern[j] != text[i])
        j = pref[j-1];

        if (text[i] == pattern[j])
        ++j;
        prev = j;
        if (j == m  )
        occurence.push_back(i-m+1);
    }

    for(int i = 0; i < occurence.size(); i++)
    cout << occurence[i] << " ";

    cout << endl;

}