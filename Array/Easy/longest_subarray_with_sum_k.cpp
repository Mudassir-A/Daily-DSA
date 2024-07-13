// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int bruteforce(int A[], int N, int K)
{
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            int s = 0;
            for (int k = i; k <= j; k++)
            {
                s += A[k];
            }

            if (s == K)
                len = max(len, j - i + 1);
        }
    }

    return len;
}

// better approach
int twoLoops(int A[], int N, int K)
{
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        int s = 0;
        for (int j = i; j < N; j++)
        {
            s += A[j];

            if (s == K)
                len = max(len, j - i + 1);
        }
    }

    return len;
}

int hashingMethod(int A[], int N, int K)
{
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < N; i++)
    {
        sum += A[i];

        if (sum == K)
            maxLen = max(maxLen, i + 1);

        int rem = sum - K;

        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (preSumMap.find(sum) == preSumMap.end())
            preSumMap[sum] = i;
    }

    return maxLen;
}

// optimal approach
int twoPointer(int A[], int N, int K)
{
    int left = 0, right = 0;
    int sum = A[0];
    int maxLen = 0;

    while (right < N)
    {
        while (left <= right && sum > K)
        {
            sum -= A[left];
            left++;
        }

        if (sum == K)
            maxLen = max(maxLen, right - left + 1);
        right++;

        if (right < N)
            sum += A[right];
    }

    return maxLen;
}

int lenOfLongSubarr(int A[], int N, int K)
{
    // return bruteforce(A, N, K);
    // return twoLoops(A, N, K);
    // return hashingMethod(A, N, K);
    return twoPointer(A, N, K);
}

int main()
{

    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int K;
    cin >> K;

    cout << lenOfLongSubarr(arr, N, K);
    return 0;
    return 0;
}