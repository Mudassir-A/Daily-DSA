// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int chocolateDistribution(vector<int> nums, int M)
{
    int min_diff = INT_MAX;
    sort(nums.begin(), nums.end());
    int i = 0;

    while ((i + M - 1) <= nums.size() - 1)
    {
        if ((nums[i + M - 1] - nums[i]) < min_diff)
            min_diff = nums[i + M - 1] - nums[i];

        i++;
    }

    return min_diff;
}

int main()
{
    vector<int> nums = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int M = 7;
    int min_diff = chocolateDistribution(nums, M);
    cout << min_diff;
    return 0;
}