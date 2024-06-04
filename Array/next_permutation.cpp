// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size();

    // Step 1: Finding the breakpoint:
    int idx = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            // index i is the break point
            idx = i;
            break;
        }
    }

    // if break point does not exist
    if (idx == -1)
    {
        // reverse the whole array
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element and swap it with arr[idx]

    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] > A[idx])
        {
            swap(A[i], A[idx]);
            break;
        }
    }

    // Step 3: Reverse the right half of the arary
    reverse(A.begin() + idx + 1, A.end());
    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "]";
    return 0;
}