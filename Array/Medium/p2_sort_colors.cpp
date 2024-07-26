// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

void keepingCounts(vector<int> &nums)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            cnt0++;
        else if (nums[i] == 1)
            cnt1++;
        else
            cnt2++;
    }

    for (int i = 0; i < cnt0; i++)
        nums[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        nums[i] = 1;
    for (int i = cnt0 + cnt1; i < nums.size(); i++)
        nums[i] = 2;
}

void sortColors(vector<int> &nums)
{
    keepingCounts(nums);
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

    sortColors(nums);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    return 0;
}