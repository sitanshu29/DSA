//Egg Dropping Problem
#include <bits/stdc++.h>
using namespace std;
/*
int eggDrop(int f, int e)
{
    if (f == 1|| f == 0)
    return f;
    if (e == 1)
    return f;
    int res = INT_MAX, temp;
    for(int i = 1; i <= f; i++)
    {
        temp = max(eggDrop(f-i, e-1), eggDrop(i-1, e));
        if (temp < res)
        res = temp;
    }
    return res+1;
}*/

int eggDrop(int f, int e)
{
    int arr[f+1][e+1];
    for (int i = 0; i < f+1; i++)
    for (int j = 0; j < e+1; j++)
    {
        if (i == 0 || j == 0)
        arr[i][j] = 0;
        else if (i == 1)
        arr[i][j] = 1;
        else if (j == 1)
        arr[i][j] = i;
        else
        {
            int res = INT_MAX, temp;
            for (int k = 1; k < i; k++)
            {
                temp = 1+ max(arr[i-k][j-1], arr[i-1][j]);
                if (temp < res)
                temp = res;
            }
            arr[i][j] = res;
        }
    }
    for(int i = 0; i < f+1; i++)
    {
        for(int j = 0; j < e+1; j++)
        cout << arr[i][j] << " ";
        cout << endl;
    }
    return arr[f][e];
}

int main()
{
    int f, e;
    cin >> f >> e;
    cout << eggDrop(f, e) << endl;
    return 0;
}