#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>


class LRUCache
{
    public:
    list<int> dq;
    unordered_map<int, list<int>::iterator> mp;
    int size;

    LRUCache(int s)
    {
        size = s;
    }

    void refer(int x)
    {
        if (mp.find(x) == mp.end())
        {
            if (dq.size() == size)
            {
                int last = dq.back();
                dq.pop_back();

                mp.erase(last);
            }
        }
        else
        {
            dq.erase(mp[x]);
        }

        dq.push_front(x);
        mp[x]= dq.begin();
        
    }

    void display()
    {
        for(auto it: dq)
        cout << it << " ";

        cout << endl;
    }

};


int main()
{
    

    return 0;
}