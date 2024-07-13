// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Two Pointer Approach
void arr_reverse(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++, end--;
    }
}

// using Recusrsion
void recursive_arr_reverse(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    recursive_arr_reverse(arr, start + 1, end - 1);
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, size);

    // using inbuilt methods
    // reverse(arr, arr + size);

    // arr_reverse(arr, size);
    recursive_arr_reverse(arr, 0, 5);
    printArr(arr, 5);

    return 0;
}