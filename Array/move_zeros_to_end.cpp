// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using temp array --> TC: O(2N) SC: O(N)
void bruteforce(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            temp.push_back(nums[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i >= temp.size())
            nums[i] = 0;
        else
            nums[i] = temp[i];
    }
}

// using 2 pointers TC: O(2N) SC: O(1)
void optimal(vector<int> &nums)
{
    int n = nums.size();
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    for (int i = j + 1; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

void moveZeroes(vector<int> &nums)
{
    optimal(nums);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    moveZeroes(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}