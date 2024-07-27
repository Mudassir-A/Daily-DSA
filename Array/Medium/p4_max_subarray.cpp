// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)
int bruteforce(vector<int> &nums)
{
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            cout << sum << endl;
            max(maxi, sum);
        }
    }

    return maxi;
}

// TC: O(n^2)
int betterApproach(vector<int> &nums)
{
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[i];
            cout << sum << endl;
            max(maxi, sum);
        }
    }

    return maxi;
}

// optimal: TC: O(n)
int kadanesAlgo(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum > maxi)
            maxi = sum;

        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int maxSubArray(vector<int> &nums)
{
    // return bruteforce(nums);
    // return betterApproach(nums);
    return kadanesAlgo(nums);
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
    int ans = maxSubArray(nums);

    // for (int i = 0; i < nums.size(); i++)
    // cout << nums[i] << " ";

    cout << ans;

    return 0;
}