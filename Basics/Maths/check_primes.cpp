// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce
bool checkPrime(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;
    }

    return count == 2;
}

int main()
{
    int n;
    cin >> n;
    string res = checkPrime(n) ? "True" : "False";
    cout << res;
    return 0;
}