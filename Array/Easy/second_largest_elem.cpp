// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int largest(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

// BRUTEFORCE --> TC: O(N Log N)
int bruteforce(int arr[], int n)
{
    sort(arr, arr + n); // O(N log N)

    int largest = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) // O(N)
    {
        if (arr[i] == largest)
            i++;
        else
            return arr[i];
    }
    return -1;
}

// better soln --> TC: O(2N)
int betterSoln(int arr[], int n)
{
    int max = largest(arr, n); // O(N)
    int smax = INT_MIN;
    for (int i = 0; i < n; i++) // O(N)
    {
        if (arr[i] > smax and arr[i] != max)
            smax = arr[i];
    }
    return smax;
}

// Optimal Soln --> TC: O()
int optimalSoln(int arr[], int n)
{
    int max = arr[0], smax = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];
        }
        else if (arr[i] > smax and arr[i] < max)
        {
            smax = arr[i];
        }
    }

    return smax;
}

int print2largest(int arr[], int n)
{
    // return bruteforce(arr, n);
    // return betterSoln(arr, n);
    return optimalSoln(arr, n);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << print2largest(arr, n);

    return 0;
}