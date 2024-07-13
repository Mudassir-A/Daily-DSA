// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_arr(int arr[], int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int min_arr(int arr[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main()
{
    int size;
    cout << "Size of array: ";
    cin >> size;
    int arr[size];
    cout << "Elements of the array: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Max element: " << max_arr(arr, size) << endl;
    cout << "Max element: " << min_arr(arr, size);

    return 0;
}