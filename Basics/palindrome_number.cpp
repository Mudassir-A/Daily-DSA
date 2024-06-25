// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n)
{
    int rem, rev = 0;
    int temp = n;
    while (temp != 0)
    {
        rem = temp % 10;
        rev = (rev * 10) + rem;
        temp /= 10;
    }

    return (rev == n);
}

int main()
{
    int N;
    cin >> N;
    string pal = palindrome(N) ? "True" : "False";
    cout << "Palindrome: " << pal;

    return 0;
}