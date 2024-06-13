// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // swap 2 numbers
    int a, b;
    cin >> a;
    cin >> b;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After swapping: \n"
         << a << " " << b << endl;

    return 0;
}