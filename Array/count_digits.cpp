// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bruteForce(int N)
{
    int count = 0;
    while (N > 0)
    {
        count++;
        N = N / 10;
    }
    return count;
}

int optimal(int N)
{
    return (int)(log10(N) + 1);
}

int evenlyDivides(int N)
{
    // return bruteForce(N);
    return optimal(N);
}

int main()
{
    int N;
    cin >> N;

    cout << evenlyDivides(N);
    return 0;
}