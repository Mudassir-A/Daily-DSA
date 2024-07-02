// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce
int *printDivisors(int n, int &size)
{
    int *divisors = new int[n];
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            divisors[count++] = i;
    }

    size = count;
    return divisors;
}

// optimal
vector<int> findDivisors(int n)
{
    vector<int> divisors;

    int sqrtN = sqrt(n);

    for (int i = 1; i <= sqrtN; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);

            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main()
{
    int number;

    cin >> number;
    // int size;
    // int *divisors = printDivisors(number, size);
    vector<int> divisors = findDivisors(number);

    for (int i = 0; i < divisors.size(); i++)
    {
        cout << divisors[i] << " ";
    }
    cout << endl;

    // delete[] divisors;

    return 0;
}