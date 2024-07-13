// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 1. Naive Approach
int naive(vector<int> &nums, int k)
{
    int n = nums.size();

    sort(nums.begin(), nums.end(), greater<int>());

    // index of kth Largest element = k-1
    return nums[k - 1];
}

// 2. Using Heap
int heapSearch(vector<int> &nums, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
    }

    int f = k - 1;

    while (f > 0)
    {
        pq.pop();
        f--;
    }

    return pq.top();
}

int findKthLargest(vector<int> &nums, int k)
{
    // return naive(nums, k);
    return heapSearch(nums, k);
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << findKthLargest(nums, k);

    return 0;
}