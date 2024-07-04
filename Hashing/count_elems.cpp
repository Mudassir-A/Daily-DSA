// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> countElements(vector<int> arr, vector<int> counts)
{
    // i
    // int hashArr[]
}

int main()
{
    int hashArr[13] = {0};

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        hashArr[arr[i]]++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << number << " - " << hashArr[number] << endl;
    }
    return 0;
}