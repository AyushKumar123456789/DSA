// https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1

/*
Logic:
1. We will partition the array between 0 because 0 will always make the product 0.
2. We will keep track of the maximum product of the subarray from the left side and right side.
*/

#include <bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int> arr, int n)
{
    long long pre = 1, suff = 1;
    long long maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        pre *= arr[i];
        suff *= arr[n - i - 1];

        maxi = max(maxi, max(pre, suff));

        if (pre == 0)
        {
            pre = 1;
        }
        if (suff == 0)
        {
            suff = 1;
        }
    }
    return maxi;
}