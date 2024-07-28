// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC: O(N)
// SC: O(N)
vector<int> usingAuxiliaryArrays(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            neg.push_back(nums[i]);
        else
            pos.push_back(nums[i]);
    }

    vector<int> ans(nums.size());

    for (int i = 0; i < nums.size() / 2; i++)
    {
        ans[2 * i] = pos[i];
        ans[2 * i + 1] = neg[i];
    }

    return ans;
}

vector<int> rearrangeArray(vector<int> &nums)
{
    return usingAuxiliaryArrays(nums);
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
    vector<int> ans = rearrangeArray(nums);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    // cout << ans;

    return 0;
}