// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

string decToBin(int num)
{
    string res = "";

    while (num != 0)
    {
        if (num % 2 == 1)
            res += '1';
        else
            res += '0';

        num = num / 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int num;
    cout << "Enter num: ";
    cin >> num;

    cout << num << " in binary is " << decToBin(num);
    return 0;
}