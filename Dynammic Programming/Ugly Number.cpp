#include <iostream>
using namespace std;

int ugly(int n)
{
    int arr[n];
    arr[0] = 1;
    int count;
    int i2 = 1, i3 = 1, i5 = 1;
    int two = 2, three = 3, five = 5;
    int next;
    for(count = 1; count < n; count++)
    {
        next = min(i2*two, min(i3*three, i5*five));
        if (next == i2*two)
    	i2++;
        if(next == i3*three)
        i3++;
        if (next == i5*five)
        i5++;

        arr[count] = next;
    }
    for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    return arr[n-1];
}

int main()
{
    int n;
    cin >> n;
    cout << ugly(n) << endl;
    return 0;
}