// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bruteforce(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < nums.size() - 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                cnt++;
                if (cnt > n / 2)
                    return nums[i];
            }
        }
    }

    return nums[n - 1];
}

int usingHash(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> hash;

    for (int i = 0; i < n; i++)
    {
        hash[nums[i]] += 1;
        if (hash[nums[i]] > (n / 2))
            return nums[i];
    }
}

// optimal approach
int mooresVoting(vector<int> &nums)
{
    int n = nums.size();
    int count = 0, element = NULL;

    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            element = nums[i];
        if (nums[i] == element)
            count++;
        else
            count--;
    }

    return element;
}

int majorityElement(vector<int> &nums)
{
    // return bruteforce(nums);
    // return usingHash(nums);
    return mooresVoting(nums);
}

int main()
{
    // input size of array
    int n;
    cin >> n;

    // input array
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    // invoke func
    int ans = majorityElement(nums);

    // for (int i = 0; i < nums.size(); i++)
    // cout << nums[i] << " ";

    cout << ans;

    return 0;
}