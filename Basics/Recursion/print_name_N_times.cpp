// Print Name N times using Recursion

// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printNos(int N)
{
    if (N >= 1)
    {
        printNos(N - 1);
        cout << N << " ";
    }
}

int main()
{
    int N;
    cin >> N;
    
    printNos(N);
    return 0;
}