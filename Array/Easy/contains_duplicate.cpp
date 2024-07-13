// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce approach --> T.C = O(n^2)
bool bruteforce_dup(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

bool set_method(vector<int> &nums)
{
    set<int> newSet;
    for (int i = 0; i < nums.size(); i++)
    {
        if (newSet.find(nums[i]) != newSet.end())
            return true;

        newSet.insert(nums[i]);
    }

    // return (newSet.size() < nums.size());
    return false;
}

bool containsDuplicate(vector<int> &nums)
{
    // return bruteforce_dup(nums);
    return set_method(nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << containsDuplicate(nums);
    return 0;
}