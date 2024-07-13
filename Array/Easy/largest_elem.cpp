#include <bits/stdc++.h>
using namespace std;

// BruteForce Method --> TC: O(n)
int bruteforce(vector<int> &arr, int n)
{
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (ans < arr[i])
            ans = arr[i];
    }

    return ans;
}

// sorting --> TC: O(N log N)
int sorting(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    return arr[n - 1];
}

// max variable --> TC: O(N log N)
int maxVar(vector<int> &arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int largest(vector<int> &arr, int n)
{
    // return bruteforce(arr, n);
    maxVar(arr, n);
}
int main()
{
    // vector<int> nums = {1, 8, 7, 56, 90};
    int n;

    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int elem = largest(nums, n);

    cout << elem << endl;

    return 0;
}