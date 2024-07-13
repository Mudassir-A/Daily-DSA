// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce approach
int bruteForce(int *arr, int n)
{
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            int currSum = 0;
            for (int i = start; i <= end; i++)
            {
                currSum += arr[i];
            }
            cout << currSum << ", ";
            maxSum = max(maxSum, currSum);
        }
        cout << endl;
    }
    cout << "Max Subarray Sum: " << maxSum;
    return maxSum;
}

// slightly optimized approach
int optimized(int *arr, int n)
{
    int maxSum = INT_MIN;

    for (int start = 0; start < n; start++)
    {
        int currSum = 0;
        for (int end = start; end < n; end++)
        {
            currSum += arr[end];
            // cout << currSum << ", ";
            maxSum = max(maxSum, currSum);
        }
        // cout << endl;
    }
    cout << "Max Subarray Sum: " << maxSum;
    return maxSum;
}

int kadaneAlgo(int *arr, int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
            currSum = 0;
    }
    cout << "Max Subarray Sum: " << maxSum;
    return maxSum;
}

int maxSubarraySum1(int *arr, int n)
{
    // return bruteForce(arr, n);
    // return optimized(arr, n);
    return kadaneAlgo(arr, n);
}

void printSubArrays(int *arr, int n)
{
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            for (int i = start; i <= end; i++)
            {
                cout << arr[i] << " ";
            }
            cout << ", ";
        }
        cout << endl;
    }
}

int main()
{
    // int arr[] = {5, 4, -1, 7, 8};
    // int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // int arr[] = {2, -3, 6, -5, 4, 2};
    int arr[] = {-1, -2, -3, -4, -5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // printSubArrays(arr, n);
    maxSubarraySum1(arr, n);
    return 0;
}