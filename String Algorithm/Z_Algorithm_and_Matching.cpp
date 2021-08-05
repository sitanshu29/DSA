//Z-function and String Matching
#include <bits/stdc++.h>
using namespace std;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


vector<int> z;
string pattern , text, combine;

vector<int> calculateZ()
{
    int n = combine.length();
    vector<int> occurence;
    for(int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
        z[i] = min(r-i+1, z[i-l]);

        while(i+z[i] < n && combine[z[i]] == combine[i+z[i]])
        ++z[i];
        if (i+z[i]-1 > r)
        {
            l = i; r = i+z[i]-1;
        }
        if (z[i] == pattern.size())
        occurence.push_back(i-pattern.length()-1);
    }
    return occurence;
}


int main()
{
    OJ;
    cin >> pattern >> text;
    combine = pattern + '#'+text;
    z.clear();
    z.resize(combine.length(), 0);
    vector<int> occurence =  calculateZ();

    for(int i = 0; i < occurence.size(); i++)
    cout << occurence[i] << " ";
    cout << endl;

}