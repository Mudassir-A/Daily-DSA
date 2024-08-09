// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &arr, int num)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return true;
    }
    return false;
}

int bruteforce(vector<int> &a)
{
    int n = a.size();
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int cnt = 1;

        while (linearSearch(a, x + 1) == true)
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

// better
int better(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    sort(a.begin(), a.end());

    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - 1 == lastSmaller)
        {
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// optimal
int optimal(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;

            while (st.find(x + 1) != st.end())
            {
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

int longestSuccessiveElements(vector<int> &a)
{
    // return bruteforce(a);
    // return better(a);
    return optimal(a);
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

    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    // invoke func
    int ans = longestSuccessiveElements(nums);

    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    cout << ans;
    return 0;
}