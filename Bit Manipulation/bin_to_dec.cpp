// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binToDec(string bin)
{
    int num = 0;
    int n = bin.size();
    int pow2 = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (bin[i] == '1')
            num += pow2;
        pow2 *= 2;
    }
    return num;
}

int main()
{
    string num;
    cout << "Enter binary: ";
    cin >> num;

    cout << num << " in decimal is " << binToDec(num);
    return 0;
}