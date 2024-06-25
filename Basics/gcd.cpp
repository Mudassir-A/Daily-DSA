// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bruteforce(int n1, int n2)
{
    int gcd = 1;
    for (int i = 1; i < min(n1, n2); i++)
    {
        if ((n1 % i == 0) && (n2 % i == 0))
            gcd = i;
    }
    return gcd;
}

int better(int n1, int n2)
{

    int gcd = 1;
    for (int i = min(n1, n2); i >= 1; i--)
    {
        if ((n1 % i == 0) && (n2 % i == 0))
            gcd = i;
    }
    return gcd;
}

int optimal(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (a == 0)
        return b;

    return a;
}

int findGCD(int n1, int n2)
{
    // return bruteforce(n1, n2);
    // return better(n1, n2);
    return optimal(n1, n2);
}

int main()
{
    int n1, n2;
    cin >> n1;
    cin >> n2;

    cout << "GCD = " << bruteforce(n1, n2);
    return 0;
}