// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bruteforce approach: TC = O(n^2)
int bruteforce(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        bool flag = false;
        for (int j = i; j < nums.size(); j++)
        {
            if (i == nums[j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return i;
    }
    return -1;
}

// better approach
int sortingMethod(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i != nums[i])
            return i;
    }
    return nums.size();
}

// better approach 2:
int hashingMethod(vector<int> &nums)
{
    int hashArr[10000] = {0};

    for (int i = 0; i < nums.size(); i++)
        hashArr[nums[i]]++;

    for (int i = 0; i <= nums.size(); i++)
    {
        if (hashArr[i] == 0)
            return i;
    }

    return nums.size();
}

// optimal approach 1:
int summationMethod(vector<int> &nums)
{
    int arrSum = 0;
    int total = 0;
    for (int i = 0; i < nums.size(); i++)
        arrSum += nums[i];
    for (int i = 0; i <= nums.size(); i++)
        total += i;

    return total - arrSum;
}

// optimal approach: 2
int XORMethod(vector<int> &nums)
{
    int xorArr = 0;
    int xorNums = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        xorArr ^= nums[i];
        xorNums ^= i;
    }

    xorNums ^= nums.size();

    return (xorArr ^ xorNums);
}

int missingNumber(vector<int> &nums)
{
    // return bruteforce(nums);
    // return sortingMethod(nums);
    // return summationMethod(nums);
    // return hashingMethod(nums);
    return XORMethod(nums);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int miss = missingNumber(nums);

    cout << "Missing Number: " << miss;

    return 0;
}