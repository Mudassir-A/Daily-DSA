// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC -> O(n^2) SC -> O(n)
vector<int> bruteforce(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int product = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                product *= nums[j];
            }
        }
        ans.push_back(product);
    }

    return ans;
}

vector<int> usingAuxiliaryArrays(vector<int> &nums)
{
    vector<int> prefixProduct(nums.size());
    vector<int> suffixProduct(nums.size());
    vector<int> product(nums.size());

    prefixProduct[0] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        prefixProduct[i] = nums[i - 1] * prefixProduct[i - 1];
    }

    suffixProduct[nums.size() - 1] = 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        suffixProduct[i] = nums[i + 1] * suffixProduct[i + 1];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        product[i] = prefixProduct[i] * suffixProduct[i];
    }

    return product;
}

vector<int> inplace(vector<int> &nums)
{
    int n = nums.size();
    vector<int> product(n);

    product[0] = 1;
    for (int i = 1; i < n; i++)
    {
        product[i] = nums[i - 1] * product[i - 1];
    }

    int suffixProduct = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        product[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }

    return product;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    // return bruteforce(nums);
    // return usingAuxiliaryArrays(nums);
    return inplace(nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = productExceptSelf(nums);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}