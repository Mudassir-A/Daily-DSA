// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int reverse(int N){
    int rem, rev = 0;
    while (N != 0)
    {
        rem = N % 10;
        rev = (rev * 10) + rem;
        N /= 10;
    }
    
    return rev;
}

int main()
{
    int N;
    cin >> N;

    cout << "Reverse: " << reverse(N);
    return 0;
}