// Question : Given an integer array nums, return true if any value appears at least
// twice in the array, and return false if every element is distinct.

// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool bruteforce(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

bool setMethod(vector<int> &nums) {
    set<int> numSet;
    for (int i = 0; i < nums.size(); i++)
    {
        numSet.insert(nums[i]);
    }

    return (numSet.size() < nums.size());
    
}

bool containsDuplicate(vector<int> &nums)
{
    // return bruteforce(nums);
    return setMethod(nums);
}

int main()
{
    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << containsDuplicate(nums);
    return 0;
}