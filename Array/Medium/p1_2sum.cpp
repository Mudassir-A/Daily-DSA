// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce approach: TC: O(n^2)
vector<int> bruteforce(vector<int> &nums, int target)
{
    vector<int> ans;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }

    return ans;
}

// better - TC: O(N)
vector<int> usingHashmap(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

// optimal
vector<int> twoPointer(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size() - 1;

    int left = 0, right = n - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
            return {left, right};
        else if (sum < target)
            left++;
        else
            right--;
    }

    return {-1, -1};
}

vector<int> twoSum(vector<int> &nums, int target)
{
    // return bruteforce(nums, target);
    return usingHashmap(nums, target);
    // return twoPointer(nums, target);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<int> ans = twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}