// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();
    int hashArray[26] = {0};

    int m;
    cin >> m;
    char q[m];
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
    }

    for (int i = 0; i < n; i++)
    {
        int index = s[i] - 'a';
        hashArray[index] += 1;
    }

    for (int i = 0; i < m; i++)
    {
        int index = q[i] - 'a';
        cout << q[i] << " - " << hashArray[index] << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     int index = s[i] - 'a';
    //     cout << s[i] << " - " << hashArray[index] << endl;
    // }

    return 0;
}