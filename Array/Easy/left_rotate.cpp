// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
        return;
    k = k % n;
    if (k > n)
        return;

    int temp[k];
    for (int i = 0; i < k; i++)
        temp[i] = nums[i];

    for (int i = 0; i < n - k; i++)
        nums[i] = nums[i + k];

    for (int i = n - k; i < n; i++)
        nums[i] = temp[i - n + k];
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    rotate(arr, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}