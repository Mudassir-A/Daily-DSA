// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Naive Approach TC: O(N^2)
int bruteforce(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == num)
                count++;
        }
        if (count == 1)
            return nums[i];
    }
}

// Better approach
int hashingMethod(vector<int> &nums)
{
    map<int, int> hash;

    for (int i = 0; i < nums.size(); i++)
        hash[nums[i]] += 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (hash[nums[i]] == 1)
            return nums[i];
    }
}

// Optimal Approach TC: O(N)
int XORMethod(vector<int> &nums)
{
    int ans = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        ans ^= nums[i];
    }

    return ans;
}

int singleNumber(vector<int> &nums)
{
    // return XORMethod(nums);
    // return bruteforce(nums);
    return hashingMethod(nums);
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

    cout << singleNumber(arr);
    return 0;
}