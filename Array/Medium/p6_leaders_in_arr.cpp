// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #1. Bruteforce
vector<int> bruteforce(int n, int arr[])
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > i)
            {
                leader = false;
                break;
            }
        }

        if (leader)
            ans.push_back(arr[i]);
    }

    return ans;
}

// #2. Optimal
vector<int> optimal(int n, int arr[])
{
    int max = INT_MIN;
    vector<int> ans;

    for (int i = n-1; i >= 0; i--)
    {
        if(arr[i] > max){
            max = arr[i];
            ans.insert(ans.begin(), max);
        }
    }
    return ans;
}

vector<int> leaders(int n, int arr[])
{
    // return bruteforce(n, arr);
    return optimal(n, arr);
}

int main()
{
    // input size of array
    int n;
    cin >> n;

    // input array
    // vector<int> nums(n);
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cin >> nums[i];
    // }

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // invoke func
    vector<int> ans = leaders(n, arr);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    // cout << ans;

    return 0;
}