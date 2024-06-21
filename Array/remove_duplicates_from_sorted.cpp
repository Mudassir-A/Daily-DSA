// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce TC: O(2N) SC: O(N)
int usingHashSet(vector<int> &nums)
{
    int n = nums.size();
    set<int> Set;

    for (int i = 0; i < n; i++)
    {
        Set.insert(nums[i]);
    }

    int k = Set.size();
    int j = 0;

    for (auto x : Set)
    {
        nums[j++];
    }

    return k;
}

// Optimal Soln: TC: O(N) SC: O(1)
int twoPointer(vector<int> &arr)
{
    int i = 0;
    int n = arr.size();
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int removeDuplicates(vector<int> &nums)
{
    // return usingHashSet(nums);
    return twoPointer(nums);
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

    cout << removeDuplicates(arr);
    return 0;
}