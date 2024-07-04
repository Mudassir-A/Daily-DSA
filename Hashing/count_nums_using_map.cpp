// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m;
    cin >> m;

    int q[m];
    for (int i = 0; i < m; i++)
        cin >> q[i];

    map<int, int> hashArr;

    for (int i = 0; i < n; i++)
        hashArr[arr[i]]++;

    for (int i = 0; i < m; i++)
        cout << q[i] << " - " << hashArr[q[i]] << endl;

    return 0;
}