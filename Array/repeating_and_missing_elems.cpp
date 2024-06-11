// Repeat and Missing Number Array

// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr)
{
    for (auto it : arr)
    {
        cout << it << ", ";
    }
    cout << endl;
}

// hashing technique --> TC = O(2n), SC = O(n)
vector<int> hashingMethod(vector<int> nums)
{
    // int hashArr[nums.size() + 1] = {0};
    vector<int> hashArr(nums.size() + 1, 0);

    int repeating = -1, missing = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        hashArr[nums[i]]++;
    }

    // printVector(hashArr);

    for (int i = 1; i < hashArr.size(); i++)
    {
        if (hashArr[i] == 2)
            repeating = i;
        if (hashArr[i] == 0)
            missing = i;
    }

    return {repeating, missing};
}

vector<int> optimalMaths(vector<int> nums)
{
    long long n = nums.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += nums[i];
        S2 += (long long)nums[i] * (long long)nums[i];
    }

    // S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    // Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    // Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    //  Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

vector<int> optimalXOR(vector<int> nums)
{
    // TODO: XOR METHOD
}


vector<int> findMissingRepeatingNumbers(vector<int> nums)
{
    // return hashingMethod(nums);
    return optimalMaths(nums);
}

int main()
{
    // vector<int> nums = {3, 1, 2, 5, 3};
    vector<int> nums = {4, 3, 6, 2, 1, 1};
    vector<int> ans = findMissingRepeatingNumbers(nums);

    cout << "Repeated: " << ans[0] << endl;
    cout << "Missing: " << ans[1] << endl;
    return 0;
}