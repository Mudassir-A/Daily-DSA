// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int tar, int si, int ei)
{
    // base case
    if (si > ei)
        return -1;

    int mid = si + (ei - si) / 2;

    // case: FOUND
    if (arr[mid] == tar)
        return mid;

    // min on L1
    if (arr[si] <= arr[mid])
    {
        // case a: left
        if (arr[si] <= tar && tar <= arr[mid])
        {
            return search(arr, tar, si, mid - 1);
        }
        // case b: right
        else
        {
            return search(arr, tar, mid + 1, ei);
        }
    }

    else
    {
        // case a: right
        if (arr[mid] <= tar && tar <= arr[ei])
        {
            return search(arr, tar, mid + 1, ei);
        }
        // case d: left
        else
        {
            return search(arr, tar, si, mid - 1);
        }
    }
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int tar = 6;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << search(arr, tar, 0, size);
    return 0;
}