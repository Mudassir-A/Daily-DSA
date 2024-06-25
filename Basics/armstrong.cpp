// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool armstrong(int num)
{
    int k = to_string(num).length();
    int sum = 0;
    int n = num;
    while (n > 0)
    {
        int rem = n % 10;
        sum += pow(rem, k);
        n = n / 10;
    }
    return sum == num ? true : false;
}

int main()
{
    int n;
    cin >> n;
    string arm = armstrong(n) ? "True" : "False";
    cout << "Armstrong: " << arm;
    return 0;
}