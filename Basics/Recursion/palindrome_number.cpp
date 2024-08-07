// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool palindrome(int i, string &s)
{
    if (i >= s.length() / 2)
        return true;

    if (s[i] != s[s.length() - i - 1])
        return false;

    return palindrome(i + 1, s);
}

int main()
{
    string s;
    cin >> s;

    string ans = palindrome(0, s) ? "True" : "False";

    cout << ans;
    return 0;
}